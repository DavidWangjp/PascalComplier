#include "translate.h"

static Tr_level outermost_l = NULL;
static F_fragList fragList = NULL;

Tr_exp Tr_Ex(T_exp ex)
{
    Tr_exp tr_exp = checked_malloc(sizeof(*tr_exp));
    tr_exp->kind = Tr_ex;
    tr_exp->u.ex = ex;
    return tr_exp;
}

Tr_exp Tr_Nx(T_stm nx)
{
    Tr_exp tr_exp = checked_malloc(sizeof(*tr_exp));
    tr_exp->kind = Tr_nx;
    tr_exp->u.nx = nx;
    return tr_exp;
}

Tr_exp Tr_Cx(patchList trues, patchList falses, T_stm stm)
{
    Tr_exp tr_exp = checked_malloc(sizeof(*tr_exp));
    tr_exp->kind = Tr_cx;
    tr_exp->u.cx.trues = trues;
    tr_exp->u.cx.falses = falses;
    tr_exp->u.cx.stm = stm;
    return tr_exp;
}

static Tr_exp getStaticLink(Tr_level dec_l, Tr_level call_l)
{
    T_exp subtree = T_Temp(F_FP());
    while (dec_l != call_l)
    {
        F_access tmp = call_l->frame->paras->head;
        subtree = F_Exp(tmp, subtree);
        call_l = call_l->parent;
    }
    return Tr_Ex(subtree);
}

static patchList PatchList(Temp_label *head, patchList tail)
{
    patchList patchlist = checked_malloc(sizeof(*patchlist));
    patchlist->head = head;
    patchlist->tail = tail;
    return patchlist;
}

void doPatch(patchList tList, Temp_label label)
{
    for (; tList; tList = tList->tail)
    {
        *(tList->head) = label;
    }
}

patchList joinPatch(patchList first, patchList second)
{
    if (!first)
        return second;
    for (; first->tail; first = first->tail);
    first->tail = second;
    return first;
}

static T_exp unEx(Tr_exp e)
{
    switch (e->kind)
    {
        case Tr_ex:
            return e->u.ex;
        case Tr_cx:
        {
            Temp_temp r = Temp_newtemp();
            Temp_label t = Temp_newlabel(), f = Temp_newlabel();
            doPatch(e->u.cx.trues, t);
            doPatch(e->u.cx.falses, f);
            return T_Eseq(T_Move(T_Temp(r), T_Const(1)),
                          T_Eseq(e->u.cx.stm,
                                 T_Eseq(T_Label(f),
                                        T_Eseq(T_Move(T_Temp(r), T_Const(0)),
                                               T_Eseq(T_Label(t), T_Temp(r))))));
        }
        case Tr_nx:
            return T_Eseq(e->u.nx, T_Const(0));
    }
    assert(0);
}

static T_stm unNx(Tr_exp e)
{
    switch (e->kind)
    {
        case Tr_nx:
            return e->u.nx;
        case Tr_cx:
        {
            Temp_temp r = Temp_newtemp();
            Temp_label t = Temp_newlabel(), f = Temp_newlabel();
            doPatch(e->u.cx.trues, t);
            doPatch(e->u.cx.falses, f);
            return T_Exp(T_Eseq(T_Move(T_Temp(r), T_Const(1)),
                                T_Eseq(e->u.cx.stm,
                                       T_Eseq(T_Label(f),
                                              T_Eseq(T_Move(T_Temp(r), T_Const(0)),
                                                     T_Eseq(T_Label(t), T_Temp(r)))))));
        }
        case Tr_ex:
            return T_Exp(e->u.ex);
    }
    assert(0);
}

static struct Cx unCx(Tr_exp e)
{
    switch (e->kind)
    {
        case Tr_cx:
            return e->u.cx;
        case Tr_ex:
        {
            struct Cx condCx;
            condCx.trues = NULL;
            condCx.falses = NULL;
            condCx.stm = T_Cjump(T_gt, e->u.ex, T_Const(0), NULL, NULL);
            condCx.trues = PatchList(&(condCx.stm)->u.CJUMP.true_label, NULL);
            condCx.falses = PatchList(&(condCx.stm)->u.CJUMP.false_label, NULL);
            return condCx;
        }
        case Tr_nx:
            assert(0);
    }
    assert(0);
}

