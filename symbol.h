#pragma once
#include "packages.h"
#include "grammarAnalysis.h"

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
struct ARRAYLNode{//�����
    string NAME;
    int LOW;//�����½�
    int UP;//�����Ͻ�
    int CTP;//����   1-int 2-float 3-char 4-string
    int CLEN; //���Ͷ�Ӧ�ĳ���
};
struct TYPELNode{//���ͱ�
    int TVAL;//���ʹ��룺i-1(����)��r-2ʵ��)��c-3(�ַ���)��b-4(������)��a-5(������)��d-6(�ṹ��)
    ARRAYLNode* TPOINT = NULL; //ָ��ָ�������
};
struct SYMBLNode{//�����ܱ�
    string NAME;//���ݣ����֣�
    TYPELNode* TYPE;//ָ�����ͱ��TYPEָ��
    int CAT;//����
    //addr��ַ
    FUNCLNode* ADDR = NULL;
};

extern SYMBLNode SYMBL[400];
extern TYPELNode TYPEL[400];
extern ARRAYLNode ARRAY[400];
extern FUNCLNode FUNCL[400],PARAM[400];

extern int cnt_SYMBL;//�����count_SYNBL+1������
extern int cnt_TYPEL;//�����count_TYPEL+1������
extern int cnt_ARRAY;//�����count_AINFL+1������
extern int cnt_FUNCL;//�����count_PFINFL+1������
extern int cnt_PARAM[5];//�����count_PARAM+1������
extern int cnt_LEVEL;//��¼������κ�

void write_param_table();//��д�βα�
void write_funcl_table();//��д������
void write_arrayl_table();//��д�����
void write_symbol_table();//��д���ű