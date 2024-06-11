#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<stack>
#include<map>
using namespace std;

struct Array;

extern string formType[10];     //K=1，P=2，I=3......
extern vector<string> Kk;
extern map<string,int> K;        //关键字表
extern vector<string> Pk;
extern map<string,int> P;        //界符表
extern vector<string> Hk;
extern map<string,int> H;                 //头文件表
extern vector<string> Ik;
extern map<string,int> I;                //标识符表
extern vector<pair<int,int>> I_Type;             //标识符所对应的类型,标识符是变量(=1)还是形参(=2)
extern vector<string> C1k;
extern map<string,int> C1;                 //常整数表
extern vector<string> C2k;
extern map<string,int> C2;                 //常实数表
extern vector<string> CTk;
extern map<string,int> CT;               //字符常量
extern vector<string> STk;
extern map<string,int> ST;               //字符串常量
extern vector<Array> Sk;
extern map<Array,int> S;             //数组表
extern vector<int> S_Type;             //数组中标识符所对应的类型
extern string Input;            ///输入的字符串
extern int error;                   //判断语法是否错误  0为无错误
extern vector<pair<int,int>> token;          //Token序列表

struct Array{
    string name,len;
    Array(string n,string l):name(n),len(l){}
    bool operator<(const Array& a) const{
        return name<a.name;
    }
    friend ostream& operator<<(ostream& out,const Array& a){
        out<<a.name+"["+a.len+"]";
        return out;
    }
};