cmake_minimum_required(VERSION 3.10)
project(PascalComplier C)

set(CMAKE_C_STANDARD 11)

add_executable(PascalComplier
        absyn.c absyn.h
        util.h util.c
        table.h table.c
        symbol.c symbol.h
        types.c types.h
        env.c env.h
        semant.c semant.h
        translate.c translate.h
        tree.h tree.c
        temp.h temp.c
        frame.c frame.h
        lex.yy.c
        pascal.tab.c pascal.tab.h
        printtree.c printtree.h
        errormsg.c errormsg.h
        prabsyn.c prabsyn.h
        printgraph.h printgraph.c
        main.c)