Tr_exp Tr_SimpleVar(Tr_access access, Tr_level level)
{
    T_exp subtree = T_Temp(F_FP());
    //不一样
    while (access->level != level && level->parent)
    {
        //获取静态链
        F_access tmpAcc = level->frame->paras->head;
        //更新偏移信息
        subtree = F_Exp(tmpAcc, subtree);
        level = level->parent;
    }
    return Tr_Ex(F_Exp(access->access, subtree));
}

Tr_exp Tr_SubscriptVar(Tr_exp base, Tr_exp e, int size)
{
    return Tr_Ex(T_Mem(T_Binop(T_plus, unEx(base)->u.MEM.exp, T_Binop(T_mul, unEx(e), T_Const(size))), size));
}

Tr_exp Tr_RecordVar(Tr_exp base, int offset, int size)
{
    return Tr_Ex(T_Mem(T_Binop(T_plus, unEx(base)->u.MEM.exp, T_Const(offset)), size));
}

Tr_exp Tr_PlusArithExp(A_plus_op op, Tr_exp left, Tr_exp right)
{
    T_binOp operator;
    switch (op)
    {
        case OP_PLUS:
            operator = T_plus;
            break;
        case OP_MINUS:
            operator = T_minus;
            break;
        case OP_OR:
            operator = T_or;
            break;
        default:
            assert(0);
            break;
    }
    return Tr_Ex(T_Binop(operator, unEx(left), unEx(right)));
}

Tr_exp Tr_MulArithExp(A_mul_op op, Tr_exp left, Tr_exp right)
{
    T_binOp operator;
    switch (op)
    {
        case OP_MUL:
            operator = T_mul;
            break;
        case OP_DIV:
            operator = T_div;
            break;
        case OP_AND:
            operator = T_and;
            break;
        case OP_MOD:
            operator = T_mod;
            break;
        default:
            assert(0);
            break;
    }
    return Tr_Ex(T_Binop(operator, unEx(left), unEx(right)));
}

Tr_exp Tr_IntExp(int i)
{
    return Tr_Ex(T_Const(i));
}

Tr_exp Tr_BoolExp(bool i)
{
    if (i == TRUE)
        return Tr_Ex(T_Const(1));
    else
        return Tr_Ex(T_Const(0));
}

Tr_exp Tr_RealExp(double i)
{
    return Tr_Ex(T_Double(i));
}

Tr_exp Tr_CharExp(char i)
{
    return Tr_Ex(T_Char(i));
}

Tr_exp Tr_ArrayExp(Tr_exp n, Tr_expList es, int size)
{
    Temp_temp r = Temp_newtemp();
    T_stm alloc = T_Move(T_Temp(r), F_externalCall(String("malloc"),
                                                   T_ExpList(T_Binop(T_plus, unEx(n), T_Const(F_wordSize)), NULL)));
    T_stm root = NULL;
    Tr_expList tmp_exp = es;
    int offset = 0;
    root = T_Move(T_Mem(T_Binop(T_plus, T_Temp(r), T_Const(0)), size), unEx(tmp_exp->head));
    for (tmp_exp = tmp_exp->tail; tmp_exp; tmp_exp = tmp_exp->tail)
    {
        offset = offset + size;
        root = T_Seq(T_Move(T_Mem(T_Binop(T_plus, T_Temp(r), T_Const(0)), size), unEx(tmp_exp->head)), root);
    }
    return Tr_Ex(T_Eseq(T_Seq(alloc, root), T_Temp(r)));
}

Tr_exp Tr_RecordExp(int n, Tr_expList es, U_byteList bytes)
{
    Temp_temp r = Temp_newtemp();
    T_stm alloc = T_Move(T_Temp(r), F_externalCall(String("malloc"), T_ExpList(T_Const(n * F_wordSize), NULL)));
    T_stm root = NULL;
    U_byteList tmp_byte = bytes;
    Tr_expList tmp_exp = es;
    int offset = 0;
    root = T_Move(T_Mem(T_Binop(T_plus, T_Temp(r), T_Const(0)), tmp_byte->byte), unEx(tmp_exp->head));
    for (tmp_exp = tmp_exp->tail; tmp_exp; tmp_exp = tmp_exp->tail)
    {
        offset = offset + tmp_byte->byte;
        tmp_byte = tmp_byte->tail;
        root = T_Seq(T_Move(T_Mem(T_Binop(T_plus, T_Temp(r), T_Const(0)), tmp_byte->byte), unEx(tmp_exp->head)), root);
    }
    return Tr_Ex(T_Eseq(T_Seq(alloc, root), T_Temp(r)));
}

