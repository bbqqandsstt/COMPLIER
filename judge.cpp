#include "judge.h"

int is_I(string a){             //�Ƿ�ΪI(��ʶ��)�е�ֵ,������ǣ������
    if(I.count(a))
        return I[a];
    else{
        Ik.push_back(a);
        return I[a]=Ik.size();
    }
}

int is_C1(string a)            //�Ƿ�ΪC1(������)�е�ֵ,������ǣ������
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

int is_C2(string a, int q)      //�Ƿ�ΪC2(��ʵ��)�е�ֵ,������ǣ������
{
    int k, i, m = 0;
    if (q == -1)                  //˵��1��Ŀǰֻ��e����ķ�����'-'�����ֽ��б任����'+'�Ļ�ֱ�ӽ�ԭ���ʽ����¼�롣
    {                          //˵��2��ĿǰĬ��e-���������Ϊ������Ϊ�˽�Լ�ڴ�ռ�����׻�������
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

int is_CT(string a)            //�Ƿ�ΪCT(�ַ�����)�е�ֵ,������ǣ������
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

int is_ST(string a)            //�Ƿ�ΪST(�ַ�������)�е�ֵ,������ǣ������
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

int is_S(string a){            //�Ƿ�ΪS(�����)�е�ֵ,������ǣ������
    int p=a.find("["),q=a.find("]");
    string t=a.substr(0,p),ind=a.substr(p+1,q-p);
    Array arr(t,ind);
    if(S[arr])
        return S[arr];
    else{
        Sk.push_back(arr);
        return S[arr]=Sk.size();
    }
    /* 
    int k, i, m = 0, j;
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
    } */
}