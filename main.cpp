/* ************************编译原理课程设计************************ */
#include "wordAnalysis.h"
#include "printOut.h"

const int max_len = 3000;         //输入字符串的最大长度
vector<string> Kk={
    "void","int","float","char"," string","while","const","for","return","if",
    "else","scanf","printf","include","struct" 
}; 
map<string,int> K;        //关键字表
char P[30][3] = { "-","/","(",")","=","==",">",">=","<","<=","+","+=","*",",",";","++","--","{","}","\"","'","#","&","[","]","%","%d","%f","%c","%s"};        //界符表
char P1[22][2] = { "-","/","(",")","=",">","<","+","*",",",";","+","-","{","}","\"","'","#","&","[","]","%" };        //辅助界符表
vector<string> Tk = {"stdio.h","stdlib.h","string.h","math.h"};
map<string,int> T;                 //头文件表
char I[20][20];                //标识符表
int I_Type[20];             //标识符所对应的类型****************************************************
int I_Type2[20];            //标识符是变量(=1)还是形参(=2)****************************************************
int II = 0;                      //标识符表的现长度
int II_Type = 0;                 //标识符对应类型的现长度
char C1[20][10];                 //常整数表
int CC1 = 0;                     //常整数表的现长度
char C2[20][10];                 //常实数表
int CC2 = 0;                     //常实数表的现长度
char CT[20][10];               //字符常量
int CTT = 0;                     //字符常量表的长度
char ST[20][10];               //字符串常量
int STT = 0;                     //字符串常量表的长度
vector<Array> Sk;
string S[20][2];             //数组表
int S_Type[20];             //数组中标识符所对应的类型****************************************************
int SS = 0;                      //数组表的长度
int SS_Type = 0;                 //数组中标识符的类别对应的长度
string Input;            ///输入的字符串
int len;                       //输入的字符串长度
int error = 0;                   //判断语法是否错误  0为无错误     1为有错误
int token[200][2];          //Token序列表****************************************************
int token_len = 0;               //Token序列表的长度（行数）
char formType[10][3] = { " ","K","P","I","C1","C2","CT","ST","T","S" };     //K=1，P=2，I=3......

void init(){
    for(int i=0;i<Kk.size();i++)
        K[Kk[i]]=i+1;
    for(int i=0;i<Tk.size();i++)
        T[Tk[i]]=i+1;
}
int main(){
    init();
    int i;
    cout << "请输入代码：\n";
    char c;
    int count_c = 0;
    while ((c = getchar()) !='@')
        if(c!='\n')
            Input.push_back(c);
    for (auto i:Input)
        cout <<i;
    len = i;
    wordAnalyse();          //词法分析开始
    if (!error){
        CX();           //开始语法分析
        if (!error){
            cout <<"\n****************************各种表***************************\n";
            print_all_form();       //输出各种表
            cout <<"\n\n****************************符号表***************************\n";
            make_table();           //开始进行符号表操作
            cout <<"\n\n****************************四元式序列***************************\n";
            outputsiyuanshi();      //输出四元式序列
        }else{
            cout << "语法错误\n错误位置：" << x2 <<"\n";
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
        cout << "词法错误";
    system("pause");
}
