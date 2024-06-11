#include "quad.h"

stack<string> s;
int xuhao = 0;         // 用以记录生成第几个四元式
int jilu = 0;          // 用以记录第几个中间变量的生成
string quadruple[100]; // 存取四元式字符串数组
string temp1, temp2;
string bo;                          // 存取bool的比较符，要插动作
int if1, if2;                       // 用于if四元式回填地址时使用的
int while1, while2, while3, while4; // 用于while四元式回填地址时使用的
int for1, for2, for3, for4;         // 用于for四元式回填地址时使用的

/*  *****************     语义分析函数定义开始      *****************  */
int xuhao1 = 0;
string quadruple1[100];

string SYS[50][4];     // 数组四元式
string SYS_new[50][4]; // 优化过的数组四元式
int SYS_new_len = 0;   // 优化过后的数组四元式的长度

string youhua_quan[50][10], youhua_caozuo[50][4];
int youhua_quan_j_len[50], quan = 0, caozuo = 0;

// 语法制导生成四元式
void quadPlus(){ // 加号生成四元式
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

void quadMinus(){ // 减号生成四元式
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

void quadMultiply(){ // 乘号生成四元式
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

void quadDivide(){ /// 除号四元式
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

void quadAssign(){ // 赋值语句生成四元式所需函数
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

// 以下为条件语句和循环语句生成四元式部分所需函数
void quadBool(){ // bool类型表达式
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
    s.push(*p); // 将bool表达式的结果存入栈中
}

void quadIf(){ // if语句
    temp1 = s.top();
    s.pop();
    string temp = "";
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(if," + temp1 + ",_,"; // 此时s.pop就是bool表达式的结果
    quadruple1[xuhao1] = temp + "(if," + temp1 + ",_,";
    SYS[xuhao][0] = "if";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao][3] = "_";
    if1 = xuhao++;
    if2 = xuhao1++;
}

void quadElse(){ // else语句
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

void quadIfEnd(){ // if语句结束
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

void quadWhile(){ // while语句
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

void quadDoWhile(){ // do语句
    while2 = xuhao;
    while4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(do," + temp1 + ",_,"; // bool那个区已经将bool表达式的结果存进去了，即s.pop
    quadruple1[xuhao1++] = temp + "(do," + temp1 + ",_,";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadWhileEnd(){ // while语句结束
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

void quadFor(){ // for语句
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

void quadDoFor(){ // do for语句
    for2 = xuhao;
    for4 = xuhao1;
    string temp = "";
    temp1 = s.top();
    s.pop();
    quadruple[xuhao] = "QT[" + to_string(xuhao) + "]:(do," + temp1 + ",_,"; // bool那个区已经将bool表达式的结果存进去了，即s.pop
    quadruple1[xuhao1++] = temp + "(do," + temp1 + ",_,";
    SYS[xuhao][0] = "do";
    SYS[xuhao][1] = temp1;
    SYS[xuhao][2] = "_";
    SYS[xuhao++][3] = "_";
}

void quadForEnd(){ // for语句结束
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

/*  *****************     语义分析函数定义结束     *****************  */