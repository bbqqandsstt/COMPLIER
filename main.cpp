/* ************************����ԭ��γ����************************ */
#include "wordAnalysis.h"
#include "printOut.h"

vector<string> Kk={
    "void","int","float","char","string","while","const","for","return","if",
    "else","scanf","printf","include","struct" 
}; 
map<string,int> K;        //�ؼ��ֱ�
vector<string> Pk = {
    "-","/","(",")","=","==",">",">=","<","<=","+","+=","*",",",";","++","--","{",
    "}","\"","'","#","&","[","]","%","%d","%f","%c","%s"
};
map<string,int> P;     //�����
vector<string> Hk = {"stdio.h","stdlib.h","string.h","math.h"};
map<string,int> H;                 //ͷ�ļ���
vector<string> Ik;
map<string,int> I;                //��ʶ����
int I_Type[20];             //��ʶ������Ӧ������****************************************************
int I_Type2[20];            //��ʶ���Ǳ���(=1)�����β�(=2)****************************************************
int II_Type = 0;                 //��ʶ����Ӧ���͵��ֳ���
vector<string> C1k;
map<string,int> C1;                 //��������
char C2[20][10];                 //��ʵ����
int CC2 = 0;                     //��ʵ������ֳ���
vector<string> CTk;
map<string,int> CT;               //�ַ�����
vector<string> STk;
map<string,int> ST;               //�ַ�������
vector<Array> Sk;
map<Array,int> S;             //�����
int S_Type[20];             //�����б�ʶ������Ӧ������****************************************************
int SS_Type = 0;                 //�����б�ʶ��������Ӧ�ĳ���
string Input;            ///������ַ���
int error = 0;                   //�ж��﷨�Ƿ����  0Ϊ�޴���    
vector<pair<int,int>> token;          //Token���б�****************************************************
int token_len = 0;               //Token���б�ĳ��ȣ�������
string formType[10]= { " ","K","P","I","C1","C2","CT","ST","H","S" };     //K=1��P=2��I=3......

void init(){
    for(int i=0;i<Kk.size();i++)
        K[Kk[i]]=i+1;
    for(int i=0;i<Hk.size();i++)
        H[Hk[i]]=i+1;
    for(int i=0;i<Pk.size();i++)
        P[Pk[i]]=i+1;
}
int main(){
    init();
    cout << "��������룺\n";
    char c;
    int count_c = 0;
    while ((c = getchar()) !='@')
        if(c!='\n')
            Input.push_back(c);
    for (auto i:Input)
        cout <<i;
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
            for (int i = 0,t; i < Next_w; i++){
                t=token[i].second-1;
                switch(token[i].first){
                    case 1:
                        if(!Kk[t].compare("include"))
                            cout <<"#"+Kk[t];
                        else
                            cout << Kk[t]+" ";
                        break;
                    case 2:
                        cout << Pk[t]+" ";
                        break;
                    case 3:
                        cout << Ik[t]+" ";
                        break;
                    case 4:
                        cout << C1k[t]+" ";
                        break;
                    case 5:
                        cout << C2[t] << " ";
                        break;
                    case 6:
                        cout << CTk[t]+" ";
                        break;
                    case 7:
                        cout << STk[t]+" ";
                        break;
                    case 8:
                        cout <<"<"+Hk[t]+"> ";
                        break;
                    case 9:
                        cout << Sk[t]<< " ";
                        break;
                }
            }
        }
    }else
        cout << "�ʷ�����";
    system("pause");
}
