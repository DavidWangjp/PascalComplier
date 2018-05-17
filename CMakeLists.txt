cmake_minimum_required(VERSION 3.10)
project(PascalComplier C)

set(CMAKE_C_STANDARD 11)

add_executable(PascalComplier absyn.c absyn.h util.h util.c pascal.l pascal.y table.h)