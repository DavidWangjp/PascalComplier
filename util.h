#ifndef _UTIL_H_
#define _UTIL_H_

#include <assert.h>

typedef char *string;
typedef char bool;

#define TRUE 1
#define FALSE 0
#define MAXINT 2147483647

#define INT_SIZE 4
#define CHAR_SIZE 1
#define BOOL_SIZE 1
#define REAL_SIZE 8

//int EM_tokPos = 0;
//int line_no = 1;

void *checked_malloc(int);

string String(char *);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_
{
    bool head;
    U_boolList tail;
};

typedef struct U_byteList_ *U_byteList;
struct U_byteList_
{
    int byte;
    U_byteList tail;
};

U_boolList U_BoolList(bool head, U_boolList tail);

U_byteList U_ByteList(int byte, U_byteList tail);

U_byteList U_constByteList(int byte);



#endif // util.h

