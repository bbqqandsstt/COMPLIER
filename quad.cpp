#include "quad.h"

stack<string> s;
int xuhao = 0;         // ���Լ�¼���ɵڼ�����Ԫʽ
int jilu = 0;          // ���Լ�¼�ڼ����м����������
string quadruple[100]; // ��ȡ��Ԫʽ�ַ�������
string temp1, temp2;
string bo;                          // ��ȡbool�ıȽϷ���Ҫ�嶯��
int if1, if2;                       // ����if��Ԫʽ�����ַʱʹ�õ�
int while1, while2, while3, while4; // ����while��Ԫʽ�����ַʱʹ�õ�
int for1, for2, for3, for4;         // ����for��Ԫʽ�����ַʱʹ�õ�

/*  *****************     ��������������忪ʼ      *****************  */
int xuhao1 = 0;
string quadruple1[100];

string SYS[50][4];     // ������Ԫʽ
string SYS_new[50][4]; // �Ż�����������Ԫʽ
int SYS_new_len = 0;   // �Ż������������Ԫʽ�ĳ���

string youhua_quan[50][10], youhua_caozuo[50][4];
int youhua_quan_j_len[50], quan = 0, caozuo = 0;

// �﷨�Ƶ�������Ԫʽ
void quadPlus(){ // �Ӻ�������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(+," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "+";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void quadMinus(){ // ����������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(-," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "-";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void quadMultiply(){ // �˺�������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(*," + temp2 + "," + temp1 + "," + *p + ")";
    quadruple1[xuhao1++] = "(*," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "*";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void quadDivide(){ /// ������Ԫʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(/," + temp2 + "," + temp1 + "," + *p + ")";
    quadruple1[xuhao1++] = "(/," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = "/";
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p);
}

void quadAssign(){ // ��ֵ���������Ԫʽ���躯��
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(=," + temp1 + ",_," + temp2 + ")";
    quadruple1[xuhao1++] = "(=," + temp1 + ",_," + temp2 + ")";
    SYS[xuhao][0] = "=";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = temp2;
}

// ����Ϊ��������ѭ�����������Ԫʽ�������躯��
void quadBool(){ // bool���ͱ��ʽ
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.pop();
    string *p = new string("t" + to_string(jilu));
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(" + bo + "," + temp2 + "," + temp1 + "," + *p + ")";
    SYS[xuhao][0] = bo;
    SYS[xuhao][1] = temp2;
    SYS[xuhao][2] = temp1;
    SYS[xuhao++][3] = *p;
    s.push(*p); // ��bool���ʽ�Ľ������ջ��
}

void quadIf(){ // if���
    temp1 = s.top();
    s.pop();
    string temp = "";
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(if," + temp1 + ",_,"; // ��ʱs.pop����bool���ʽ�Ľ��
    quadruple1[xuhao1] = temp + "(if," + temp1 + ",_,";
    SYS[xuhao][0] = "if";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    if1 = xuhao++;
    if2 = xuhao1++;
}

void quadElse(){ // else���
    string temp = "";
    int i = xuhao + 1, j = xuhao1 + 1;
    quadruple[if1] += to_string(i) + ")";
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(el,_,_,";
    quadruple1[if2] += to_string(j) + ")";
    quadruple1[xuhao1] = temp + "(el,_,_,";
    SYS[xuhao][0] = "el";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    if1 = xuhao++;
    if2 = xuhao1++;
}

void quadIfEnd(){ // if������
    string temp = "";
    quadruple[if1] += to_string(xuhao) + ")";
    quadruple1[if2] += to_string(xuhao1++) + ")";
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(ie,_,_,_)";
    quadruple1[xuhao1] = temp + "(ie,_,_,_)";
    SYS[xuhao][0] = "ie";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadWhile(){ // while���
    string temp = "";
    while1 = xuhao;
    while3 = xuhao1;
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(wh,_,_,_)";
    quadruple1[xuhao1++] = temp + "(wh,_,_,_)";
    SYS[xuhao][0] = "wh";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadDoWhile(){ // do���
    while2 = xuhao;
    while4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(do," + temp1 + ",_,"; // bool�Ǹ����Ѿ���bool���ʽ�Ľ�����ȥ�ˣ���s.pop
    quadruple1[xuhao1++] = temp + "(do," + temp1 + ",_,";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadWhileEnd(){ // while������
    string temp = "";
    int i = xuhao + 1, j = while1 + 1, k = xuhao1 + 1, m = while3 + 1;
    quadruple[while2] += to_string(i) + ")";
    quadruple1[while4] += to_string(k) + ")";
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(we,_,_," + to_string(j) + ")";
    quadruple1[xuhao1++] = temp + "(we,_,_," + to_string(m) + ")";
    SYS[xuhao][0] = "we";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadFor(){ // for���
    string temp = "";
    for1 = xuhao;
    for3 = xuhao1;
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(for,_,_,_)";
    quadruple1[xuhao1++] = temp + "(for,_,_,_)";
    SYS[xuhao][0] = "for";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadDoFor(){ // do for���
    for2 = xuhao;
    for4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(do," + temp1 + ",_,"; // bool�Ǹ����Ѿ���bool���ʽ�Ľ�����ȥ�ˣ���s.pop
    quadruple1[xuhao1++] = temp + "(do," + temp1 + ",_,";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadForEnd(){ // for������
    string temp = "";
    int i = xuhao + 1, j = for1 + 1, k = xuhao1 + 1, m = for3 + 1;
    quadruple[for2] += to_string(i) + ")";
    quadruple1[for4] += to_string(k) + ")";
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(fe,_,_," + to_string(j) + ")";
    quadruple1[xuhao1++] = temp + "(fe,_,_," + to_string(m) + ")";
    SYS[xuhao][0] = "fe";
    SYS[xuhao][1] = "_";
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

/*  *****************     ������������������     *****************  */