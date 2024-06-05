#pragma once
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
extern const int max_len;         //输入字符串的最大长度
extern char K[15][8];        //关键字表
extern char P[30][3];        //界符表
extern char P1[22][2];        //辅助界符表
extern char T[4][10];                 //头文件表
extern char I[20][20];                //标识符表
extern int I_Type[20];             //标识符所对应的类型****************************************************
extern int I_Type2[20];            //标识符是变量(=1)还是形参(=2)****************************************************
extern int II;                      //标识符表的现长度
extern int II_Type;                 //标识符对应类型的现长度
extern char C1[20][10];                 //常整数表
extern int CC1;                     //常整数表的现长度
extern char C2[20][10];                 //常实数表
extern int CC2;                     //常实数表的现长度
extern char CT[20][10];               //字符常量
extern int CTT;                     //字符常量表的长度
extern char ST[20][10];               //字符串常量
extern int STT;                     //字符串常量表的长度
extern char S[20][2][10];             //数组表
extern int S_Type[20];             //数组中标识符所对应的类型
extern int SS;                      //数组表的长度
extern int SS_Type;                 //数组中标识符的类别对应的长度
extern char Input[];            ///输入的字符串
extern int len;                       //输入的字符串长度
extern int error;                   //判断语法是否错误  0为无错误     1为有错误
extern int token[200][2];          //Token序列表
extern int token_len;               //Token序列表的长度（行数）
extern char formType[10][3];     //K=1，P=2，I=3......
