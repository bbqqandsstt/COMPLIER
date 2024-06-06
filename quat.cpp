#include "quat.h"

stack<string> s;
int xuhao = 0;         // ���Լ�¼���ɵڼ�����Ԫʽ
int jilu = 0;          // ���Լ�¼�ڼ����м����������
string siyuanshi[100]; // ��ȡ��Ԫʽ�ַ�������
string temp1, temp2;
string bo;                          // ��ȡbool�ıȽϷ���Ҫ�嶯��
int if1, if2;                       // ����if��Ԫʽ�����ַʱʹ�õ�
int while1, while2, while3, while4; // ����while��Ԫʽ�����ַʱʹ�õ�
int for1, for2, for3, for4;         // ����for��Ԫʽ�����ַʱʹ�õ�

/*  *****************     ��������������忪ʼ      *****************  */
int xuhao1 = 0;
string siyuanshi1[100];

string SYS[50][4];     // ������Ԫʽ
string SYS_new[50][4]; // �Ż�����������Ԫʽ
int SYS_new_len = 0;   // �Ż������������Ԫʽ�ĳ���

string youhua_quan[50][10], youhua_caozuo[50][4];
int youhua_quan_j_len[50], quan = 0, caozuo = 0;

// �﷨�Ƶ�������Ԫʽ
void QUATJIA(){ // �Ӻ�������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(+," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "+";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void QUATJIAN(){ // ����������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(-," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "-";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void QUATCHENGE(){ // �˺�������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(*," + temp2 + "," + temp1 + "," + *p + ")";
    siyuanshi1[xuhao1++] = "(*," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "*";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void QUATCHU(){ /// ������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(/," + temp2 + "," + temp1 + "," + *p + ")";
    siyuanshi1[xuhao1++] = "(/," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "/";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void QUATFUZHI(){ // ��ֵ���������Ԫʽ���躯��
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(=," + temp1 + ",_," + temp2 + ")";
    siyuanshi1[xuhao1++] = "(=," + temp1 + ",_," + temp2 + ")";
    SYS[xuhao][0] = "=";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = temp2;
}

// ����Ϊ��������ѭ�����������Ԫʽ�������躯��
void QUATBOOL(){ // bool���ͱ��ʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(" + bo + "," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = bo;
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p); // ��bool���ʽ�Ľ������ջ��
}

void QUATIF(){ // if���
    temp1 = s.top();
    s.pop();
    string temp = "";
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(if," + temp1 + ",_,"; // ��ʱs.pop����bool���ʽ�Ľ��
    siyuanshi1[xuhao1] = temp + "(if," + temp1 + ",_,";
    SYS[xuhao][0] = "if";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    if1 = xuhao++;
    if2 = xuhao1++;
}

void QUATELSE(){ // else���
    string temp = "";
    int i = xuhao + 1, j = xuhao1 + 1;
    siyuanshi[if1] += to_string(i) + ")";
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(el,_,_,";
    siyuanshi1[if2] += to_string(j) + ")";
    siyuanshi1[xuhao1] = temp + "(el,_,_,";
    SYS[xuhao][0] = "el";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    if1 = xuhao++;
    if2 = xuhao1++;
}

void QUATIFEND(){ // if������
    string temp = "";
    siyuanshi[if1] += to_string(xuhao) + ")";
    siyuanshi1[if2] += to_string(xuhao1++) + ")";
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(ie,_,_,_)";
    siyuanshi1[xuhao1] = temp + "(ie,_,_,_)";
    SYS[xuhao][0] = "ie";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void QUATWHILE(){ // while���
    string temp = "";
    while1 = xuhao;
    while3 = xuhao1;
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(wh,_,_,_)";
    siyuanshi1[xuhao1++] = temp + "(wh,_,_,_)";
    SYS[xuhao][0] = "wh";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void QUATDO(){ // do���
    while2 = xuhao;
    while4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(do," + temp1 + ",_,"; // bool�Ǹ����Ѿ���bool���ʽ�Ľ�����ȥ�ˣ���s.pop
    siyuanshi1[xuhao1++] = temp + "(do," + temp1 + ",_,";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void QUATWHILEEND(){ // while������
    string temp = "";
    int i = xuhao + 1, j = while1 + 1, k = xuhao1 + 1, m = while3 + 1;
    siyuanshi[while2] += to_string(i) + ")";
    siyuanshi1[while4] += to_string(k) + ")";
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(we,_,_," + to_string(j) + ")";
    siyuanshi1[xuhao1++] = temp + "(we,_,_," + to_string(m) + ")";
    SYS[xuhao][0] = "we";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void QUATFOR(){ // for���
    string temp = "";
    for1 = xuhao;
    for3 = xuhao1;
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(for,_,_,_)";
    siyuanshi1[xuhao1++] = temp + "(for,_,_,_)";
    SYS[xuhao][0] = "for";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void QUATDOFOR(){ // do for���
    for2 = xuhao;
    for4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(do," + temp1 + ",_,"; // bool�Ǹ����Ѿ���bool���ʽ�Ľ�����ȥ�ˣ���s.pop
    siyuanshi1[xuhao1++] = temp + "(do," + temp1 + ",_,";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void QUATFOREND(){ // for������
    string temp = "";
    int i = xuhao + 1, j = for1 + 1, k = xuhao1 + 1, m = for3 + 1;
    siyuanshi[for2] += to_string(i) + ")";
    siyuanshi1[for4] += to_string(k) + ")";
    siyuanshi[xuhao] = "QT[" + to_string(xuhao) + "]:(fe,_,_," + to_string(j) + ")";
    siyuanshi1[xuhao1++] = temp + "(fe,_,_," + to_string(m) + ")";
    SYS[xuhao][0] = "fe";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

/*  *****************     ������������������     *****************  */