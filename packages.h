#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<stack>
#include<map>
using namespace std;

struct Array;

extern string formType[10];     //K=1��P=2��I=3......
extern vector<string> Kk;
extern map<string,int> K;        //�ؼ��ֱ�
extern vector<string> Pk;
extern map<string,int> P;        //�����
extern vector<string> Hk;
extern map<string,int> H;                 //ͷ�ļ���
extern vector<string> Ik;
extern map<string,int> I;                //��ʶ����
extern vector<pair<int,int>> I_Type;             //��ʶ������Ӧ������,��ʶ���Ǳ���(=1)�����β�(=2)
extern vector<string> C1k;
extern map<string,int> C1;                 //��������
extern vector<string> C2k;
extern map<string,int> C2;                 //��ʵ����
extern vector<string> CTk;
extern map<string,int> CT;               //�ַ�����
extern vector<string> STk;
extern map<string,int> ST;               //�ַ�������
extern vector<Array> Sk;
extern map<Array,int> S;             //�����
extern vector<int> S_Type;             //�����б�ʶ������Ӧ������
extern string Input;            ///������ַ���
extern int error;                   //�ж��﷨�Ƿ����  0Ϊ�޴���
extern vector<pair<int,int>> token;          //Token���б�

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