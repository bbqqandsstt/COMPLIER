#pragma once
#include<bits/stdc++.h>
using namespace std;

extern map<string,int> K;        //关键字表
extern map<string,int> P;        //界符表
extern map<string,int> H;                 //头文件表
extern vector<string> Ik;
extern map<string,int> I;                //标识符表
extern int I_Type[20];             //标识符所对应的类型
extern int I_Type2[20];            //标识符是变量(=1)还是形参(=2)
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
struct Array;
extern vector<Array> Sk;
extern map<Array,int> S;             //数组表
extern int S_Type[20];             //数组中标识符所对应的类型
extern int SS;                      //数组表的长度
extern int SS_Type;                 //数组中标识符的类别对应的长度
extern string Input;            ///输入的字符串
extern int len;                       //输入的字符串长度
extern int error;                   //判断语法是否错误  0为无错误
extern int token[200][2];          //Token序列表
extern int token_len;               //Token序列表的长度（行数）
extern char formType[10][3];     //K=1，P=2，I=3......

struct Array{
    string type,index;
    Array(string t,string i):type(t),index(i){}
    bool operator<(const Array& a) const{
        int f=type.compare(a.type),s=index.compare(a.index);
        return f<0;
    }
};