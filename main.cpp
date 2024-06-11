/* ************************编译原理课程设计************************ */
#include "wordAnalysis.h"
#include "printOut.h"

vector<string> Kk={
    "void","int","float","char","string","while","const","for","return","if",
    "else","scanf","printf","include","struct" 
}; 
map<string,int> K;        //关键字表
vector<string> Pk = {
    "-","/","(",")","=","==",">",">=","<","<=","+","+=","*",",",";","++","--","{",
    "}","\"","'","#","&","[","]","%","%d","%f","%c","%s"
};
map<string,int> P;     //界符表
vector<string> Hk = {"stdio.h","stdlib.h","string.h","math.h"};
map<string,int> H;                 //头文件表
vector<string> Ik;
map<string,int> I;                //标识符表
vector<pair<int,int>> I_Type;             //标识符所对应的类型,标识符是变量(=1)还是形参(=2)****************************************************
vector<string> C1k;
map<string,int> C1;                 //常整数表
vector<string> C2k;
map<string,int> C2;                 //常实数表
vector<string> CTk;
map<string,int> CT;               //字符常量
vector<string> STk;
map<string,int> ST;               //字符串常量
vector<Array> Sk;
map<Array,int> S;             //数组表
vector<int> S_Type;             //数组中标识符所对应的类型****************************************************
string Input;            ///输入的字符串
int error = 0;                   //判断语法是否错误  0为无错误    
vector<pair<int,int>> token;          //Token序列表****************************************************
string formType[10]={" ","K","P","I","C1","C2","CT","ST","H","S"};     //K=1，P=2，I=3......

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
    cout << "请输入代码：\n";
    char c;
    while ((c = getchar()) !='@')
        if(c!='\n')
            Input.push_back(c);
    for (auto i:Input)
        cout <<i;
    cout<<"\n";
    wordAnalyse();          //词法分析开始
    if (!error){
        CX();           //开始语法分析
        if (!error){
            cout <<"****************************各种表***************************\n";
            print_all_forms();       //输出各种表
            cout<<"\n\n****************************符号表***************************\n";
            make_table();           //开始进行符号表操作
            cout<<"\n\n****************************四元式序列***************************\n";
            outputQuadruples();      //输出四元式序列
        }else{
            cout << "语法错误\n错误位置：" << x2 <<"\n";
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
        cout << "词法错误\n";
    system("pause");
}
