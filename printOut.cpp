#include "printOut.h"

void print_all_form()     //输出各种表
{
    int i;
    cout << "标识符表：";
    for (i = 0; i < II; i++)
        cout << I[i] << "  ";
    cout << endl;
    cout << "标识符表类型(int-1,float-2,char-3,string-4,void-5)：";
    for (i = 0; i < II_Type; i++)
        cout << I_Type[i] << "  ";
    cout << endl;
    cout << "变量还是形参：";
    for (i = 0; i < II_Type; i++)
        cout << I_Type2[i] << "  ";
    cout << endl;
    cout << "整数表：";
    for (i = 0; i < CC1; i++)
        cout << C1[i] << "  ";
    cout << endl;
    cout << "实数表：";
    for (i = 0; i < CC2; i++)
        cout << C2[i] << "  ";
    cout << endl;
    cout << "字符表：";
    for (i = 0; i < CTT; i++)
        cout << CT[i] << "  ";
    cout << endl;
    cout << "字符串表：";
    for (i = 0; i < STT; i++)
        cout << ST[i] << "  ";
    cout << endl;
    cout << "数组表：";
    for (i = 0; i < SS; i++)
        cout << S[i][0] << "  ";
    cout << endl;
    cout << "数组长度表：";
    for (i = 0; i < SS; i++)
        cout << S[i][1] << "  ";
    cout << endl;
    cout << "数组类型表：";
    for (i = 0; i < SS_Type; i++)
        cout << S_Type[i] << "  ";
}

