#include "judge.h"

int is_P(char a[], int d)       //是否为P中的值
{
    int flag;
    for (int i = 0; i < 30; i++)
    {
        flag = 0;
        for (int j = 0; j < d; j++)
        {
            if (a[j] != P[i][j])
                flag = 1;
        }
        if (flag == 0)
            return i + 1;
    }
    return 0;
}

int is_P1(char a)              //辅助函数
{
    for (int i = 0; i < 22; i++)
    {
        if (a == P1[i][0])
            return 1;
    }
    return 0;
}

int is_I(char a[])             //是否为I(标识符)中的值,如果不是，则存入
{
    int k, i, m = 0;
    if (II == 0)
    {
        for (k = 0; k < 20; k++)
            I[II][k] = a[k];
        II++;
        return II;
    }
    else
    {
        for (k = 0; k < II && m == 0; k++)
        {
            for (i = 0; i < 20; i++)
            {
                if (i == 19 && a[19] == I[k][19])
                    m = k + 1;
                else if (a[i] != I[k][i])
                    break;
            }
        }
        if (m == 0)
        {
            for (k = 0; k < 20; k++)
                I[II][k] = a[k];
            II++;
            return II;
        }
        else
            return m;
    }
}

int is_C1(char a[])            //是否为C1(常整数)中的值,如果不是，则存入
{
    int k, i, m = 0;
    if (CC1 == 0)
    {
        for (k = 0; k < 10; k++)
            C1[CC1][k] = a[k];
        CC1++;
        return CC1;
    }
    else
    {
        for (k = 0; k < CC1 && m == 0; k++)
        {
            for (i = 0; i < 10; i++)
            {
                if (i == 9 && a[9] == C1[k][9])
                    m = k + 1;
                else if (a[i] != C1[k][i])
                    break;
            }
        }
        if (m == 0)
        {
            for (k = 0; k < 10; k++)
                C1[CC1][k] = a[k];
            CC1++;
            return CC1;
        }
        else return m;
    }
}

int is_C2(char a[], int q)      //是否为C2(常实数)中的值,如果不是，则存入
{
    int k, i, m = 0;
    if (q == -1)                  //说明1：目前只对e后面的符号是'-'的数字进行变换，而'+'的话直接将原表达式进行录入。
    {                          //说明2：目前默认e-后面的数字为个数，为了节约内存空间而简易化操作。
        int num, x;//1.23e-3   0.00123
        for (k = 0; k < 10; k++)
        {
            if (a[k] == '-')
            {
                x = k - 2;
                k++;
                num = a[k] - '0';
            }
        }
        for (k = x + 1; k < 10; k++)
            a[k] = '0';
        for (k = x + num; a[k - num] != '.'; k--)
        {
            a[k] = a[k - num];
            a[k - num] = '0';
        }
        a[num + 1] = a[0];
        a[0] = '0';
        for (k = k + num; k < 10; k++)
            a[k] = '\0';

    }
    if (CC2 == 0)
    {
        for (k = 0; k < 10; k++)
            C2[CC2][k] = a[k];
        CC2++;
        return CC2;
    }
    else
    {
        for (k = 0; k < CC2 && m == 0; k++)
        {
            for (i = 0; i < 10; i++)
            {
                if (i == 9 && a[9] == C2[k][9])
                    m = k + 1;
                else if (a[i] != C2[k][i])
                    break;
            }
        }
        if (m == 0)
        {
            for (k = 0; k < 10; k++)
                C2[CC2][k] = a[k];
            CC2++;
            return CC2;
        }
        else return m;
    }
}

int is_CT(char a[])            //是否为CT(字符常量)中的值,如果不是，则存入
{
    int k, i, m = 0;
    if (CTT == 0)
    {
        for (k = 0; k < 10; k++)
            CT[CTT][k] = a[k];
        CTT++;
        return CTT;
    }
    else
    {
        for (k = 0; k < CTT && m == 0; k++)
        {
            for (i = 0; i < 10; i++)
            {
                if (i == 9 && a[9] == CT[k][9])
                    m = k + 1;
                else if (a[i] != CT[k][i])
                    break;
            }
        }
        if (m == 0)
        {
            for (k = 0; k < 10; k++)
                CT[CTT][k] = a[k];
            CTT++;
            return CTT;
        }
        else return m;
    }
}

int is_ST(char a[])            //是否为ST(字符串常量)中的值,如果不是，则存入
{
    int k, i, m = 0;
    if (STT == 0)
    {
        for (k = 0; k < 10; k++)
            ST[STT][k] = a[k];
        STT++;
        return STT;
    }
    else
    {
        for (k = 0; k < STT && m == 0; k++)
        {
            for (i = 0; i < 10; i++)
            {
                if (i == 9 && a[9] == ST[k][9])
                    m = k + 1;
                else if (a[i] != ST[k][i])
                    break;
            }
        }
        if (m == 0)
        {
            for (k = 0; k < 10; k++)
                ST[STT][k] = a[k];
            STT++;
            return STT;
        }
        else return m;
    }
}

int is_S(string a){            //是否为S(数组表)中的值,如果不是，则存入
    int p=a.find("["),q=a.find("]"),k, i, m = 0, j;
    string t=a.substr(0,p),ind=a.substr(p+1,q-p);
    Array arr(t,ind);
    if(S[arr])
        return S[arr];
    else{
        Sk.push_back(arr);
        return S[arr]=Sk.size();
    }
    
    if (SS == 0){
        for (k = 0; a[k] != '['; k++)
            S[SS][0][k] = a[k];
        k++;
        for (j = 0; a[k] != ']'; k++)
            S[SS][1][j] = a[k];
        SS++;
        return SS;
    }else{
        for (k = 0; k < SS && m == 0; k++){
            for (i = 0; a[i] != '['; i++){
                if (a[i] != S[k][0][i])
                    break;
            }
            if (a[i] == '['){
                m = k + 1;
                break;
            }
        }
        if (m == 0){
            for (k = 0; a[k] != '['; k++)
                S[SS][0][k] = a[k];
            k++;
            for (j = 0; a[k] != ']'; k++)
                S[SS][1][j] = a[k];
            SS++;
            return SS;
        }else 
            return m;
    }
}