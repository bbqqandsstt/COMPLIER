#include "quad.h"

stack<string> s;
int cnt = 0;         // ���Լ�¼���ɵڼ�����Ԫʽ
int tag = 0;          // ���Լ�¼�ڼ����м����������
string quadruple[100]; // ��ȡ��Ԫʽ�ַ�������
string temp1, temp2;
string bo;                          // ��ȡbool�ıȽϷ�
int if1, if2;                       // ����if��Ԫʽ�����ַʱʹ�õ�
int while1, while2, while3, while4; // ����while��Ԫʽ�����ַʱʹ�õ�
int for1, for2, for3, for4;         // ����for��Ԫʽ�����ַʱʹ�õ�

/*  *****************     ��������������忪ʼ      *****************  */
int cnt1 = 0;
string quadruple1[100];

// �﷨�Ƶ�������Ԫʽ
void quadPlus(){ // �Ӻ�������Ԫʽ
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(+,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadMinus(){ // ����������Ԫʽ
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(-,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadMultiply(){ // �˺�������Ԫʽ
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(*,"+temp2+","+temp1+","+p+")";
    quadruple1[cnt1++]="(*,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadDivide(){ /// ������Ԫʽ
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(/,"+temp2+","+temp1+","+p+")";
    quadruple1[cnt1++]="(/,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadAssign(){ // ��ֵ���������Ԫʽ���躯��
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(=,"+temp1+",_,"+temp2+")";
    quadruple1[cnt1++]="(=,"+temp1+",_,"+temp2+")";
}

// ����Ϊ��������ѭ�����������Ԫʽ�������躯��
void quadBool(){ // bool���ͱ��ʽ
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:("+bo+","+temp2+","+temp1+","+p+")";
    s.push(p); // ��bool���ʽ�Ľ������ջ��
}

void quadIf(){ // if���
    temp1 = s.top();s.pop();  // ��ʱs.top����bool���ʽ�Ľ��
    quadruple[cnt]="QT["+to_string(cnt)+"]:(if,"+temp1+",_,"; 
    quadruple1[cnt1]="(if,"+temp1+",_,";
    if1 = cnt++;
    if2 = cnt1++;
}

void quadElse(){ // else���
    quadruple[if1]+=to_string(cnt+1)+")";
    quadruple[cnt]="QT["+to_string(cnt)+"]:(el,_,_,";
    quadruple1[if2]+=to_string(cnt1+1)+")";
    quadruple1[cnt1]="(el,_,_,";
    if1 = cnt++;
    if2 = cnt1++;
}

void quadIfEnd(){ // if������
    quadruple[if1]+=to_string(cnt)+")";
    quadruple1[if2]+=to_string(cnt1++)+")";
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(ie,_,_,_)";
    quadruple1[cnt1]="(ie,_,_,_)";
}

void quadWhile(){ // while���
    while1 = cnt;
    while3 = cnt1;
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(wh,_,_,_)";
    quadruple1[cnt1++]="(wh,_,_,_)";
}

void quadDoWhile(){ // do���
    while2 = cnt;
    while4 = cnt1;
    temp1 = s.top();s.pop();// quadBool�Ѿ���bool���ʽ�Ľ�����ȥ�ˣ���s.top
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(do,"+temp1+",_,"; 
    quadruple1[cnt1++]="(do,"+temp1+",_,";
}

void quadWhileEnd(){ // while������
    quadruple[while2]+=to_string(cnt+1)+")";
    quadruple1[while4]+=to_string(cnt1+1)+")";
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(we,_,_,"+to_string(while1+1)+")";
    quadruple1[cnt1++]="(we,_,_,"+to_string(while3+1)+")";
}

void quadFor(){ // for���
    for1 = cnt;
    for3 = cnt1;
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(for,_,_,_)";
    quadruple1[cnt1++]="(for,_,_,_)";
}

void quadDoFor(){ // do for���
    for2 = cnt;
    for4 = cnt1;
    temp1 = s.top();s.pop();//ͬquadDoWhile
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(do,"+temp1+",_,"; 
    quadruple1[cnt1++]="(do,"+temp1+",_,";
}

void quadForEnd(){ // for������
    quadruple[for2]+=to_string(cnt+1)+")";
    quadruple1[for4]+=to_string(cnt1+1)+")";
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(fe,_,_,"+to_string(for1+1)+")";
    quadruple1[cnt1++]="(fe,_,_,"+to_string(for3+1)+")";
}

/*  *****************     ������������������     *****************  */