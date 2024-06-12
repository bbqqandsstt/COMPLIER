#include "symbol.h"

/*  *****************     符号表填写      *****************  */
SYMBLNode SYMBL[20];
TYPELNode TYPEL[20];
AINFLNode AINFL[20];
PFINFLNode PFINFL[20];
PFINFLNode PARAM[20];

int count_SYNBL = 0;                  // 代表第count_SYNBL+1个表项
int count_TYPEL = 0;                  // 代表第count_TYPEL+1个表项
int count_AINFL = 0;                  // 代表第count_AINFL+1个表项
int count_PFINFL = 0;                 // 代表第count_PFINFL+1个表项
int count_PARAM[5] = {0, 0, 0, 0, 0}; // 代表第count_PARAM+1个表项
int count_LEVEL = 3;                  // 记录函数层次号

void write_param_table(){ // 填写函数形参表
    //   cout << "填写形参表" << endl;
    auto p=I_Type[x4 - 1];

    PFINFL[count_PFINFL - 1].PARAM[count_PARAM[count_PFINFL - 1]].NAME=x2; // 赋予标识符名称
    // cout << PFINFL[count_PFINFL - 1].PARAM->NAME << "是形参" << endl;
    PFINFL[count_PFINFL - 1].PARAM[count_PARAM[count_PFINFL - 1]].TYPE = p.first;                         // 1-int 2-float 3-char 4-string
    PFINFL[count_PFINFL - 1].PARAM[count_PARAM[count_PFINFL - 1]].HSNAME=PFINFL[count_PFINFL - 1].NAME; // 赋予对应函数的名称
    //  cout << "形参类型是" << PFINFL[count_PFINFL - 1].PARAM->CAT << endl;

    count_PARAM[count_PFINFL - 1]++;
    PFINFL[count_PFINFL - 1].FN++;
}

void write_prinfl_table(){ // 填写函数表
    //   cout << "函数层次号为:" << count_LEVEL << endl;
    PFINFL[count_PFINFL].LEVEL = count_LEVEL;
    PFINFL[count_PFINFL].NAME=x2;
    //  cout << "函数名称为:" << PFINFL[count_PFINFL].NAME << endl;
    PFINFL[count_PFINFL].OFF = 3; // 记录函数区距
    // cout << "函数形参个数:" << PFINFL[count_PFINFL].FN << endl;
    PFINFL[count_PFINFL++].PARAM = new PARAMLNode[20];
    count_LEVEL++;
}

void write_ainfl_table(){
    AINFL[count_AINFL].NAME=Sk[count_AINFL].name;
    AINFL[count_AINFL].LOW = 1;
    AINFL[count_AINFL].UP = stoi(Sk[count_AINFL].len);
    AINFL[count_AINFL].CTP = S_Type[count_AINFL]; // 1-int 2-float 3-char 4-string
    AINFL[count_AINFL++].CLEN = S_Type.size();
}

void write_symbol_table(){ // 填写符号表
    // 填写总表. f(函数)，c(常量)，t(类型)，d(域名)，v, vn, vf(变量，换名形参，赋值形参)
    // I_Type,x4:（int-1,float-2,char-3,string-4,void-5）
    /*填写SYNBL符号表*/
    auto p=I_Type[x4 - 1];

    if (x1=="I"){ // 填写int float char string void函数
        if (0<p.first && p.first <5){ // x4:int-1,float-2,char-3,string-4
            SYMBL[count_SYNBL].NAME=x2;     // 赋予标识符名称
            SYMBL[count_SYNBL].CAT = p.first; // 填写种类

            if (p.second == 2)
                write_param_table();
        }else if (p.first == 5){ // x4:void-5
            SYMBL[count_SYNBL].NAME=x2; // 赋予标识符名称
            write_prinfl_table();                // 填写函数表
            SYMBL[count_SYNBL].CAT = 5;
            SYMBL[count_SYNBL].TYPE = NULL; // void 返回类型
            SYMBL[count_SYNBL].ADDR_1 = &PFINFL[count_PFINFL - 1];
        }
    }else if (x1=="S"){ // 填写数组
        SYMBL[count_SYNBL].NAME=x2; // 赋予标识符名称
        SYMBL[count_SYNBL].CAT = 5;          // 填写数组种类，CAT对应数字5
    }

    count_SYNBL++;
}

/*  *****************     符号表填写结束      *****************  */