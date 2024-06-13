#include "symbol.h"

/*  *****************     ���ű���д      *****************  */
SYMBLNode SYMBL[400];
TYPELNode TYPEL[400];
ARRAYLNode ARRAY[400];
FUNCLNode FUNCL[400];
FUNCLNode PARAM[400];

int cnt_SYMBL = 0;                  // �����cnt_SYNBL+1������
int cnt_TYPEL = 0;                  // �����cnt_TYPEL+1������
int cnt_ARRAY = 0;                  // �����cnt_AINFL+1������
int cnt_FUNCL = 0;                 // �����cnt_PFINFL+1������
int cnt_PARAM[5] = {0, 0, 0, 0, 0}; // �����cnt_PARAM+1������
int cnt_LEVEL = 0;                  // ��¼������κ�

void write_param_table(){ // ��д�����βα�
    //   cout << "��д�βα�" << endl;
    auto p=I_Type[x4 - 1];

    FUNCL[cnt_FUNCL - 1].PARAM[cnt_PARAM[cnt_FUNCL - 1]].NAME=x2; // �����ʶ������
    // cout << FUNCL[cnt_FUNCL - 1].PARAM->NAME << "���β�" << endl;
    FUNCL[cnt_FUNCL - 1].PARAM[cnt_PARAM[cnt_FUNCL - 1]].TYPE = p.first;                         // 1-int 2-float 3-char 4-string
    FUNCL[cnt_FUNCL - 1].PARAM[cnt_PARAM[cnt_FUNCL - 1]].FUNC=FUNCL[cnt_FUNCL - 1].NAME; // �����Ӧ����������
    //  cout << "�β�������" << FUNCL[cnt_FUNCL - 1].PARAM->CAT << endl;

    cnt_PARAM[cnt_FUNCL - 1]++;
    FUNCL[cnt_FUNCL - 1].FN++;
}

void write_funcl_table(){ // ��д������
    //   cout << "������κ�Ϊ:" << cnt_LEVEL << endl;
    FUNCL[cnt_FUNCL].LEVEL = cnt_LEVEL;
    FUNCL[cnt_FUNCL].NAME=x2;
    //  cout << "��������Ϊ:" << FUNCL[cnt_FUNCL].NAME << endl;
    // cout << "�����βθ���:" << FUNCL[cnt_FUNCL].FN << endl;
    FUNCL[cnt_FUNCL++].PARAM = new PARAMLNode[20];
    cnt_LEVEL++;
}

void write_arrayl_table(){
    ARRAY[cnt_ARRAY].NAME=Sk[cnt_ARRAY].name;
    ARRAY[cnt_ARRAY].LOW = 1;
    ARRAY[cnt_ARRAY].UP = stoi(Sk[cnt_ARRAY].len);
    ARRAY[cnt_ARRAY].CTP = S_Type[cnt_ARRAY]; // 1-int 2-float 3-char 4-string
    ARRAY[cnt_ARRAY++].CLEN = S_Type.size();
}

void write_symbol_table(){ // ��д���ű�
    // ��д�ܱ�. f(����)��c(����)��t(����)��d(����)��v, vn, vf(�����������βΣ���ֵ�β�)
    // I_Type,x4:��int-1,float-2,char-3,string-4,void-5��
    /*��дSYMBL���ű�*/
    auto p=I_Type[x4 - 1];

    if (x1=="I"){ // ��дint float char string void����
        if (0<p.first && p.first <5){ // x4:int-1,float-2,char-3,string-4
            SYMBL[cnt_SYMBL].NAME=x2;     // �����ʶ������
            SYMBL[cnt_SYMBL].CAT = p.first; // ��д����
            if (p.second == 2)
                write_param_table();
        }else if (p.first == 5){ // x4:void-5
            SYMBL[cnt_SYMBL].NAME=x2; // �����ʶ������
            write_funcl_table();                // ��д������
            SYMBL[cnt_SYMBL].CAT = 5;
            SYMBL[cnt_SYMBL].TYPE = NULL; // void ��������
            SYMBL[cnt_SYMBL].ADDR = &FUNCL[cnt_FUNCL - 1];
        }
    }else if (x1=="S"){ // ��д����
        SYMBL[cnt_SYMBL].NAME=x2; // �����ʶ������
        SYMBL[cnt_SYMBL].CAT = 5;          // ��д�������࣬CAT��Ӧ����5
    }

    cnt_SYMBL++;
}

/*  *****************     ���ű���д����      *****************  */