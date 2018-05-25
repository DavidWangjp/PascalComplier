cmake_minimum_required(VERSION 3.10)
project(PascalComplier C)

set(CMAKE_C_STANDARD 11)

add_executable(PascalComplier
        absyn.c absyn.h
        util.h util.c
        pascal.l pascal.y
        table.h table.c
        symbol.c symbol.h
        types.c types.h
        env.c env.h semant.c
        semant.h translate.c
        translate.h translate.c
        tree.h tree.c
        temp.h temp.c
        frame.c frame.h)