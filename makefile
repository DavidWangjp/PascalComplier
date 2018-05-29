a.out: main.o \
	   printtree.o \
       pascal.tab.o lex.yy.o  \
	   errormsg.o util.o \
	   table.o absyn.o symbol.o semant.o types.o env.o 
	cc -g main.o \
		  printtree.o \
		  pascal.tab.o lex.yy.o errormsg.o util.o \
		  table.o absyn.o symbol.o semant.o types.o env.o \
		  translate.o frame.o temp.o tree.o \
		  canon.o codegen.o assem.o; \
    ctags -R *

printtree.o: printtree.c
	cc -g -c printtree.c

tree.o: tree.c tree.h
	cc -g -c tree.c

temp.o: temp.c temp.h
	cc -g -c temp.c

translate.o: translate.c translate.h
	cc -g -c translate.c

frame.o: frame.c frame.h
	cc -g -c -o frame.o frame.c

types.o: types.c types.h
	cc -g -c types.c
	
env.o: env.c env.h
	cc -g -c env.c

semant.o: semant.c semant.h
	cc -g -c semant.c

main.o: main.c errormsg.h util.h
	cc -g -c main.c

pascal.tab.o: pascal.tab.c
	cc -g -c pascal.tab.c

pascal.tab.c: pascal.y
	yacc -dv pascal.y

pascal.tab.h: pascal.tab.c
	echo "pascal.tab.h was created at the same time as pascal.tab.c"

symbol.o: symbol.c symbol.h
	cc -g -c symbol.c

absyn.o: absyn.c absyn.h
	cc -g -c absyn.c

table.o: table.c table.h
	cc -g -c table.c

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c symbol.h absyn.h pascal.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

lex.yy.c: pascal.l
	lex pascal.l

util.o: util.c util.h
	cc -g -c util.c

clean: 
	rm -f a.out util.o maintest.o lex.yy.o errormsg.o pascal.tab.c pascal.tab.h pascal.tab.o main.o printtree.o
