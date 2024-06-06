#pragma once
#include "packages.h"

int is_I(string a);             //是否为I(标识符)中的值,如果不是，则存入
int is_C1(string a);            //是否为C1(常整数)中的值,如果不是，则存入
int is_C2(string a, int q);      //是否为C2(常实数)中的值,如果不是，则存入
int is_CT(string a);            //是否为CT(字符常量)中的值,如果不是，则存入
int is_S(string a);            //是否为S(数组表)中的值,如果不是，则存入
int is_ST(string a);            //是否为ST(字符串常量)中的值,如果不是，则存入
