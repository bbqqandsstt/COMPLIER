#pragma once
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
extern const int max_len;         //�����ַ�������󳤶�
extern char K[15][8];        //�ؼ��ֱ�
extern char P[30][3];        //�����
extern char P1[22][2];        //���������
extern char T[4][10];                 //ͷ�ļ���
extern char I[20][20];                //��ʶ����
extern int I_Type[20];             //��ʶ������Ӧ������****************************************************
extern int I_Type2[20];            //��ʶ���Ǳ���(=1)�����β�(=2)****************************************************
extern int II;                      //��ʶ������ֳ���
extern int II_Type;                 //��ʶ����Ӧ���͵��ֳ���
extern char C1[20][10];                 //��������
extern int CC1;                     //����������ֳ���
extern char C2[20][10];                 //��ʵ����
extern int CC2;                     //��ʵ������ֳ���
extern char CT[20][10];               //�ַ�����
extern int CTT;                     //�ַ�������ĳ���
extern char ST[20][10];               //�ַ�������
extern int STT;                     //�ַ���������ĳ���
extern char S[20][2][10];             //�����
extern int S_Type[20];             //�����б�ʶ������Ӧ������
extern int SS;                      //�����ĳ���
extern int SS_Type;                 //�����б�ʶ��������Ӧ�ĳ���
extern char Input[];            ///������ַ���
extern int len;                       //������ַ�������
extern int error;                   //�ж��﷨�Ƿ����  0Ϊ�޴���     1Ϊ�д���
extern int token[200][2];          //Token���б�
extern int token_len;               //Token���б�ĳ��ȣ�������
extern char formType[10][3];     //K=1��P=2��I=3......
