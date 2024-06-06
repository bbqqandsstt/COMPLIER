#include "symbol.h"

/*  *****************     ���ű���д      *****************  */
SYNBLNode SYNBL[20];
TYPELNode TYPEL[20];
AINFLNode AINFL[20];
RINFLNode RINFL[20];
PFINFLNode PFINFL[20];
PFINFLNode PARAM[20];

int count_SYNBL = 0;                  // �����count_SYNBL+1������
int count_TYPEL = 0;                  // �����count_TYPEL+1������
int count_AINFL = 0;                  // �����count_AINFL+1������
int count_PFINFL = 0;                 // �����count_PFINFL+1������
int count_PARAM[5] = {0, 0, 0, 0, 0}; // �����count_PARAM+1������
int count_LEVEL = 3;                  // ��¼������κ�

void write_param_table() // ��д�����βα�
{
    //   cout << "��д�βα�" << endl;

    strcpy(PFINFL[count_PFINFL - 1].PARAM[count_PARAM[count_PFINFL - 1]].NAME, x2); // �����ʶ������
    // cout << PFINFL[count_PFINFL - 1].PARAM->NAME << "���β�" << endl;
    PFINFL[count_PFINFL - 1].PARAM[count_PARAM[count_PFINFL - 1]].TYPE = I_Type[x4 - 1];                         // 1-int 2-float 3-char 4-string
    strcpy(PFINFL[count_PFINFL - 1].PARAM[count_PARAM[count_PFINFL - 1]].HSNAME, PFINFL[count_PFINFL - 1].NAME); // �����Ӧ����������
    //  cout << "�β�������" << PFINFL[count_PFINFL - 1].PARAM->CAT << endl;

    count_PARAM[count_PFINFL - 1]++;
    PFINFL[count_PFINFL - 1].FN++;
}

void write_prinfl_table() // ��д������
{
    //   cout << "������κ�Ϊ:" << count_LEVEL << endl;
    PFINFL[count_PFINFL].LEVEL = count_LEVEL;
    strcpy(PFINFL[count_PFINFL].NAME, x2);
    //  cout << "��������Ϊ:" << PFINFL[count_PFINFL].NAME << endl;
    PFINFL[count_PFINFL].OFF = 3; // ��¼��������
    // cout << "�����βθ���:" << PFINFL[count_PFINFL].FN << endl;
    PFINFL[count_PFINFL].PARAM = new PARAMLNode[20];
    count_LEVEL++;
    count_PFINFL++;
}

void write_ainfl_table()
{
    strcpy(AINFL[count_AINFL].NAME, S[count_AINFL][0]);
    AINFL[count_AINFL].LOW = 1;
    AINFL[count_AINFL].UP = S[count_AINFL][1][0] - '0';
    AINFL[count_AINFL].CTP = S_Type[count_AINFL]; // 1-int 2-float 3-char 4-string
    AINFL[count_AINFL].CLEN = SS_Type;

    count_AINFL++;
}

void write_symbol_table() // ��д���ű�
{
    // ��д�ܱ�. f(����)��c(����)��t(����)��d(����)��v, vn, vf(�����������βΣ���ֵ�β�)
    // I_Type,x4:��int-1,float-2,char-3,string-4,void-5��
    /*��дSYNBL���ű�*/
    if (!strcmp(x1, "I")) // ��дint float char string void����
    {
        if (I_Type[x4 - 1] >= 1 && I_Type[x4 - 1] <= 4) // x4:int-1,float-2,char-3,string-4
        {
            strcpy(SYNBL[count_SYNBL].NAME, x2);     // �����ʶ������
            SYNBL[count_SYNBL].CAT = I_Type[x4 - 1]; // ��д����

            if (I_Type2[x4 - 1] == 2)
            {
                write_param_table();
            }
        }
        else if (I_Type[x4 - 1] == 5) // x4:void-5
        {
            strcpy(SYNBL[count_SYNBL].NAME, x2); // �����ʶ������
            write_prinfl_table();                // ��д������
            SYNBL[count_SYNBL].CAT = 5;
            SYNBL[count_SYNBL].TYPE = NULL; // void ��������
            SYNBL[count_SYNBL].ADDR_1 = &PFINFL[count_PFINFL - 1];
            SYNBL[count_SYNBL].ADDR_2 = NULL;
            SYNBL[count_SYNBL].ADDR_3 = NULL;
        }
    }
    else if (!strcmp(x1, "S")) // ��д����
    {
        strcpy(SYNBL[count_SYNBL].NAME, x2); // �����ʶ������
        SYNBL[count_SYNBL].CAT = 5;          // ��д�������࣬CAT��Ӧ����5
    }

    count_SYNBL++;
}

/*  *****************     ���ű���д����      *****************  */