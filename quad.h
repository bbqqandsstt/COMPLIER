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
extern int xuhao;          // ���Լ�¼���ɵڼ�����Ԫʽ
extern int jilu;           // ���Լ�¼�ڼ����м����������
extern string quadruple[]; // ��ȡ��Ԫʽ�ַ�������
extern string temp1, temp2;
extern string bo;                          // ��ȡbool�ıȽϷ���Ҫ�嶯��
extern int if1, if2;                       // ����if��Ԫʽ�����ַʱʹ�õ�
extern int while1, while2, while3, while4; // ����while��Ԫʽ�����ַʱʹ�õ�
extern int for1, for2, for3, for4;         // ����for��Ԫʽ�����ַʱʹ�õ�

extern int xuhao1;
extern string quadruple1[100];
extern string SYS[50][4];     // ������Ԫʽ
