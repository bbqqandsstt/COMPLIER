#pragma once
#include "packages.h"
#include "grammarAnalysis.h"

struct SYNBLNode;
struct TYPELNode;
struct AINFLNode;
struct RINFLNode;
struct PARAMLNode;
struct PFINFLNode;
struct CONSLNode;
struct LENLNode;

extern SYNBLNode SYNBL[20];
extern TYPELNode TYPEL[20];
extern AINFLNode AINFL[20];
extern RINFLNode RINFL[20];
extern PFINFLNode PFINFL[20];
extern PFINFLNode PARAM[20];

extern int count_SYNBL;//�����count_SYNBL+1������
extern int count_TYPEL;//�����count_TYPEL+1������
extern int count_AINFL;//�����count_AINFL+1������
extern int count_PFINFL;//�����count_PFINFL+1������
extern int count_PARAM[5];//�����count_PARAM+1������
extern int count_LEVEL;//��¼������κ�

struct SYNBLNode//�����ܱ�
{
    char NAME[20];//���ݣ����֣�
    TYPELNode* TYPE;//ָ�����ͱ��TYPEָ��
    int CAT;//����
    //addr��ַ
    PFINFLNode* ADDR_1 = NULL;//
    CONSLNode* ADDR_2 = NULL;
    LENLNode* ADDR_3 = NULL;
    //VALLNode* ADDR_4;

};

struct TYPELNode//���ͱ�
{
    int TVAL;//���ʹ��룺i-1(����)��r-2ʵ��)��c-3(�ַ���)��b-4(������)��a-5(������)��d-6(�ṹ��)
    int* TPOINT = NULL;
    AINFLNode* TPOINT_1 = NULL; //ָ��ָ�������
    RINFLNode* TPOINT_2 = NULL;//ָ��ָ��ṹ��
    //TYPELNode* next;//��һ�����
};

struct AINFLNode//�����
{
    char NAME[20];
    int LOW;//�����½�
    int UP;//�����Ͻ�
    int CTP;//�ɷ�   1-int 2-float 3-char 4-string
    int CLEN; //�ɷ����͵ĳ���
};

struct RINFLNode//�ṹ��
{
    string ID;//�ṹ����
    int OFF;//����-ֵ��Ԫ��ַ��������ڼ�¼ֵ����ͷλ�ã�
    string* TP = NULL;//��ɷ�����ָ��
};

struct PARAMLNode//������
{
    char NAME[20];//���ݣ����֣�
    int TYPE;//1-int 2-float 3-char 4-string
    char HSNAME[20];//��Ӧ����������
    int ADDR;//��ַ
    // PARAMLNode* next;//��һ���ڵ�
};

struct PFINFLNode//������
{
    char NAME[20];
    int LEVEL;//�������ڲ�κ�
    int OFF;//����C�ù���������������ʼ��Ԫ��Ըù���ֵ����ͷλ��
    int FN;//��������
    int ENTRY;//�ú���Ŀ������׵�ַ
    PARAMLNode* PARAM;//��ɷ����ͽṹ����
};

void write_param_table();//��д�βα�
void write_prinfl_table();//��д������
void write_ainfl_table();//��д�����
void write_symbol_table();//��д���ű