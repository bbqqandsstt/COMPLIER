/* ************************����ԭ��γ����************************ */
#include "wordAnalysis.h"
#include "printOut.h"

const int max_len = 3000;         //�����ַ�������󳤶�
vector<string> Kk={
    "void","int","float","char"," string","while","const","for","return","if",
    "else","scanf","printf","include","struct" 
}; 
map<string,int> K;        //�ؼ��ֱ�
char P[30][3] = { "-","/","(",")","=","==",">",">=","<","<=","+","+=","*",",",";","++","--","{","}","\"","'","#","&","[","]","%","%d","%f","%c","%s"};        //�����
char P1[22][2] = { "-","/","(",")","=",">","<","+","*",",",";","+","-","{","}","\"","'","#","&","[","]","%" };        //���������
vector<string> Tk = {"stdio.h","stdlib.h","string.h","math.h"};
map<string,int> T;                 //ͷ�ļ���
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
vector<Array> Sk;
string S[20][2];             //�����
int S_Type[20];             //�����б�ʶ������Ӧ������****************************************************
int SS = 0;                      //�����ĳ���
int SS_Type = 0;                 //�����б�ʶ��������Ӧ�ĳ���
string Input;            ///������ַ���
int len;                       //������ַ�������
int error = 0;                   //�ж��﷨�Ƿ����  0Ϊ�޴���     1Ϊ�д���
int token[200][2];          //Token���б�****************************************************
int token_len = 0;               //Token���б�ĳ��ȣ�������
char formType[10][3] = { " ","K","P","I","C1","C2","CT","ST","T","S" };     //K=1��P=2��I=3......

void init(){
    for(int i=0;i<Kk.size();i++)
        K[Kk[i]]=i+1;
    for(int i=0;i<Tk.size();i++)
        T[Tk[i]]=i+1;
}
int main(){
    init();
    int i;
    cout << "��������룺\n";
    char c;
    int count_c = 0;
    while ((c = getchar()) !='@')
        if(c!='\n')
            Input.push_back(c);
    for (auto i:Input)
        cout <<i;
    len = i;
    wordAnalyse();          //�ʷ�������ʼ
    if (!error){
        CX();           //��ʼ�﷨����
        if (!error){
            cout <<"\n****************************���ֱ�***************************\n";
            print_all_form();       //������ֱ�
            cout <<"\n\n****************************���ű�***************************\n";
            make_table();           //��ʼ���з��ű����
            cout <<"\n\n****************************��Ԫʽ����***************************\n";
            outputsiyuanshi();      //�����Ԫʽ����
        }else{
            cout << "�﷨����\n����λ�ã�" << x2 <<"\n";
            for (i = 0; i < Next_w; i++){
                if (token[i][0] == 1){
                    if(!Kk[token[i][1] - 1].compare("include"))
                        cout <<"#"<< Kk[token[i][1] - 1];
                    else
                        cout << Kk[token[i][1] - 1] << " ";
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
                    cout <<"<"<<Tk[token[i][1] - 1]<<">"<< " ";
                else if (token[i][0] == 9)
                    cout << S[token[i][1] - 1][0] << "[" << S[token[i][1] - 1][1] << "]" << " ";
            }
        }
    }else
        cout << "�ʷ�����";
    system("pause");
}
