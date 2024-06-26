#include "quad.h"

stack<string> s;
int cnt = 0;         // 用以记录生成第几个四元式
int tag = 0;          // 用以记录第几个中间变量的生成
string quadruple[100]; // 存取四元式字符串数组
string temp1, temp2;
string bo;                          // 存取bool的比较符
int if1;                       // 用于if四元式回填地址时使用的
int while1, while2; // 用于while四元式回填地址时使用的
int for1, for2;         // 用于for四元式回填地址时使用的

/*  *****************     语义分析函数定义开始      *****************  */
// 语法制导生成四元式
void quadPlus(){ // 加号生成四元式
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(+,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadMinus(){ // 减号生成四元式
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(-,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadMultiply(){ // 乘号生成四元式
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(*,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadDivide(){ /// 除号四元式
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(/,"+temp2+","+temp1+","+p+")";
    s.push(p);
}

void quadAssign(){ // 赋值语句生成四元式所需函数
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(=,"+temp1+",_,"+temp2+")";
}

// 以下为条件语句和循环语句生成四元式部分所需函数
void quadBool(){ // bool类型表达式
    temp1 = s.top();s.pop();
    temp2 = s.top();s.pop();
    string p="t" + to_string(tag);
    quadruple[cnt++]="QT["+to_string(cnt)+"]:("+bo+","+temp2+","+temp1+","+p+")";
    s.push(p); // 将bool表达式的结果存入栈中
}

void quadIf(){ // if语句
    temp1 = s.top();s.pop();  // 此时s.top就是bool表达式的结果
    quadruple[cnt]="QT["+to_string(cnt)+"]:(if,"+temp1+",_,"; 
    if1 = cnt++;
}

void quadElse(){ // else语句
    quadruple[if1]+=to_string(cnt+1)+")";
    quadruple[cnt]="QT["+to_string(cnt)+"]:(el,_,_,";
    if1 = cnt++;
}

void quadIfEnd(){ // if语句结束
    quadruple[if1]+=to_string(cnt)+")";
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(ie,_,_,_)";
}

void quadWhile(){ // while语句
    while1 = cnt;
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(wh,_,_,_)";
}

void quadDoWhile(){ // do语句
    while2 = cnt;
    temp1 = s.top();s.pop();// quadBool已经将bool表达式的结果存进去了，即s.top
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(do,"+temp1+",_,"; 
}

void quadWhileEnd(){ // while语句结束
    quadruple[while2]+=to_string(cnt+1)+")";
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(we,_,_,"+to_string(while1+1)+")";
}

void quadFor(){ // for语句
    for1 = cnt;
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(for,_,_,_)";
}

void quadDoFor(){ // do for语句
    for2 = cnt;
    temp1 = s.top();s.pop();//同quadDoWhile
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(do,"+temp1+",_,"; 
}

void quadForEnd(){ // for语句结束
    quadruple[for2]+=to_string(cnt+1)+")";
    quadruple[cnt++]="QT["+to_string(cnt)+"]:(fe,_,_,"+to_string(for1+1)+")";
}

/*  *****************     语义分析函数定义结束     *****************  */