/* ************************����ԭ��γ����************************ */
#include "wordAnalysis.h"
#include "printOut.h"

const int max_len = 3000;         //�����ַ�������󳤶�
char K[15][8] = { "void","int","float","char"," string","while","const","for","return","if","else","scanf","printf","include","struct" };        //�ؼ��ֱ�
char P[30][3] = { "-","/","(",")","=","==",">",">=","<","<=","+","+=","*",",",";","++","--","{","}","\"","'","#","&","[","]","%","%d","%f","%c","%s"};        //�����
char P1[22][2] = { "-","/","(",")","=",">","<","+","*",",",";","+","-","{","}","\"","'","#","&","[","]","%" };        //���������
char T[4][10] = { "stdio.h","stdlib.h","string.h","math.h" };                 //ͷ�ļ���
char I[20][20];                //��ʶ����
int I_Type[20];             //��ʶ������Ӧ������****************************************************
int I_Type2[20];            //��ʶ���Ǳ���(=1)�����β�(=2)****************************************************
int II = 0;                      //��ʶ������ֳ���
int II_Type = 0;                 //��ʶ����Ӧ���͵��ֳ���
char C1[20][10];                 //��������
int CC1 = 0;                     //����������ֳ���
char C2[20][10];                 //��ʵ����
int CC2 = 0;                     //��ʵ������ֳ���
char CT[20][10];               //�ַ�����
int CTT = 0;                     //�ַ�������ĳ���
char ST[20][10];               //�ַ�������
int STT = 0;                     //�ַ���������ĳ���
char S[20][2][10];             //�����
int S_Type[20];             //�����б�ʶ������Ӧ������****************************************************
int SS = 0;                      //�����ĳ���
int SS_Type = 0;                 //�����б�ʶ��������Ӧ�ĳ���
char Input[max_len];            ///������ַ���
int len;                       //������ַ�������
int error = 0;                   //�ж��﷨�Ƿ����  0Ϊ�޴���     1Ϊ�д���
int token[200][2];          //Token���б�****************************************************
int token_len = 0;               //Token���б�ĳ��ȣ�������
char formType[10][3] = { " ","K","P","I","C1","C2","CT","ST","T","S" };     //K=1��P=2��I=3......


int main()
{
    int i;
    cout << "��������룺" << endl;
    char c;
    int count_c = 0;
    while ((c = getchar()) !='@') { 
        if(c!='\n')
            Input[count_c++] = c;
    }
    for (i = 0; i < max_len; i++)
    {
        cout << Input[i];
        if (Input[i] == '\0') break;
    }
    len = i;
    wordAnalyse();          //�ʷ�������ʼ
    if (error == 0)
    {
        CX();           //��ʼ�﷨����
        if (error == 0)
        {
            cout << endl << "****************************���ֱ�***************************" << endl;
            print_all_form();       //������ֱ�
            cout << endl << endl << "****************************���ű�***************************" << endl;
            make_table();           //��ʼ���з��ű����
            cout << endl << endl << "****************************��Ԫʽ����***************************" << endl;
            outputsiyuanshi();      //�����Ԫʽ����
        }
        else if (error == 1)
        {
            cout << "�﷨����"<<endl;
            cout << "����λ�ã�" << x2 << endl;

            for (i = 0; i < Next_w; i++)
            {
                if (token[i][0] == 1)
                {
                    if(strcmp(K[token[i][1] - 1],"include")==0)
                        cout <<"#"<< K[token[i][1] - 1];
                    else
                        cout << K[token[i][1] - 1] << " ";
                }
                else if (token[i][0] == 2)
                    cout << P[token[i][1] - 1] << " ";
                else if (token[i][0] == 3)
                    cout << I[token[i][1] - 1] << " ";
                else if (token[i][0] == 4)
                    cout << C1[token[i][1] - 1] << " ";
                else if (token[i][0] == 5)
                    cout << C2[token[i][1] - 1] << " ";
                else if (token[i][0] == 6)
                    cout << CT[token[i][1] - 1] << " ";
                else if (token[i][0] == 7)
                    cout << ST[token[i][1] - 1] << " ";
                else if (token[i][0] == 8)
                    cout <<"<"<<T[token[i][1] - 1]<<">"<< " ";
                else if (token[i][0] == 9)
                    cout << S[token[i][1] - 1][0] << "[" << S[token[i][1] - 1][1] << "]" << " ";
            }

        }
    }
    else if (error == 1)
        cout << "�ʷ�����";
    system("pause");
}
