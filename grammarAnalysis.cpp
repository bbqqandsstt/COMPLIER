#include "grammarAnalysis.h"

int kk = 1;
int Next_w = 0;
char x1[2], x2[20];
int x3, x4;
char yy[20];
int y2 = 0;

/*  *****************     �﷨������ʼ      *****************  */
void count_data()                       //��������   x1Ϊ������֣�x2Ϊ����ֵ,x3Ϊtoken�ĵ�һ�����֣�x4Ϊtoken�ĵڶ�������
{
    int mm, i, j;
    x1[0] = formType[token[Next_w][0]][0];
    if (formType[token[Next_w][0]][1] != '\0')
        x1[1] = formType[token[Next_w][0]][1];
    else x1[1] = '\0';
    mm = token[Next_w][1] - 1;
    if (strcmp(x1, "H") == 0)
    {
        for (i = 0; H[mm][i] != '\0'; i++)
            x2[i] = H[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "K") == 0)
    {
        for (i = 0; K[mm][i] != '\0'; i++)
            x2[i] = K[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "P") == 0)
    {
        for (i = 0; P[mm][i] != '\0'; i++)
            x2[i] = P[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "I") == 0)
    {
        for (i = 0; I[mm][i] != '\0'; i++)
            x2[i] = I[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "C1") == 0)
    {
        for (i = 0; C1[mm][i] != '\0'; i++)
            x2[i] = C1[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "C2") == 0)
    {
        for (i = 0; C2[mm][i] != '\0'; i++)
            x2[i] = C2[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "CT") == 0)
    {
        for (i = 0; CT[mm][i] != '\0'; i++)
            x2[i] = CT[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "ST") == 0)
    {
        for (i = 0; ST[mm][i] != '\0'; i++)
            x2[i] = ST[mm][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    else if (strcmp(x1, "S") == 0)
    {
        for (i = 0; S[mm][0][i] != '\0'; i++)
            x2[i] = S[mm][0][i];
        for (j = i; j < 20; j++)
            x2[j] = '\0';
    }
    x3 = token[Next_w][0];
    x4 = token[Next_w][1];
}

void CX()          //����ʼ   <CX> �� {<WB>}<HD>{<HD>}
{
    count_data();
    while (strcmp(x2, "include") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x1, "H") == 0)
        {
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    while (strcmp(x2, "int") == 0 || strcmp(x2, "float") == 0 || strcmp(x2, "char") == 0 || strcmp(x2, "string") == 0)
    {
        WB();
        if (error == 1) return;
    }
    HD();
    if (error == 1) return;
    while (strcmp(x2, "void") == 0)
    {
        HD();
        if (error == 1) return;
    }
    if (Next_w < token_len) error = 1;
}

void WB()          //�ⲿ����   <WB> �� <BL>|<��BS��>[{<��,��><��BS��>}|<FG>]<��;��>|<��SZ��>[<SF>]<��;��>)
{
    int aa;
    aa = BL();
    if (aa == 0)return;
    if (strcmp(x1, "I") == 0)
    {
        for (int q = 0; q < II_Type; q++)
        {
            if (strcmp(I[q], x2) == 0)
            {
                error = 1;
                return;
            }
        }
        I_Type[II_Type] = aa;
        I_Type2[II_Type] = 1;
        II_Type++;
        Next_w++; count_data();
        if (strcmp(x2, "=") == 0)
        {
            Next_w--; count_data();
            s.push(x2);
            Next_w++; count_data();
            FG(aa);
            if (error == 1)return;
        }
        while (strcmp(x2, ",") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x1, "I") != 0)
            {
                error = 1;
                return;
            }
            I_Type[II_Type] = aa;
            I_Type2[II_Type] = 1;
            II_Type++;
            Next_w++; count_data();
            if (strcmp(x2, "=") == 0)
            {
                Next_w--; count_data();
                s.push(x2);
                Next_w++; count_data();
                FG(aa);
                if (error == 1)return;
            }
        }
        if (strcmp(x2, ";") == 0)
        {
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else if (strcmp(x1, "S") == 0)
    {
        int s_len1;
        for (int q = 0; q < SS_Type; q++)
        {
            if (strcmp(S[q][0], x2) == 0)
            {
                error = 1;
                return;
            }
        }
        S_Type[SS_Type] = aa;
        s_len1 = S[SS_Type][1][0] - '0';  //��ʱֻ�������鳤��Ϊ��λ�������
        SS_Type++;
        Next_w++; count_data();
        if (strcmp(x2, "=") == 0)
        {
            SF(aa, s_len1);
            if (error == 1)return;
        }
        if (strcmp(x2, ";") == 0)
        {
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }

}

int BL()           //��������   <BL> �� int | float | char |string
{
    if (strcmp(x2, "int") == 0)
    {
        Next_w++; count_data();
        return 1;
    }
    else if (strcmp(x2, "float") == 0)
    {
        Next_w++; count_data();
        return 2;
    }
    else if (strcmp(x2, "char") == 0)
    {
        Next_w++; count_data();
        return 3;
    }
    else if (strcmp(x2, "string") == 0)
    {
        Next_w++; count_data();
        return 4;
    }
    else
    {
        error = 1;
        return 0;
    }
}

void FG(int aa)    //��ֵ��ʽ   <FG> �� <��=��>(<��ZC��>|<SB>)
{
    if (strcmp(x2, "=") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x1, "CT") == 0 && aa == 3)
        {
            s.push(x2);
            Next_w++; count_data();
        }
        else if (strcmp(x1, "ST") == 0 && aa == 4)
        {
            s.push(x2);
            Next_w++; count_data();
        }
        else
        {
            SB(aa);
            if (error == 1) return;
        }
        QUATFUZHI();
    }
    else
    {
        error = 1;
        return;
    }
}

void SB(int aa)    //������ʽ <SB> �� <SD><SE>
{
    SD(aa);
    if (error == 1)return;
    SE(aa);
    if (error == 1)return;
}

void SE(int aa)    //������ʽ <SE> �� [(+|-)<SD><SE>]
{
    int cc;
    if (strcmp(x2, "+") == 0 || strcmp(x2, "-") == 0)
    {
        if (strcmp(x2, "+") == 0)
        {
            cc = 1;
        }
        else if (strcmp(x2, "-") == 0)
        {
            cc = 2;
        }
        Next_w++; count_data();
        SD(aa);
        if (error == 1)return;
        if (cc == 1)
        {
            QUATJIA();
            jilu++;
        }
        else if (cc == 2)
        {
            QUATJIAN();
            jilu++;
        }
        SE(aa);
        if (error == 1)return;
    }
    else
    {
        return;
    }
}

void SD(int aa)    //������ʽ <SD> �� <SV><SU>
{
    SV(aa);
    if (error == 1)return;
    SU(aa);
    if (error == 1)return;
}

void SU(int aa)    //������ʽ <SU> �� [(*|/)<SV><SU>]
{
    int cc;
    if (strcmp(x2, "*") == 0 || strcmp(x2, "/") == 0)
    {
        if (strcmp(x2, "*") == 0)
        {
            cc = 3;
        }
        else if (strcmp(x2, "/") == 0)
        {
            cc = 4;
        }
        Next_w++; count_data();
        SV(aa);
        if (error == 1)return;
        if (cc == 3)
        {
            QUATCHENGE();
            jilu++;
        }
        else if (cc == 4)
        {
            QUATCHU();
            jilu++;
        }
        SU(aa);
        if (error == 1)return;
    }
    else
    {
        return;
    }
}

void SV(int aa)    //������ʽ <SV> �� <��BS��> push(i)|<��SS��> push(i)|<��(��><SB><��)��>
{
    if (strcmp(x1, "I") == 0 && aa == I_Type[x4 - 1])
    {
        s.push(x2);
        Next_w++; count_data();
    }
    else if (strcmp(x1, "C1") == 0 && aa == 1)
    {
        s.push(x2);
        Next_w++; count_data();
    }
    else if (strcmp(x1, "C2") == 0 && aa == 2)
    {
        s.push(x2);
        Next_w++; count_data();
    }
    else if (strcmp(x2, "(") == 0)
    {
        Next_w++; count_data();
        SB(aa);
        if (error == 1)return;
        if (strcmp(x2, ")") == 0)
        {
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void SF(int aa, int bb)    //���鿪ʼ��ֵ��ʽ  <SF> �� <��=��><��{��>(<��SS��>{<��SS��>}|<��ZC��>{<��ZC��>})<��}��>
{
    int i = 0;
    if (strcmp(x2, "=") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x2, "{") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x1, "C1") == 0 && aa == 1)
            {
                i++;
                Next_w++; count_data();
                while (strcmp(x2, ",") == 0)
                {
                    Next_w++; count_data();
                    if (strcmp(x1, "C1") == 0)
                    {
                        i++;
                        Next_w++; count_data();
                    }
                    else
                    {
                        error = 1;
                        return;
                    }
                }
            }
            else if (strcmp(x1, "C2") == 0 && aa == 2)
            {
                i++;
                Next_w++; count_data();
                while (strcmp(x2, ",") == 0)
                {
                    Next_w++; count_data();
                    if (strcmp(x1, "C2") == 0)
                    {
                        i++;
                        Next_w++; count_data();
                    }
                    else
                    {
                        error = 1;
                        return;
                    }
                }
            }
            else if (strcmp(x1, "CT") == 0 && aa == 3)
            {
                i++;
                Next_w++; count_data();
                while (strcmp(x2, ",") == 0)
                {
                    Next_w++; count_data();
                    if (strcmp(x1, "CT") == 0)
                    {
                        i++;
                        Next_w++; count_data();
                    }
                    else
                    {
                        error = 1;
                        return;
                    }
                }
            }
            else if (strcmp(x1, "ST") == 0 && aa == 4)
            {
                i++;
                Next_w++; count_data();
                while (strcmp(x2, ",") == 0)
                {
                    Next_w++; count_data();
                    if (strcmp(x1, "ST") == 0)
                    {
                        i++;
                        Next_w++; count_data();
                    }
                    else
                    {
                        error = 1;
                        return;
                    }
                }
            }
            else
            {
                error = 1;
                return;
            }
            if (i > bb)
            {
                error = 1;
                return;
            }
            if (strcmp(x2, "}") == 0)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void HD()          //��������   <HD> �� <void><ZF><'{'><YG>{<YG>}<'}'>
{
    if (strcmp(x2, "void") == 0)
    {
        Next_w++; count_data();
        ZF();
        if (error == 1)return;
        if (strcmp(x2, "{") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x2, "}") == 0)
            {
                Next_w++; count_data();
                return;
            }
            YG();
            if (error == 1)return;
            while (strcmp(x2, "}") != 0)
            {
                YG();
                if (error == 1)return;
            }
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void ZF()          //ֱ��˵���� <ZF> �� <��BS��><��(��>[<CL>]<��)��>
{
    if (strcmp(x1, "I") == 0)
    {
        I_Type[II_Type] = 5;
        I_Type2[II_Type] = 0;
        II_Type++;
        Next_w++; count_data();
        if (strcmp(x2, "(") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x2, "int") == 0 || strcmp(x2, "float") == 0 || strcmp(x2, "char") == 0 || strcmp(x2, "string") == 0)
            {
                CL();
                if (error == 1)return;
            }
            if (strcmp(x2, ")") == 0)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void CL()          //�����б�   <CL> �� <BL><��BS��>{<��,��><BL><��BS��>}
{
    int aa;
    aa = BL();
    if (strcmp(x1, "I") == 0)
    {
        I_Type[II_Type] = aa;
        I_Type2[II_Type] = 2;
        II_Type++;
        Next_w++; count_data();
        while (strcmp(x2, ",") == 0)
        {
            Next_w++; count_data();
            aa = BL();
            if (error == 1)return;
            if (strcmp(x1, "I") == 0)
            {
                I_Type[II_Type] = aa;
                I_Type2[II_Type] = 2;
                II_Type++;
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void YG()          //���       <YG> �� <WB>|<BY><��;��>|<XY>|<XH>
{
    if (strcmp(x2, "int") == 0 || strcmp(x2, "float") == 0 || strcmp(x2, "char") == 0 || strcmp(x2, "string") == 0)
    {
        WB();
        if (error == 1)return;
    }
    else if (strcmp(x2, "scanf") == 0 || strcmp(x2, "printf") == 0 || strcmp(x1, "I") == 0 || strcmp(x1, "S") == 0)
    {
        BY();
        if (error == 1)return;
        if (strcmp(x2, ";") == 0)
        {
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else if (strcmp(x2, "if") == 0)
    {
        XY();
        if (error == 1)return;
    }
    else if (strcmp(x2, "for") == 0 || strcmp(x2, "while") == 0)
    {
        XH();
        if (error == 1)return;
    }
    else
    {
        error = 1;
        return;
    }
}

void BY()          //���ʽ��� <BY> �� <scanf><��(��><RG><��)��>|<printf><��(��><CG><��)��>|<FZ>
{
    if (strcmp(x2, "scanf") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x2, "(") == 0)
        {
            Next_w++; count_data();
            RG();
            if (error == 1)return;
            if (strcmp(x2, ")") == 0)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else if (strcmp(x2, "printf") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x2, "(") == 0)
        {
            Next_w++; count_data();
            CG();
            if (error == 1)return;
            if (strcmp(x2, ")") == 0)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        FZ();
        if (error == 1)return;
    }
}

void RG()          //�����ʽ   <RG> �� <������><GF><������><��,��>(<��&��><��BS��>|<��SZ��>)
{
    int aa;
    if (strcmp(x2, "\"") == 0)
    {
        Next_w++; count_data();
        aa = GF();
        if (error == 1)return;
        if (strcmp(x2, "\"") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x2, ",") == 0)
            {
                Next_w++; count_data();
                if (strcmp(x2, "&") == 0)
                {
                    Next_w++; count_data();
                    if (strcmp(x1, "I") != 0)
                    {
                        error = 1;
                        return;
                    }
                    if (aa == I_Type[x4 - 1])
                    {
                        Next_w++; count_data();
                    }
                    else
                    {
                        error = 1;
                        return;
                    }
                }
                else if (strcmp(x1, "S") == 0)
                {
                    if (aa == S_Type[x4 - 1])
                    {
                        Next_w++; count_data();
                    }
                    else
                    {
                        error = 1;
                        return;
                    }
                }
                else
                {
                    error = 1;
                    return;
                }
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void CG()          //�����ʽ   <CG> �� <������><GF><������><��,��><��BS��>|<��ZC��>
{
    int aa;
    if (strcmp(x2, "\"") == 0)
    {
        Next_w++; count_data();
        aa = GF();
        if (error == 1)return;
        if (strcmp(x2, "\"") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x2, ",") == 0)
            {
                Next_w++; count_data();
                if (aa == I_Type[x4 - 1])
                {
                    Next_w++; count_data();
                }
                else
                {
                    error = 1;
                    return;
                }
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else if (strcmp(x1, "ST") == 0)
    {
        Next_w++; count_data();
    }
    else
    {
        error = 1;
        return;
    }
}

int GF()           //��ʽ����   <GF> �� %d|%f|%c|%s
{
    if (strcmp(x2, "%d") == 0)
    {
        Next_w++; count_data();
        return 1;
    }
    else if (strcmp(x2, "%f") == 0)
    {
        Next_w++; count_data();
        return 2;
    }
    else if (strcmp(x2, "%c") == 0)
    {
        Next_w++; count_data();
        return 3;
    }
    else if (strcmp(x2, "%s") == 0)
    {
        Next_w++; count_data();
        return 4;
    }
    else error = 1;
    return 0;
}

void FZ()          //��ֵ���ʽ <FZ> �� <��BS��>(<FG>|<��(��>[<DG>]<��)��>)|<��SZ��><��[��>(<��BS��>|<��SS��>)<��]��><FG>
{
    int aa;
    if (strcmp(x1, "I") == 0)
    {
        s.push(x2);
        aa = I_Type[x4 - 1];
        Next_w++; count_data();
        if (strcmp(x2, "(") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x1, "I") == 0 || strcmp(x1, "C1") == 0 || strcmp(x1, "C2") == 0 || strcmp(x1, "CT") == 0 || strcmp(x1, "ST") == 0)
            {
                DG();
                if (error == 1)return;
            }
            if (strcmp(x2, ")") == 0)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            FG(aa);
            if (error == 1)return;
        }
    }
    else if (strcmp(x1, "S") == 0)
    {
        aa = S_Type[x4 - 1];
        Next_w++; count_data();
        if (strcmp(x2, "[") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x1, "I") == 0)
            {
                Next_w++; count_data();
            }
            else if (strcmp(x1, "C1") == 0)    //C1<�������󳤶�(��δ�ж�)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
            if (strcmp(x2, "]") == 0)
            {
                Next_w++; count_data();
                FG(aa);
                if (error == 1)return;
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void DG()          //���ø�ʽ  <DG> �� (<��BS��>|<��SS��>|<��ZC��>){<��,��>(<��BS��>|<��SS��>|<��ZC��>)}  ��������ʽ������Ӧ������ͬ��δʵ�֣�
{
    if (strcmp(x1, "I") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x1, "C1") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x1, "C2") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x1, "CT") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x1, "ST") == 0)
    {
        Next_w++; count_data();
    }
    else
    {
        error = 1;
        return;
    }
    while (strcmp(x2, ",") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x1, "I") == 0)
        {
            Next_w++; count_data();
        }
        else if (strcmp(x1, "C1") == 0)
        {
            Next_w++; count_data();
        }
        else if (strcmp(x1, "C2") == 0)
        {
            Next_w++; count_data();
        }
        else if (strcmp(x1, "CT") == 0)
        {
            Next_w++; count_data();
        }
        else if (strcmp(x1, "ST") == 0)
        {
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
}

void XY()          //ѡ�����  <XY> �� <if><��(��><��BS��><PG><��)��><XG>[<else><XG>]
{
    int aa;
    if (strcmp(x2, "if") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x2, "(") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x1, "I") == 0)
            {
                s.push(x2);
                aa = I_Type[x4 - 1];
                Next_w++; count_data();
                PG(aa);
                if (error == 1)return;
                if (strcmp(x2, ")") == 0)
                {

                    Next_w++; count_data();
                    QUATIF();
                    XG();
                    if (error == 1)return;
                    if (strcmp(x2, "else") == 0)
                    {

                        Next_w++; count_data();
                        QUATELSE();
                        XG();
                        if (error == 1)return;
                    }
                }
                else
                {
                    error = 1;
                    return;
                }
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
        QUATIFEND();
    }
    else
    {
        error = 1;
        return;
    }
}

void XG()          //ѡ������ʽ  <XG> ��<'{'><YG>{<YG>}<'}'>|<YG>
{
    if (strcmp(x2, "{") == 0)
    {
        Next_w++; count_data();
        YG();
        if (error == 1)return;
        while (strcmp(x2, "}") != 0)
        {
            YG();
            if (error == 1)return;
        }
        Next_w++; count_data();
    }
    else
    {
        YG();
        if (error == 1)return;
    }
}

void PG(int aa)    //�жϸ�ʽ   <PG> �� <PF>(<��BS��>|<��SS��>)
{
    int aa1;
    if (strcmp(x2, ">") == 0 || strcmp(x2, ">=") == 0 || strcmp(x2, "<") == 0 || strcmp(x2, "<=") == 0 || strcmp(x2, "==") == 0)
    {
        bo = x2;
        PF();
        if (error == 1)return;
        if (strcmp(x1, "I") == 0)
        {
            s.push(x2);
            aa1 = I_Type[x4 - 1];

            Next_w++; count_data();
            if (aa1 != aa)
            {
                error = 1;
                return;
            }
        }
        else if (strcmp(x1, "C1") == 0 && aa == 1)
        {
            s.push(x2);
            Next_w++; count_data();
        }
        else if (strcmp(x1, "C2") == 0 && aa == 2)
        {
            s.push(x2);
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
        QUATBOOL();
        jilu++;
    }
    else
    {
        error = 1;
        return;
    }
}

void PF()          //�жϷ���    <PF> �� >|>=|<|<=|==
{
    if (strcmp(x2, ">") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x2, ">=") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x2, "<") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x2, "<=") == 0)
    {
        Next_w++; count_data();
    }
    else if (strcmp(x2, "==") == 0)
    {
        Next_w++; count_data();
    }
    else
    {
        error = 1;
        return;
    }
}

void XH()      //ѭ�����   <XH> �� <while><��(��><��BS��><PG><��)'><XG>|<for><��(��>[<��BS��><FG>]<��;��>[<��BS��><PG>]<��;��>[<BD>]<��)��><XG>
{
    int aa;
    if (strcmp(x2, "while") == 0)
    {
        QUATWHILE();
        Next_w++; count_data();
        if (strcmp(x2, "(") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x1, "I") == 0)
            {
                s.push(x2);
                aa = I_Type[x4 - 1];
                Next_w++; count_data();
                PG(aa);
                if (error == 1)return;
                if (strcmp(x2, ")") == 0)
                {
                    Next_w++; count_data();
                    QUATDO();
                    XG();
                    QUATWHILEEND();
                    if (error == 1)return;
                }
                else
                {
                    error = 1;
                    return;
                }
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else if (strcmp(x2, "for") == 0)
    {
        Next_w++; count_data();
        if (strcmp(x2, "(") == 0)
        {
            Next_w++; count_data();
            if (strcmp(x1, "I") == 0)
            {
                s.push(x2);
                aa = I_Type[x4 - 1];
                Next_w++; count_data();
                FG(aa);
                if (error == 1)return;
            }
            if (strcmp(x2, ";") == 0)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
            QUATFOR();
            if (strcmp(x1, "I") == 0)
            {
                s.push(x2);
                aa = I_Type[x4 - 1];
                Next_w++; count_data();
                PG(aa);
                if (error == 1)return;
            }
            if (strcmp(x2, ";") == 0)
            {
                Next_w++; count_data();
            }
            else
            {
                error = 1;
                return;
            }
            if (strcmp(x1, "I") == 0 || strcmp(x2, "++") == 0 || strcmp(x2, "--") == 0)
            {
                BD();
                if (error == 1)return;
            }
            if (strcmp(x2, ")") == 0)
            {
                Next_w++; count_data();
                QUATDOFOR();
                XG();
                if (y2 == 1)
                {
                    s.push(yy);
                    s.push(yy);
                    s.push("1");
                    QUATJIA();
                    jilu++;
                    QUATFUZHI();
                    y2 = 0;
                }
                if (y2 == 2)
                {
                    s.push(yy);
                    s.push(yy);
                    s.push("1");
                    QUATJIAN();
                    jilu++;
                    QUATFUZHI();
                    y2 = 0;
                }
                QUATFOREND();
                if (error == 1)return;
            }
            else
            {
                error = 1;
                return;
            }
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }
}

void BD()      //�仯���ʽ <BD> �� <��BS��>(<��++��>|<��--��>)|(<��--��>|<��++��>)<��BS��>
{
    if (strcmp(x1, "I") == 0 && I_Type[x4 - 1] == 1)
    {
        strcpy(yy, x2);
        Next_w++; count_data();
        if (strcmp(x2, "++") == 0)
        {
            y2 = 1;
            Next_w++; count_data();
        }
        else if (strcmp(x2, "--") == 0)
        {
            y2 = 2;
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else if (strcmp(x2, "++") == 0)
    {
        y2 = 1;
        Next_w++; count_data();
        if (strcmp(x1, "I") == 0 && I_Type[x4 - 1] == 1)
        {
            strcpy(yy, x2);
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else if (strcmp(x2, "--") == 0)
    {
        y2 = 2;
        Next_w++; count_data();
        if (strcmp(x1, "I") == 0 && I_Type[x4 - 1] == 1)
        {
            strcpy(yy, x2);
            Next_w++; count_data();
        }
        else
        {
            error = 1;
            return;
        }
    }
    else
    {
        error = 1;
        return;
    }

}

/*  *****************     �﷨��������      *****************  */