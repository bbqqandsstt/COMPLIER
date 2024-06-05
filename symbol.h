#pragma once
#include "packages.h"
#include "grammarAnalysis.h"

struct SYNBLNode;
struct TYPELNode;
struct AINFLNode;
struct RINFLNode;
struct PARAMLNode;
struct PFINFLNode;
struct CONSLNode;
struct LENLNode;

extern SYNBLNode SYNBL[20];
extern TYPELNode TYPEL[20];
extern AINFLNode AINFL[20];
extern RINFLNode RINFL[20];
extern PFINFLNode PFINFL[20];
extern PFINFLNode PARAM[20];

extern int count_SYNBL;//代表第count_SYNBL+1个表项
extern int count_TYPEL;//代表第count_TYPEL+1个表项
extern int count_AINFL;//代表第count_AINFL+1个表项
extern int count_PFINFL;//代表第count_PFINFL+1个表项
extern int count_PARAM[5];//代表第count_PARAM+1个表项
extern int count_LEVEL;//记录函数层次号

struct SYNBLNode//符号总表
{
    char NAME[20];//内容（名字）
    TYPELNode* TYPE;//指向类型表的TYPE指针
    int CAT;//种类
    //addr地址
    PFINFLNode* ADDR_1 = NULL;//
    CONSLNode* ADDR_2 = NULL;
    LENLNode* ADDR_3 = NULL;
    //VALLNode* ADDR_4;

};

struct TYPELNode//类型表
{
    int TVAL;//类型代码：i-1(整型)，r-2实型)，c-3(字符型)，b-4(布尔型)，a-5(数组型)，d-6(结构型)
    int* TPOINT = NULL;
    AINFLNode* TPOINT_1 = NULL; //指针指向数组表
    RINFLNode* TPOINT_2 = NULL;//指针指向结构表
    //TYPELNode* next;//下一个结点
};

struct AINFLNode//数组表
{
    char NAME[20];
    int LOW;//数组下界
    int UP;//数组上界
    int CTP;//成分   1-int 2-float 3-char 4-string
    int CLEN; //成分类型的长度
};

struct RINFLNode//结构表
{
    string ID;//结构域名
    int OFF;//区距-值单元首址相对于所在记录值区区头位置；
    string* TP = NULL;//域成分类型指针
};

struct PARAMLNode//参数表
{
    char NAME[20];//内容（名字）
    int TYPE;//1-int 2-float 3-char 4-string
    char HSNAME[20];//对应函数的名字
    int ADDR;//地址
    // PARAMLNode* next;//下一个节点
};

struct PFINFLNode//函数表
{
    char NAME[20];
    int LEVEL;//函数所在层次号
    int OFF;//区距–该过函自身数据区起始单元相对该过函值区区头位置
    int FN;//参数个数
    int ENTRY;//该函数目标程序首地址
    PARAMLNode* PARAM;//域成分类型结构数组
};

void write_param_table();//填写形参表
void write_prinfl_table();//填写函数表
void write_ainfl_table();//填写数组表
void write_symbol_table();//填写符号表