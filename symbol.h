#pragma once
#include "packages.h"
#include "grammarAnalysis.h"

struct SYMBLNode{//�����ܱ�
    string NAME;//���ݣ����֣�
    TYPELNode* TYPE;//ָ�����ͱ��TYPEָ��
    int CAT;//����
    //addr��ַ
    FUNCLNode* ADDR_1 = NULL;
};
struct TYPELNode{//���ͱ�
    int TVAL;//���ʹ��룺i-1(����)��r-2ʵ��)��c-3(�ַ���)��b-4(������)��a-5(������)��d-6(�ṹ��)
    ARRAYLNode* TPOINT_1 = NULL; //ָ��ָ�������
};
struct ARRAYLNode{//�����
    string NAME;
    int LOW;//�����½�
    int UP;//�����Ͻ�
    int CTP;//����   1-int 2-float 3-char 4-string
    int CLEN; //���Ͷ�Ӧ�ĳ���
};
struct PARAMLNode{//������
    string NAME;//���ݣ����֣�
    int TYPE;//1-int 2-float 3-char 4-string
    string HSNAME;//��Ӧ����������
    int ADDR;//��ַ
};
struct FUNCLNode{//������
    string NAME;
    int LEVEL;//�������ڲ�κ�
    int OFF;//����C�ù���������������ʼ��Ԫ��Ըù���ֵ����ͷλ��
    int FN;//��������
    int ENTRY;//�ú���Ŀ������׵�ַ
    PARAMLNode* PARAM;//��ɷ����ͽṹ����
};

extern SYMBLNode SYMBL[400];
extern TYPELNode TYPEL[400];
extern ARRAYLNode AINFL[400];
extern FUNCLNode PFINFL[400],PARAM[400];

extern int count_SYNBL;//�����count_SYNBL+1������
extern int count_TYPEL;//�����count_TYPEL+1������
extern int count_AINFL;//�����count_AINFL+1������
extern int count_PFINFL;//�����count_PFINFL+1������
extern int count_PARAM[5];//�����count_PARAM+1������
extern int count_LEVEL;//��¼������κ�

void write_param_table();//��д�βα�
void write_prinfl_table();//��д������
void write_ainfl_table();//��д�����
void write_symbol_table();//��д���ű