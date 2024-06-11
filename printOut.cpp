#include "printOut.h"

void print_all_forms(){ // ������ֱ�
    int i;
    cout << "��ʶ����";
    for (auto i:Ik)
        cout <<i+"  ";
    cout << "\n��ʶ��������(int-1,float-2,char-3,string-4,void-5)��";
    for (auto i:I_Type)
        cout << i.first << "  ";
    cout <<"\n���������βΣ�";
    for (auto i:I_Type)
        cout << i.second << "  ";
    cout << "\n������";
    for (auto i:C1k)
        cout << i << "  ";
    cout << "\nʵ����";
    for (auto i:C2k)
        cout << i << "  ";
    cout << "\n�ַ���";
    for (auto i:CTk)
        cout << i+ "  ";
    cout << "\n�ַ�����";
    for (auto i:STk)
        cout << i+ "  ";
    cout << "\n�����";
    for (auto i:Sk)
        cout << i.name << "  ";
    cout << "\n���鳤�ȱ�";
    for (auto i:Sk)
        cout << i.index << "  ";
    cout << "\n�������ͱ�";
    for (auto i:S_Type)
        cout << i << "  ";
}

void make_table(){
    int i, k, m;
    string d1[]={"","int    ","float  ","char   ","string ","void   "};
    cout << "             ******************SYMBL****************\n";
    cout << "                ������������������������������������������������������������������\n";
    cout << "                ��---NAME---��---TYPE---��---XOB---��\n";
    cout << "                ��----------��----------��---------��\n";
    for (Next_w = 0; Next_w < token.size(); Next_w++){ // ɨ��token�������
        count_data();
        int flag = 1;                // ���
        for (i = 0; i < Next_w; i++) // ���Ҫ��д�ı�ʶ���������Ƿ�����ǰ��д�ı��ظ�
            if (SYNBL[i].NAME==x2){
                flag = 0; // ���ظ��������
                break;
            }
        if (flag){
            if (x1=="I"){ // �����ʶ���ͺ���
                cout << "                ��   "<< x2;
                for (i=x2.length(); i < 7; i++)
                    cout << " ";
                cout << "��   ";
                string d2[]={"function ","argument ","parameter"};
                cout <<d1[I_Type[x4 - 1].first]<< "��"<<d2[I_Type[x4-1].second]<< "��\n";
                cout << "                ��----------��----------��---------��\n";
                write_symbol_table();
            }else if (x1=="S"){ // ��������
                cout << "                ��   "<< x2;
                for (i=x2.length(); i < 7; i++)
                    cout << " ";
                cout << "��   "<<d1[S_Type[x4 - 1]]<< "�� array   ��\n";
                cout << "                ��----------��----------��---------��\n";
                write_ainfl_table();
                write_symbol_table();
            }
        }
    }
    cout << "                ������������������������������������������������������������������\n\n";
    cout << "            ******************PFINFL*******************\n";
    cout << "            ��������������������������������������������������������������������������������������\n";
    cout << "            ��-NAME-��-LEVEL-��-OFF-��-FN-��-ENTRY-��-PARAM-��\n";
    cout << "            ��------��-------��-----��----��-------��-------��\n";
    for (k = 0; k < count_PFINFL; k++){
        for (i = 0; PFINFL[k].NAME[i] != '\0';)
            i++;
        cout << "            ��";
        cout << PFINFL[k].NAME;
        for (; i < 6; i++)
            cout << " ";
        cout << "��   " << PFINFL[k].LEVEL << "   ";
        cout << "��  " << PFINFL[k].OFF << "  ";
        cout << "�� " << PFINFL[k].FN << "  ";
        cout << "�� entry ��       ��\n";
        cout << "            ��------��-------��-----��----��-------��-------��\n";
    }
    cout << "            ��������������������������������������������������������������������������������������\n\n";
    cout << "             ******************PARAM****************\n";
    cout << "                ������������������������������������������������������������������\n";
    cout << "                ��---NAME---��---TYPE---��---HSN---��\n";
    cout << "                ��----------��----------��---------��\n";
    for (m = 0; m < count_PFINFL; m++)
        for (k = 0; k < count_PARAM[m]; k++){
            for (i = 0; PFINFL[m].PARAM[k].NAME[i] != '\0';)
                i++;
            cout << "                ��   ";
            cout << PFINFL[m].PARAM[k].NAME;
            for (; i < 7; i++)
                cout << " ";
            cout << "��   "<<d1[PFINFL[m].PARAM[k].TYPE]<< "��  ";
            for (i = 0; PFINFL[m].PARAM[k].HSNAME[i] != '\0';)
                i++;
            cout << PFINFL[m].PARAM[k].HSNAME;
            for (; i < 7; i++)
                cout << " ";
            cout << "��\n";
            cout << "                ��----------��----------��---------��\n";
        }
    cout << "                ������������������������������������������������������������������\n\n";
    cout << "              *****************AINFL***************\n";
    cout << "              ��������������������������������������������������������������������������\n";
    cout << "              ��--NAME--��-LOW-��-UP-��--TYPE--��-CLEN-��\n";
    cout << "              ��--------��-----��----��--------��------��\n";
    for (k = 0; k < count_AINFL; k++){
        for (i = 0; AINFL[k].NAME[i] != '\0';)
            i++;
        cout << "              �� ";
        cout << AINFL[k].NAME;
        for (; i < 7; i++)
            cout << " ";
        cout << "��  1  �� ";
        cout << AINFL[k].UP;
        cout << "  ��";
        if (AINFL[k].CTP == 1)
            cout << "  int   ��  4   ��\n";
        else if (AINFL[k].CTP == 2)
            cout << " float  ��  8   ��\n";
        else if (AINFL[k].CTP == 3)
            cout << "  char  ��  1   ��\n";
        else if (AINFL[k].CTP == 4)
            cout << " string ��  8   ��\n";
        cout << "              ��--------��-----��----��--------��------��\n";
    }
    cout << "              ��������������������������������������������������������������������������\n\n";
}

void outputQuadruples(){ // ���������Ԫʽ����
    cout << "��Ԫʽ����Ϊ��\n";
    for(int i=0;quadruple[i] != "";i++)
        cout << quadruple[i]+"\n";
    cout << endl;
}