void make_table()
{
    int i, k, m;
    cout << "             ******************SYMBL****************" << endl;
    cout << "                ┌───────────────────────────────┐" << endl;
    cout << "                │---NAME---│---TYPE---│---XOB---│" << endl;
    cout << "                │----------│----------│---------│" << endl;
    for (Next_w = 0; Next_w < token_len; Next_w++)//扫描token序列填表
    {
        count_data();
        int flag = 1;//填表
        for (i = 0; i < Next_w; i++)//检查要填写的标识符或数组是否与先前填写的表重复
        {
            if (!strcmp(SYNBL[i].NAME, x2))
            {
                flag = 0;//有重复，不填表
                break;
            }
        }
        if (flag)
        {
            if (!strcmp(x1, "I"))//储存标识符和函数
            {
                for (i = 0; x2[i] != '\0';)
                    i++;
                cout << "                │   ";
                cout << x2;
                for (; i < 7; i++)
                    cout << " ";
                cout << "│   ";
                if (I_Type[x4 - 1] == 1)
                    cout << "int    ";
                else if (I_Type[x4 - 1] == 2)
                    cout << "float  ";
                else if (I_Type[x4 - 1] == 3)
                    cout << "char   ";
                else if (I_Type[x4 - 1] == 4)
                    cout << "string ";
                else if (I_Type[x4 - 1] == 5)
                    cout << "void   ";
                cout << "│";
                if (I_Type2[x4 - 1] == 1)
                    cout << "argument ";
                else if (I_Type2[x4 - 1] == 2)
                    cout << "parameter";
                else if (I_Type2[x4 - 1] == 0)
                    cout << "function ";
                cout << "│" << endl;
                cout << "                │----------│----------│---------│" << endl;
                write_symbol_table();
            }

            else if (!strcmp(x1, "S"))//储存数组
            {
                for (i = 0; x2[i] != '\0';)
                    i++;
                cout << "                │   ";
                cout << x2;
                for (; i < 7; i++)
                    cout << " ";
                cout << "│   ";
                if (S_Type[x4 - 1] == 1)
                    cout << "int    ";
                else if (S_Type[x4 - 1] == 2)
                    cout << "float  ";
                else if (S_Type[x4 - 1] == 3)
                    cout << "char   ";
                else if (S_Type[x4 - 1] == 4)
                    cout << "string ";
                cout << "│ array   ";
                cout << "│" << endl;
                cout << "                │----------│----------│---------│" << endl;
                write_ainfl_table();
                write_symbol_table();
            }
        }
    }
    cout << "                └───────────────────────────────┘" << endl << endl;

    cout << "            ******************PFINFL*******************" << endl;
    cout << "            ┌─────────────────────────────────────────┐" << endl;
    cout << "            │-NAME-│-LEVEL-│-OFF-│-FN-│-ENTRY-│-PARAM-│" << endl;
    cout << "            │------│-------│-----│----│-------│-------│" << endl;
    for (k = 0; k < count_PFINFL; k++)
    {
        for (i = 0; PFINFL[k].NAME[i] != '\0';)
            i++;
        cout << "            │";
        cout << PFINFL[k].NAME;
        for (; i < 6; i++)
            cout << " ";
        cout << "│   " << PFINFL[k].LEVEL << "   ";

        cout << "│  " << PFINFL[k].OFF << "  ";
        cout << "│ " << PFINFL[k].FN << "  ";
        cout << "│ entry │       │" << endl;
        cout << "            │------│-------│-----│----│-------│-------│" << endl;
    }
    cout << "            └─────────────────────────────────────────┘" << endl << endl;

    cout << "             ******************PARAM****************" << endl;
    cout << "                ┌───────────────────────────────┐" << endl;
    cout << "                │---NAME---│---TYPE---│---HSN---│" << endl;
    cout << "                │----------│----------│---------│" << endl;
    for (m = 0; m < count_PFINFL; m++)
        for (k = 0; k < count_PARAM[m]; k++)
        {
            for (i = 0; PFINFL[m].PARAM[k].NAME[i] != '\0';)
                i++;
            cout << "                │   ";
            cout << PFINFL[m].PARAM[k].NAME;
            for (; i < 7; i++)
                cout << " ";
            cout << "│   ";
            if (PFINFL[m].PARAM[k].TYPE == 1)
                cout << "int    ";
            else if (PFINFL[m].PARAM[k].TYPE == 2)
                cout << "float  ";
            else if (PFINFL[m].PARAM[k].TYPE == 3)
                cout << "char   ";
            else if (PFINFL[m].PARAM[k].TYPE == 4)
                cout << "string ";
            cout << "│  ";
            for (i = 0; PFINFL[m].PARAM[k].HSNAME[i] != '\0';)
                i++;
            cout << PFINFL[m].PARAM[k].HSNAME;
            for (; i < 7; i++)
                cout << " ";
            cout << "│" << endl;
            cout << "                │----------│----------│---------│" << endl;
        }
    cout << "                └───────────────────────────────┘" << endl << endl;

    cout << "              *****************AINFL***************" << endl;
    cout << "              ┌───────────────────────────────────┐" << endl;
    cout << "              │--NAME--│-LOW-│-UP-│--TYPE--│-CLEN-│" << endl;
    cout << "              │--------│-----│----│--------│------│" << endl;
    for (k = 0; k < count_AINFL; k++)
    {
        for (i = 0; AINFL[k].NAME[i] != '\0';)
            i++;
        cout << "              │ ";
        cout << AINFL[k].NAME;
        for (; i < 7; i++)
            cout << " ";
        cout << "│  1  │ ";
        cout << AINFL[k].UP;
        cout << "  │";
        if (AINFL[k].CTP == 1)
            cout << "  int   │  4   │" << endl;
        else if (AINFL[k].CTP == 2)
            cout << " float  │  8   │" << endl;
        else if (AINFL[k].CTP == 3)
            cout << "  char  │  1   │" << endl;
        else if (AINFL[k].CTP == 4)
            cout << " string │  8   │" << endl;
        cout << "              │--------│-----│----│--------│------│" << endl;
    }
    cout << "              └───────────────────────────────────┘" << endl << endl;
}


void outputsiyuanshi()//输出所有四元式函数
{
    cout << "四元式序列为：" << endl;
    int i = 0;
    while (siyuanshi[i] != "")
    {
        cout << siyuanshi[i] << endl;
        i++;
    }
    cout << endl;
}