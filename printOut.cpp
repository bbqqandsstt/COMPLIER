#include "printOut.h"

void print_all_forms(){ // 输出各种表
    cout << "标识符表：";
    for (auto i:Ik)
        cout <<i+"  ";
    cout << "\n标识符表类型(int-1,float-2,char-3,string-4,void-5)：";
    for (auto i:I_Type)
        cout << i.first << "  ";
    cout <<"\n变量还是形参：";
    for (auto i:I_Type)
        cout << i.second << "  ";
    cout << "\n整数表：";
    for (auto i:C1k)
        cout << i << "  ";
    cout << "\n实数表：";
    for (auto i:C2k)
        cout << i << "  ";
    cout << "\n字符表：";
    for (auto i:CTk)
        cout << i+ "  ";
    cout << "\n字符串表：";
    for (auto i:STk)
        cout << i+ "  ";
    cout << "\n数组表：";
    for (auto i:Sk)
        cout << i.name << "  ";
    cout << "\n数组长度表：";
    for (auto i:Sk)
        cout << i.len << "  ";
    cout << "\n数组类型表：";
    for (auto i:S_Type)
        cout << i << "  ";
}

void make_table(){
    int t;
    string d1[]={"","int    ","float  ","char   ","string ","void   "};
    cout << "             ******************SYMBL****************\n";
    cout << "                ┌───────────────────────────────┐\n";
    cout << "                │---NAME---│---TYPE---│---XOB---│\n";
    cout << "                │----------│----------│---------│\n";
    for (Next_w = 0; Next_w < token.size(); Next_w++){ // 扫描token序列填表
        count_data();
        int flag = 1;                // 填表
        for(int i=0;i<Next_w;i++) // 检查要填写的标识符或数组是否与先前填写的表重复
            if (SYMBL[i].NAME==x2){
                flag = 0; // 有重复，不填表
                break;
            }
        if (flag){
            t=7-x2.length();
            if (x1=="I"){ // 储存标识符和函数
                cout << "                │   "<< x2<<string(t,' ')<< "│   ";
                string d2[]={"function ","argument ","parameter"};
                cout<<d1[I_Type[x4-1].first]<< "│"<<d2[I_Type[x4-1].second]<<"│\n";
                cout << "                │----------│----------│---------│\n";
                write_symbol_table();
            }else if (x1=="S"){ // 储存数组
                cout << "                │   "<< x2<<string(t,' ');
                cout << "│   "<<d1[S_Type[x4 - 1]]<< "│ array   │\n";
                cout << "                │----------│----------│---------│\n";
                write_ainfl_table();
                write_symbol_table();
            }
        }
    }
    cout << "                └───────────────────────────────┘\n\n";
    cout << "            *****************FUNCTION******************\n";
    cout << "            ┌─────────────────────────────────────────┐\n";
    cout << "            │-NAME-│-LEVEL-│-OFF-│-FN-│-ENTRY-│-PARAM-│\n";
    cout << "            │------│-------│-----│----│-------│-------│\n";
    for (int i = 0; i < count_PFINFL; i++){
        t=6-PFINFL[i].NAME.length();
        cout << "            │"<< PFINFL[i].NAME<<string(t,' ');
        cout << "│   " << PFINFL[i].LEVEL << "   ";
        cout << "│  " << PFINFL[i].OFF << "  ";
        cout << "│ " << PFINFL[i].FN << "  ";
        cout << "│ entry │       │\n";
        cout << "            │------│-------│-----│----│-------│-------│\n";
    }
    cout << "            └─────────────────────────────────────────┘\n\n";
    cout << "             ******************PARAM****************\n";
    cout << "                ┌───────────────────────────────┐\n";
    cout << "                │---NAME---│---TYPE---│---HSN---│\n";
    cout << "                │----------│----------│---------│\n";
    for (int i=0;i<count_PFINFL;i++)
        for (int j=0;j<count_PARAM[i];j++){
            t=7-PFINFL[i].PARAM[j].NAME.length();
            cout<<"                │   "<<PFINFL[i].PARAM[j].NAME<<string(t,' ');
            cout << "│   "<<d1[PFINFL[i].PARAM[j].TYPE]<< "│  ";
            t=7-PFINFL[i].PARAM[j].HSNAME.length();
            cout << PFINFL[i].PARAM[j].HSNAME<<string(t,' ');
            cout << "│\n                │----------│----------│---------│\n";
        }
    cout << "                └───────────────────────────────┘\n\n";
    cout << "              ********************ARRAY********************\n";
    cout << "              ┌────────────────────────────────────────────┐\n";
    cout << "              │--NAME--│---LOW--│---UP---│--TYPE--│--CLEN--│\n";
    cout << "              │--------│--------│--------│--------│--------│\n";
    for (int i = 0; i < count_AINFL; i++){
        cout << "              │ "<< AINFL[i].NAME;
        t=7-AINFL[i].NAME.length();
        cout<<string(t,' ')<< "│    1   │";
        t=8-to_string(AINFL[i].UP).length();
        cout<<string(t/2,' ')<<AINFL[i].UP<<string(t/2+t%2,' ')<<"│";
        if (AINFL[i].CTP == 1)
            cout << "  int   │   4    │\n";
        else if (AINFL[i].CTP == 2)
            cout << " float  │   8    │\n";
        else if (AINFL[i].CTP == 3)
            cout << "  char  │   1    │\n";
        else if (AINFL[i].CTP == 4)
            cout << " string │   8    │\n";
        cout<<"              │--------│--------│--------│--------│--------│\n";
    }
    cout << "              └────────────────────────────────────────────┘\n\n";
}

void outputQuadruples(){ // 输出所有四元式函数
    cout << "四元式序列为：\n";
    for(int i=0;quadruple[i] != "";i++)
        cout << quadruple[i]+"\n";
    cout << "\n";
}