//不一样
Tr_exp Tr_IfExp(Tr_exp e1, Tr_exp e2, Tr_exp e3)
{
    Tr_exp exp = NULL;
    T_stm tmp1 = NULL;
    T_stm tmp2 = NULL;
    struct Cx cond = unCx(e1);
    Temp_label x = Temp_newlabel();
    Temp_label y = Temp_newlabel();
    Temp_label z = Temp_newlabel();
    doPatch(cond.trues, x);
    doPatch(cond.falses, y);
    if (e3)
    {
        switch (e2->kind)
        {
            case Tr_ex:
                tmp1 = T_Seq(T_Label(x), T_Seq(unNx(e2), T_Jump(T_Name(z), Temp_LabelList(z, NULL))));
                break;
            case Tr_nx:
                tmp1 = T_Seq(T_Label(x), T_Seq(unNx(e2), T_Jump(T_Name(z), Temp_LabelList(z, NULL))));
                break;
            case Tr_cx:
            {
                struct Cx cond2 = unCx(e2);
                Temp_label x2 = Temp_newlabel();
                doPatch(cond2.trues, x2);
                doPatch(cond2.falses, y);
                tmp1 = T_Seq(T_Label(x), T_Seq(cond2.stm, T_Jump(T_Name(z), Temp_LabelList(z, NULL))));
                break;
            }
        }

        switch (e3->kind)
        {
            case Tr_ex:
                tmp2 = T_Seq(T_Label(y), unNx(e3));
                break;
            case Tr_nx:
                tmp2 = T_Seq(T_Label(y), unNx(e3));
                break;
            case Tr_cx:
            {
                struct Cx cond2 = unCx(e2);
                Temp_label x2 = Temp_newlabel();
                doPatch(cond2.trues, x2);
                doPatch(cond2.falses, y);
                tmp2 = T_Seq(T_Label(y), cond2.stm);
                break;
            }
        }

        exp = Tr_Nx(T_Seq(T_Seq(cond.stm, T_Seq(tmp1, tmp2)), T_Label(z)));
    }
    else
    {
        switch (e2->kind)
        {
            case Tr_ex:
                exp = Tr_Nx(T_Seq(T_Seq(cond.stm, T_Seq(T_Label(x), unNx(e2))), T_Label(y)));
                break;
            case Tr_nx:
                exp = Tr_Nx(T_Seq(T_Seq(cond.stm, T_Seq(T_Label(x), unNx(e2))), T_Label(y)));
                break;
            case Tr_cx:
            {
                struct Cx cond2 = unCx(e2);
                Temp_label x2 = Temp_newlabel();
                doPatch(cond2.trues, x2);
                doPatch(cond2.falses, y);
                exp = Tr_Nx(T_Seq(T_Seq(cond.stm, T_Seq(T_Label(x), cond2.stm)), T_Label(y)));
                break;
            }
        }
    }
    return exp;
}

Tr_exp Tr_WhileExp(Tr_exp cond, Tr_exp body, Tr_exp done)
{
    Temp_label cond_l = Temp_newlabel();
    Temp_label body_l = Temp_newlabel();
    return Tr_Nx(T_Seq(T_Seq(T_Label(cond_l), T_Cjump(T_eq, unEx(cond), T_Const(1), body_l, unEx(done)->u.NAME)),
                       T_Seq(unNx(body), T_Jump(T_Name(cond_l), Temp_LabelList(cond_l, NULL)))));
}

Tr_exp Tr_CallExp(Temp_label label, Tr_level def_l, Tr_level call_l, Tr_expList paras)
{
    T_expList tmp = NULL;
    Tr_expList exp_l = checked_malloc(sizeof(*exp_l));
    exp_l->head = getStaticLink(def_l, call_l);
    exp_l->tail = paras;
    T_expList head = NULL;
    T_expList tail = NULL;
    while (exp_l)
    {
        if (head)
        {
            tail->tail = T_ExpList(unEx(exp_l->head), NULL);
            tail = tail->tail;
        }
        else
        {
            head = T_ExpList(unEx(exp_l->head), NULL);
            tail = head;
        }
        exp_l = exp_l->tail;
    }
    return Tr_Ex(T_Call(T_Name(label), head));
}

Tr_exp Tr_AssignExp(Tr_exp left, Tr_exp right)
{
    return Tr_Nx(T_Move(unEx(left), unEx(right)));
}

