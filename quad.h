#pragma once
#include "packages.h"

void quadPlus();
void quadMinus();
void quadMultiply();
void quadDivide();
void quadAssign();

void quadBool();
void quadIf();
void quadElse();
void quadIfEnd();
void quadWhile();
void quadDoWhile();
void quadWhileEnd();
void quadFor();
void quadDoFor();
void quadForEnd();

extern stack<string> s;
extern int cnt;          // 用以记录生成第几个四元式
extern int tag;           // 用以记录第几个中间变量的生成
extern string quadruple[]; // 存取四元式字符串数组
extern string temp1, temp2;
extern string bo;                          // 存取bool的比较符，要插动作
extern int if1, if2;                       // 用于if四元式回填地址时使用的
extern int while1, while2, while3, while4; // 用于while四元式回填地址时使用的
extern int for1, for2, for3, for4;         // 用于for四元式回填地址时使用的

extern int cnt1;
extern string quadruple1[100];
