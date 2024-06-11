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
vector<pair<int,int>> I_Type;             //��ʶ������Ӧ������,��ʶ���Ǳ���(=1)�����β�(=2)****************************************************
vector<string> C1k;
map<string,int> C1;                 //��������
vector<string> C2k;
map<string,int> C2;                 //��ʵ����
vector<string> CTk;
map<string,int> CT;               //�ַ�����
vector<string> STk;
map<string,int> ST;               //�ַ�������
vector<Array> Sk;
map<Array,int> S;             //�����
vector<int> S_Type;             //�����б�ʶ������Ӧ������****************************************************
string Input;            ///������ַ���
int error = 0;                   //�ж��﷨�Ƿ����  0Ϊ�޴���    
vector<pair<int,int>> token;          //Token���б�****************************************************
string formType[10]={" ","K","P","I","C1","C2","CT","ST","H","S"};     //K=1��P=2��I=3......

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
    while ((c = getchar()) !='@')
        if(c!='\n')
            Input.push_back(c);
    for (auto i:Input)
        cout <<i;
    cout<<"\n";
    wordAnalyse();          //�ʷ�������ʼ
    if (!error){
        CX();           //��ʼ�﷨����
        if (!error){
            cout <<"****************************���ֱ�***************************\n";
            print_all_forms();       //������ֱ�
            cout<<"\n\n****************************���ű�***************************\n";
            make_table();           //��ʼ���з��ű����
            cout<<"\n\n****************************��Ԫʽ����***************************\n";
            outputQuadruples();      //�����Ԫʽ����
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
                        cout << C2k[t] << " ";
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
            cout<<"\n";
        }
    }else
        cout << "�ʷ�����\n";
    system("pause");
}
