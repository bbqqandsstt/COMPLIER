#pragma once
#include "packages.h"

void QUATJIA();
void QUATJIAN();
void QUATCHENGE();
void QUATCHU();
void QUATFUZHI();

void QUATBOOL();
void QUATIF();
void QUATELSE();
void QUATIFEND();
void QUATWHILE();
void QUATDO();
void QUATWHILEEND();
void QUATFOR();
void QUATDOFOR();
void QUATFOREND();

extern stack<string> s;
extern int xuhao;//用以记录生成第几个四元式
extern int jilu;//用以记录第几个中间变量的生成
extern string siyuanshi[];//存取四元式字符串数组
extern string temp1;
extern string temp2;
extern string bo;//存取bool的比较符，要插动作
extern int if1;//用于if四元式回填地址时使用的
extern int if2;
extern int while1;//用于while四元式回填地址时使用的
extern int while2;//用于while四元式回填地址时使用的
extern int while3;
extern int while4;
extern int for1;//用于while四元式回填地址时使用的
extern int for2;//用于while四元式回填地址时使用的
extern int for3;
extern int for4;

extern int xuhao1;
extern string siyuanshi1[100];
extern string SYS[50][4];                  //数组四元式
extern string SYS_new[50][4];              //优化过的数组四元式
extern int SYS_new_len;                  //优化过后的数组四元式的长度
extern string youhua_quan[50][10];
extern int youhua_quan_j_len[50];
extern int quan;
extern string youhua_chaozuo[50][4];
extern int chaozuo;
