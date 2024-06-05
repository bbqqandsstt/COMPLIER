#include "quat.h"

stack<string> s;
int xuhao = 0;//用以记录生成第几个四元式
int jilu = 0;//用以记录第几个中间变量的生成
string siyuanshi[100];//存取四元式字符串数组
string temp1;
string temp2;
string bo;//存取bool的比较符，要插动作
int if1;//用于if四元式回填地址时使用的
int if2;
int while1;//用于while四元式回填地址时使用的
int while2;//用于while四元式回填地址时使用的
int while3;
int while4;
int for1;//用于while四元式回填地址时使用的
int for2;//用于while四元式回填地址时使用的
int for3;
int for4;

/*  *****************     语义分析函数定义开始      *****************  */
int xuhao1 = 0;
string siyuanshi1[100];

string SYS[50][4];                  //数组四元式
string SYS_new[50][4];              //优化过的数组四元式
int SYS_new_len = 0;                  //优化过后的数组四元式的长度

string youhua_quan[50][10];
int youhua_quan_j_len[50];
int quan = 0;
string youhua_chaozuo[50][4];
int chaozuo = 0;


string int2str(int& i)
{
    return to_string(i);
}

//语法制导生成四元式
void QUATJIA()//加号生成四元式
{
    temp1 = s.top();//弹栈
    s.pop();
    temp2 = s.top();
    s.pop();
    string* p = new string;
    *p = "t" + int2str(jilu);
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(+," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "+";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao][3] = *p;
    s.push(*p);
    xuhao++;
}

void QUATJIAN()//减号生成四元式
{
    temp1 = s.top();//弹栈
    s.pop();
    temp2 = s.top();
    s.pop();
    string* p = new string;
    *p = "t" + int2str(jilu);
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(-," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "-";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao][3] = *p;
    s.push(*p);
    xuhao++;
}

void QUATCHENGE()//乘号生成四元式
{
    temp1 = s.top();//弹栈
    s.pop();
    temp2 = s.top();
    s.pop();
    string* p = new string;
    *p = "t" + int2str(jilu);
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(*," + temp2 + "," + temp1 + "," + *p + ")";
    siyuanshi1[xuhao1] = "(*," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "*";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao][3] = *p;
    s.push(*p);
    xuhao1++;
    xuhao++;
}


void QUATCHU()///除号四元式 
{
    temp1 = s.top();//弹栈
    s.pop();
    temp2 = s.top();
    s.pop();
    string* p = new string;
    *p = "t" + int2str(jilu);
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(/," + temp2 + "," + temp1 + "," + *p + ")";
    siyuanshi1[xuhao1] = "(/," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "/";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao][3] = *p;
    s.push(*p);
    xuhao1++;
    xuhao++;
}

void QUATFUZHI()//赋值语句生成四元式所需函数
{
    temp1 = s.top();//弹栈
    s.pop();
    temp2 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(=," + temp1 + "," + "_" + "," + temp2 + ")";
    siyuanshi1[xuhao1] = "(=," + temp1 + "," + "_" + "," + temp2 + ")";
    SYS[xuhao][0] = "=";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = temp2;
    xuhao1++;
    xuhao++;
}

//以下为条件语句和循环语句生成四元式部分所需函数
void QUATBOOL() //bool类型表达式 
{
    temp1 = s.top();//弹栈
    s.pop();
    temp2 = s.top();
    s.pop();
    string* p = new string;
    *p = "t" + int2str(jilu);
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + bo + "," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = bo;
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao][3] = *p;
    xuhao++;
    s.push(*p);//将bool表达式的结果存入栈中
}

void QUATIF()//if语句 
{
    temp1 = s.top();
    s.pop();
    string temp = "";
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "if" + "," + temp1 + "," + "_" + ",";//此时s.pop就是bool表达式的结果
    siyuanshi1[xuhao1] = temp + "(" + "if" + "," + temp1 + "," + "_" + ",";
    SYS[xuhao][0] = "if";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    if1 = xuhao;
    if2 = xuhao1;
    xuhao++;
    xuhao1++;
}

void QUATELSE()//else语句 
{
    string temp = "";
    int i = xuhao + 1;
    int j = xuhao1 + 1;
    siyuanshi[if1] += int2str(i) + ")";
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "el" + "," + "_" + "," + "_" + ",";
    siyuanshi1[if2] += int2str(j) + ")";
    siyuanshi1[xuhao1] = temp + "(" + "el" + "," + "_" + "," + "_" + ",";
    SYS[xuhao][0] = "el";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    if1 = xuhao;
    if2 = xuhao1;
    xuhao++;
    xuhao1++;
}

void QUATIFEND()//if语句结束 
{
    string temp = "";
    siyuanshi[if1] += int2str(xuhao) + ")";
    siyuanshi1[if2] += int2str(xuhao1) + ")";
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "ie" + "," + "_" + "," + "_" + "," + "_" + ")";
    siyuanshi1[xuhao1] = temp + "(" + "ie" + "," + "_" + "," + "_" + "," + "_" + ")";
    SYS[xuhao][0] = "ie";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATWHILE()//while语句 
{
    string temp = "";
    while1 = xuhao;
    while3 = xuhao1;
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "wh" + "," + "_" + "," + "_" + "," + "_" + ")";
    siyuanshi1[xuhao1] = temp + "(" + "wh" + "," + "_" + "," + "_" + "," + "_" + ")";
    SYS[xuhao][0] = "wh";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATDO()//do语句 
{
    while2 = xuhao;
    while4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "do" + "," + temp1 + "," + "_" + ",";//bool那个区已经将bool表达式的结果存进去了，即s.pop
    siyuanshi1[xuhao1] = temp + "(" + "do" + "," + temp1 + "," + "_" + ",";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATWHILEEND()//while语句结束 
{
    string temp = "";
    int i = xuhao + 1;
    int j = while1 + 1;
    int k = xuhao1 + 1;
    int m = while3 + 1;
    siyuanshi[while2] += int2str(i) + ")";
    siyuanshi1[while4] += int2str(k) + ")";
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "we" + "," + "_" + "," + "_" + "," + int2str(j) + ")";
    siyuanshi1[xuhao1] = temp + "(" + "we" + "," + "_" + "," + "_" + "," + int2str(m) + ")";
    SYS[xuhao][0] = "we";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATFOR()//for语句 
{
    string temp = "";
    for1 = xuhao;
    for3 = xuhao1;
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "for" + "," + "_" + "," + "_" + "," + "_" + ")";
    siyuanshi1[xuhao1] = temp + "(" + "for" + "," + "_" + "," + "_" + "," + "_" + ")";
    SYS[xuhao][0] = "for";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATDOFOR()//do for语句 
{
    for2 = xuhao;
    for4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "do" + "," + temp1 + "," + "_" + ",";//bool那个区已经将bool表达式的结果存进去了，即s.pop
    siyuanshi1[xuhao1] = temp + "(" + "do" + "," + temp1 + "," + "_" + ",";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATFOREND()//for语句结束 
{
    string temp = "";
    int i = xuhao + 1;
    int j = for1 + 1;
    int k = xuhao1 + 1;
    int m = for3 + 1;
    siyuanshi[for2] += int2str(i) + ")";
    siyuanshi1[for4] += int2str(k) + ")";
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "fe" + "," + "_" + "," + "_" + "," + int2str(j) + ")";
    siyuanshi1[xuhao1] = temp + "(" + "fe" + "," + "_" + "," + "_" + "," + int2str(m) + ")";
    SYS[xuhao][0] = "fe";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

/*  *****************     语义分析函数定义结束     *****************  */