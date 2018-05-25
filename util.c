/*
 * util.c - commonly used utility functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void *checked_malloc(int len)
{
    void *p = malloc((size_t) len);
    if (!p)
    {
        fprintf(stderr, "\nRan out of memory!\n");
        exit(1);
    }
    return p;
}

string String(char *s)
{
    string p = checked_malloc((int) (strlen(s) + 1));
    strcpy(p, s);
    return p;
}

U_boolList U_BoolList(bool head, U_boolList tail)
{
    U_boolList list = checked_malloc(sizeof(*list));
    list->head = head;
    list->tail = tail;
    return list;
}

U_byteList U_ByteList(int byte, U_byteList tail)
{
    U_byteList list = checked_malloc(sizeof(*list));
    list->byte = byte;
    list->tail = tail;
    return list;
}

U_byteList U_constByteList(int byte)
{
    U_byteList list = checked_malloc(sizeof(*list));
    list->byte = byte;
    list->tail = list;
    return list;
}