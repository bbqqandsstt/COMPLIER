#include "symbol.h"

/*  *****************     符号表填写      *****************  */
SYMBLNode SYMBL[400];
TYPELNode TYPEL[400];
ARRAYLNode ARRAY[400];
FUNCLNode FUNCL[400];
FUNCLNode PARAM[400];

int cnt_SYMBL = 0;                  // 代表第cnt_SYNBL+1个表项
int cnt_TYPEL = 0;                  // 代表第cnt_TYPEL+1个表项
int cnt_ARRAY = 0;                  // 代表第cnt_AINFL+1个表项
int cnt_FUNCL = 0;                 // 代表第cnt_PFINFL+1个表项
int cnt_PARAM[5] = {0, 0, 0, 0, 0}; // 代表第cnt_PARAM+1个表项
int cnt_LEVEL = 0;                  // 记录函数层次号

void write_param_table(){ // 填写函数形参表
    //   cout << "填写形参表" << endl;
    auto p=I_Type[x4 - 1];

    FUNCL[cnt_FUNCL - 1].PARAM[cnt_PARAM[cnt_FUNCL - 1]].NAME=x2; // 赋予标识符名称
    // cout << FUNCL[cnt_FUNCL - 1].PARAM->NAME << "是形参" << endl;
    FUNCL[cnt_FUNCL - 1].PARAM[cnt_PARAM[cnt_FUNCL - 1]].TYPE = p.first;                         // 1-int 2-float 3-char 4-string
    FUNCL[cnt_FUNCL - 1].PARAM[cnt_PARAM[cnt_FUNCL - 1]].FUNC=FUNCL[cnt_FUNCL - 1].NAME; // 赋予对应函数的名称
    //  cout << "形参类型是" << FUNCL[cnt_FUNCL - 1].PARAM->CAT << endl;

    cnt_PARAM[cnt_FUNCL - 1]++;
    FUNCL[cnt_FUNCL - 1].FN++;
}

void write_funcl_table(){ // 填写函数表
    //   cout << "函数层次号为:" << cnt_LEVEL << endl;
    FUNCL[cnt_FUNCL].LEVEL = cnt_LEVEL;
    FUNCL[cnt_FUNCL].NAME=x2;
    //  cout << "函数名称为:" << FUNCL[cnt_FUNCL].NAME << endl;
    // cout << "函数形参个数:" << FUNCL[cnt_FUNCL].FN << endl;
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

void write_symbol_table(){ // 填写符号表
    // 填写总表. f(函数)，c(常量)，t(类型)，d(域名)，v, vn, vf(变量，换名形参，赋值形参)
    // I_Type,x4:（int-1,float-2,char-3,string-4,void-5）
    /*填写SYMBL符号表*/
    auto p=I_Type[x4 - 1];

    if (x1=="I"){ // 填写int float char string void函数
        if (0<p.first && p.first <5){ // x4:int-1,float-2,char-3,string-4
            SYMBL[cnt_SYMBL].NAME=x2;     // 赋予标识符名称
            SYMBL[cnt_SYMBL].CAT = p.first; // 填写种类
            if (p.second == 2)
                write_param_table();
        }else if (p.first == 5){ // x4:void-5
            SYMBL[cnt_SYMBL].NAME=x2; // 赋予标识符名称
            write_funcl_table();                // 填写函数表
            SYMBL[cnt_SYMBL].CAT = 5;
            SYMBL[cnt_SYMBL].TYPE = NULL; // void 返回类型
            SYMBL[cnt_SYMBL].ADDR = &FUNCL[cnt_FUNCL - 1];
        }
    }else if (x1=="S"){ // 填写数组
        SYMBL[cnt_SYMBL].NAME=x2; // 赋予标识符名称
        SYMBL[cnt_SYMBL].CAT = 5;          // 填写数组种类，CAT对应数字5
    }

    cnt_SYMBL++;
}

/*  *****************     符号表填写结束      *****************  */