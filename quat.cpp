#include "quat.h"

stack<string> s;
int xuhao = 0;//���Լ�¼���ɵڼ�����Ԫʽ
int jilu = 0;//���Լ�¼�ڼ����м����������
string siyuanshi[100];//��ȡ��Ԫʽ�ַ�������
string temp1;
string temp2;
string bo;//��ȡbool�ıȽϷ���Ҫ�嶯��
int if1;//����if��Ԫʽ�����ַʱʹ�õ�
int if2;
int while1;//����while��Ԫʽ�����ַʱʹ�õ�
int while2;//����while��Ԫʽ�����ַʱʹ�õ�
int while3;
int while4;
int for1;//����while��Ԫʽ�����ַʱʹ�õ�
int for2;//����while��Ԫʽ�����ַʱʹ�õ�
int for3;
int for4;

/*  *****************     ��������������忪ʼ      *****************  */
int xuhao1 = 0;
string siyuanshi1[100];

string SYS[50][4];                  //������Ԫʽ
string SYS_new[50][4];              //�Ż�����������Ԫʽ
int SYS_new_len = 0;                  //�Ż������������Ԫʽ�ĳ���

string youhua_quan[50][10];
int youhua_quan_j_len[50];
int quan = 0;
string youhua_chaozuo[50][4];
int chaozuo = 0;


string int2str(int& i)
{
    return to_string(i);
}

//�﷨�Ƶ�������Ԫʽ
void QUATJIA()//�Ӻ�������Ԫʽ
{
    temp1 = s.top();//��ջ
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

void QUATJIAN()//����������Ԫʽ
{
    temp1 = s.top();//��ջ
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

void QUATCHENGE()//�˺�������Ԫʽ
{
    temp1 = s.top();//��ջ
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


void QUATCHU()///������Ԫʽ 
{
    temp1 = s.top();//��ջ
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

void QUATFUZHI()//��ֵ���������Ԫʽ���躯��
{
    temp1 = s.top();//��ջ
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

//����Ϊ��������ѭ�����������Ԫʽ�������躯��
void QUATBOOL() //bool���ͱ��ʽ 
{
    temp1 = s.top();//��ջ
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
    s.push(*p);//��bool���ʽ�Ľ������ջ��
}

void QUATIF()//if��� 
{
    temp1 = s.top();
    s.pop();
    string temp = "";
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "if" + "," + temp1 + "," + "_" + ",";//��ʱs.pop����bool���ʽ�Ľ��
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

void QUATELSE()//else��� 
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

void QUATIFEND()//if������ 
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

void QUATWHILE()//while��� 
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

void QUATDO()//do��� 
{
    while2 = xuhao;
    while4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "do" + "," + temp1 + "," + "_" + ",";//bool�Ǹ����Ѿ���bool���ʽ�Ľ�����ȥ�ˣ���s.pop
    siyuanshi1[xuhao1] = temp + "(" + "do" + "," + temp1 + "," + "_" + ",";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATWHILEEND()//while������ 
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

void QUATFOR()//for��� 
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

void QUATDOFOR()//do for��� 
{
    for2 = xuhao;
    for4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + int2str(xuhao) + "]:(" + "do" + "," + temp1 + "," + "_" + ",";//bool�Ǹ����Ѿ���bool���ʽ�Ľ�����ȥ�ˣ���s.pop
    siyuanshi1[xuhao1] = temp + "(" + "do" + "," + temp1 + "," + "_" + ",";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    xuhao1++;
    xuhao++;
}

void QUATFOREND()//for������ 
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

/*  *****************     ������������������     *****************  */