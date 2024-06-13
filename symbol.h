#pragma once
#include "packages.h"
#include "grammarAnalysis.h"

struct PARAMLNode{//参数表
    string NAME;//内容（名字）
    int TYPE;//1-int 2-float 3-char 4-string
    string HSNAME;//对应函数的名字
    int ADDR;//地址
};
struct FUNCLNode{//函数表
    string NAME;
    int LEVEL;//函数所在层次号
    int OFF;//区距–该过函自身数据区起始单元相对该过函值区区头位置
    int FN;//参数个数
    int ENTRY;//该函数目标程序首地址
    PARAMLNode* PARAM;//域成分类型结构数组
};
struct ARRAYLNode{//数组表
    string NAME;
    int LOW;//数组下界
    int UP;//数组上界
    int CTP;//类型   1-int 2-float 3-char 4-string
    int CLEN; //类型对应的长度
};
struct TYPELNode{//类型表
    int TVAL;//类型代码：i-1(整型)，r-2实型)，c-3(字符型)，b-4(布尔型)，a-5(数组型)，d-6(结构型)
    ARRAYLNode* TPOINT = NULL; //指针指向数组表
};
struct SYMBLNode{//符号总表
    string NAME;//内容（名字）
    TYPELNode* TYPE;//指向类型表的TYPE指针
    int CAT;//种类
    //addr地址
    FUNCLNode* ADDR = NULL;
};

extern SYMBLNode SYMBL[400];
extern TYPELNode TYPEL[400];
extern ARRAYLNode ARRAY[400];
extern FUNCLNode FUNCL[400],PARAM[400];

extern int cnt_SYMBL;//代表第count_SYNBL+1个表项
extern int cnt_TYPEL;//代表第count_TYPEL+1个表项
extern int cnt_ARRAY;//代表第count_AINFL+1个表项
extern int cnt_FUNCL;//代表第count_PFINFL+1个表项
extern int cnt_PARAM[5];//代表第count_PARAM+1个表项
extern int cnt_LEVEL;//记录函数层次号

void write_param_table();//填写形参表
void write_funcl_table();//填写函数表
void write_arrayl_table();//填写数组表
void write_symbol_table();//填写符号表