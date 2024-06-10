#pragma once
#include<bits/stdc++.h>
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
extern int I_Type[20];             //��ʶ������Ӧ������
extern int I_Type2[20];            //��ʶ���Ǳ���(=1)�����β�(=2)
extern int II_Type;                 //��ʶ����Ӧ���͵��ֳ���
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
extern int S_Type[20];             //�����б�ʶ������Ӧ������
extern int SS_Type;                 //�����б�ʶ��������Ӧ�ĳ���
extern string Input;            ///������ַ���
extern int error;                   //�ж��﷨�Ƿ����  0Ϊ�޴���
extern vector<pair<int,int>> token;          //Token���б�
extern int token_len;               //Token���б�ĳ��ȣ�������

struct Array{
    string type,index;
    Array(string t,string i):type(t),index(i){}
    bool operator<(const Array& a) const{
        int f=type.compare(a.type),s=index.compare(a.index);
        return f<0;
    }
    friend ostream& operator<<(ostream& out,const Array& a){
        out<<a.type+"["+a.index+"]";
        return out;
    }
};