Tr_exp Tr_GotoExp(Tr_exp done)
{
    return Tr_Nx(T_Jump(T_Name(unEx(done)->u.NAME), Temp_LabelList(unEx(done)->u.NAME, NULL)));
}

Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail)
{
    Tr_accessList list = checked_malloc(sizeof(*list));
    list->head = head;
    list->tail = tail;
    return list;
}

Tr_level Tr_outermost(void)
{
    if (outermost_l == NULL)
    {
        outermost_l = Tr_NewLevel(NULL, Temp_newlabel(), NULL, NULL);
    }
    return outermost_l;
}

Tr_level Tr_NewLevel(Tr_level parent, Temp_label name, U_boolList formals, U_byteList bytes)
{
    Tr_level new_l = checked_malloc(sizeof(*new_l));
    new_l->parent = parent;
    new_l->frame = F_newFrame(name, U_BoolList(TRUE, formals), U_ByteList(4, bytes));
    return new_l;
}

Tr_accessList Tr_formals(Tr_level level)
{
    F_access_List get_al = F_formals(level->frame);
    Tr_accessList new_al = NULL;
    Tr_accessList tmp_al = NULL;
    while (get_al)
    {
        Tr_accessList tmp = checked_malloc(sizeof(*tmp));
        Tr_access new_a = checked_malloc(sizeof(*new_a));
        new_a->access = get_al->head;
        new_a->level = level;
        tmp->head = new_a;
        tmp->tail = NULL;
        if (new_al == NULL)
        {
            new_al = tmp;
        }
        else
        {
            tmp_al->tail = tmp;
        }
        tmp_al = tmp;
        get_al = get_al->tail;
    }
    return new_al;
}

Tr_access Tr_AllocLocal(Tr_level level, bool escape, int size)
{
    Tr_access new_a = checked_malloc(sizeof(*new_a));
    new_a->level = level;
    new_a->access = F_allocLocal(level->frame, escape, size);
    return new_a;
}

Tr_exp Tr_RelExp(A_rel_op oper, Tr_exp left, Tr_exp right)
{
    T_relOp op;
    switch (oper)
    {
        case OP_EQUAL:
            op = T_eq;
            break;
        case OP_UNEQUAL:
            op = T_ne;
            break;
        case OP_LT:
            op = T_lt;
            break;
        case OP_LE:
            op = T_le;
            break;
        case OP_GT:
            op = T_gt;
            break;
        case OP_GE:
            op = T_ge;
            break;
    }
    T_stm cond = T_Cjump(op, unEx(left), unEx(right), NULL, NULL);
    patchList trues = PatchList(&cond->u.CJUMP.true_label, NULL);
    patchList falses = PatchList(&cond->u.CJUMP.false_label, NULL);
    return Tr_Cx(trues, falses, cond);
}

Tr_expList Tr_ExpList(Tr_exp head, Tr_expList tail)
{
    Tr_expList exp_l = checked_malloc(sizeof(*exp_l));
    exp_l->head = head;
    exp_l->tail = tail;
    return exp_l;
}

Tr_exp Tr_SeqExp(Tr_exp left, Tr_exp right)
{
    if (right == NULL)
        return Tr_Nx(T_Seq(unNx(left), NULL));
    return Tr_Nx(T_Seq(unNx(left), unNx(right)));
}

Tr_exp Tr_LabelExp(Temp_label label)
{
    return Tr_Ex(T_Name(label));
}

Tr_exp Tr_NullExp(void)
{
    return Tr_Ex(T_Const(0));
}

Tr_exp Tr_MinusExp(Tr_exp e)
{
    return Tr_Ex(T_Binop(T_minus, T_Const(0), unEx(e)));
}

Tr_exp Tr_Return(void)
{
    return Tr_Nx(T_Return());
}

Tr_access Tr_ReturnValue(int size)
{
    Tr_access new_a = checked_malloc(sizeof(*new_a));
    new_a->level = Tr_outermost();
    new_a->access = F_RV(Tr_outermost()->frame);
    new_a->access->size = size;
    return new_a;
}

void Tr_procEntryExit(Tr_level level, Tr_exp body)
{
    F_frag newFrag = F_ProcFrag(unNx(body), level->frame);
    fragList = F_FragList(newFrag, fragList);
}

F_fragList Tr_getResult(void)
{
    return fragList;
}
