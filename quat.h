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
extern int xuhao;//���Լ�¼���ɵڼ�����Ԫʽ
extern int jilu;//���Լ�¼�ڼ����м����������
extern string siyuanshi[];//��ȡ��Ԫʽ�ַ�������
extern string temp1;
extern string temp2;
extern string bo;//��ȡbool�ıȽϷ���Ҫ�嶯��
extern int if1;//����if��Ԫʽ�����ַʱʹ�õ�
extern int if2;
extern int while1;//����while��Ԫʽ�����ַʱʹ�õ�
extern int while2;//����while��Ԫʽ�����ַʱʹ�õ�
extern int while3;
extern int while4;
extern int for1;//����while��Ԫʽ�����ַʱʹ�õ�
extern int for2;//����while��Ԫʽ�����ַʱʹ�õ�
extern int for3;
extern int for4;

extern int xuhao1;
extern string siyuanshi1[100];
extern string SYS[50][4];                  //������Ԫʽ
extern string SYS_new[50][4];              //�Ż�����������Ԫʽ
extern int SYS_new_len;                  //�Ż������������Ԫʽ�ĳ���
extern string youhua_quan[50][10];
extern int youhua_quan_j_len[50];
extern int quan;
extern string youhua_chaozuo[50][4];
extern int chaozuo;
