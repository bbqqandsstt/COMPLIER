#include "wordAnalysis.h"


/*  *****************     词法分析开始      *****************  */
void wordAnalyse()                  //词法分析函数
{
    char a[30];               
    int j, k, m;
    int t = 0;                 
    for (int i = 0; i < len;)
    {
        if (Input[i] == '#')
        {
            j = 0;
            i++;
            while (is_s(Input[i]))
            {
                a[j] = Input[i];
                i++;
                j++;
            }
            for (int k = j; k < 20; k++)
                a[k] = '\0';
            m = is_K(a);
            if (m)
            {
                token[token_len][0] = 1;
                token[token_len][1] = m;
                token_len++;
            }
            else
            {
                error = 1;
                return;
            }
            while (Input[i]!='<')
            {
                i++;
            }
            j = 0;
            i++;
            while (Input[i] != '>')
            {
                a[j] = Input[i];
                i++;
                j++;
            }
            a[j] = '\0';
            i++;
            m = is_T(a);
            if (m)
            {
                token[token_len][0] = 8;
                token[token_len][1] = m;
                token_len++;
            }
            else
            {
                error = 1;
                return;
            }
           
        }
        else if (is_s(Input[i]) || Input[i] == '_')   //如果首字符是字母或下划线
        {
            j = 0;
            a[j] = Input[i];
            i++;
            j++;
            while (is_s(Input[i]) || is_d(Input[i]) || Input[i] == '_')
            {
                a[j] = Input[i];
                i++;
                j++;
            }
            if (Input[i] == '[')
            {
                a[j] = Input[i];
                i++;
                j++;
                while (is_d(Input[i]) || is_s(Input[i]) || Input[i] == '_')
                {
                    a[j] = Input[i];
                    i++;
                    j++;
                }
                if (Input[i] == ']')
                {
                    a[j] = Input[i];
                    i++;
                    j++;
                }
                for (int k = j; k < 20; k++)
                    a[k] = '\0';
                m = is_S(a);
                token[token_len][0] = 9;
                token[token_len][1] = m;
                token_len++;
            }
            else
            {
                for (int k = j; k < 20; k++)
                    a[k] = '\0';
                m = is_K(a);
                if (m)
                {
                    token[token_len][0] = 1;
                    token[token_len][1] = m;
                    token_len++;
                }
                else
                {
                        m = is_I(a);
                        token[token_len][0] = 3;
                        token[token_len][1] = m;
                        token_len++;
                }
            }
        }
        else if (is_d(Input[i]))        //如果首字符是数字
        {
            int q = 0;
            j = 0;
            a[j] = Input[i];
            i++;
            j++;
            while ((a[0] != '0' || (a[0] == '0' && Input[i] == '.') || (a[0] == '0' && a[1] == '.')) && (is_d(Input[i]) ||
                Input[i] == '.' || Input[i] == 'e' || (Input[i] == '-' && Input[i - 1] == 'e') ||
                (Input[i] == '+' && Input[i - 1] == 'e')))
            {
                if (Input[i] == '.') q = 1;
                if (Input[i] == 'e' && Input[i + 1] == '-') q = -1;
                a[j] = Input[i];
                i++;
                j++;
            }
            if (is_s(Input[i]) == 1)
            {
                error = 1;
                return;
            }
            for (k = j; k < 10; k++)
                a[k] = '\0';
            if (q == 0)
            {
                m = is_C1(a);
                token[token_len][0] = 4;
                token[token_len][1] = m;
                token_len++;
            }
            else
            {
                m = is_C2(a, q);
                token[token_len][0] = 5;
                token[token_len][1] = m;
                token_len++;
            }
        }
        else if (t == 0 && (Input[i] == '\'' || (Input[i] == '"' && Input[i - 1] != '(' && Input[i + 1] != ')') || (Input[i] == '"' && Input[i - 1] == '(' && Input[i + 1] != '%')))
        {
            j = 0;
            a[j] = Input[i];
            i++;
            j++;
            while (a[0] == '"' && Input[i] != '"')
            {
                a[j] = Input[i];
                i++;
                j++;
            }
            if (a[0] == '"')
            {
                a[j] = Input[i];
                i++;
                j++;
            }
            if (a[0] == '\'')
            {
                a[j] = Input[i];
                i++;
                j++;
                if (Input[i] != '\'')
                {
                    error = 1;
                    return;
                }
                else
                {
                    a[j] = Input[i];
                    i++;
                    j++;
                }
            }
            for (int k = j; k < 10; k++)
                a[k] = '\0';
            if (a[0] == '\'')
            {
                m = is_CT(a);
                token[token_len][0] = 6;
                token[token_len][1] = m;
                token_len++;
            }
            else if (a[0] == '"')
            {
                m = is_ST(a);
                token[token_len][0] = 7;
                token[token_len][1] = m;
                token_len++;
            }
        }
        else if (is_P1(Input[i]))       //如果首字符是界符
        {
            j = 0;
            int u = 0;
            if (t == 0 && Input[i] == '"')
            {
                t = 1;
                u = 1;
            }
            if (u == 0 && t == 1 && Input[i] == '"')t = 0;
            a[j] = Input[i];
            i++;
            j++;
            if ((a[0] == '=' && Input[i] == '=') || (a[0] == '<' && Input[i] == '=') || (a[0] == '>' && Input[i] == '=')
                || (a[0] == '+' && Input[i] == '=')|| (a[0] == '-' && Input[i] == '=')|| (a[0] == '*' && Input[i] == '=')
                ||(a[0] == '/' && Input[i] == '=')|| (a[0] == '%' && Input[i] == '=')
                || (a[0] == '+' && Input[i] == '+') || (a[0] == '-' && Input[i] == '-') || (a[0] == '%' && Input[i] == 'd')
                || (a[0] == '%' && Input[i] == 'f') || (a[0] == '%' && Input[i] == 'c') || (a[0] == '%' && Input[i] == 's'))
            {
                a[j] = Input[i];
                i++;
                j++;
            }
            for (int k = j; k < 10; k++)
                a[k] = '\0';
            m = is_P(a, j);
            token[token_len][0] = 2;
            token[token_len][1] = m;
            token_len++;
        }
        else if (Input[i] == ' ')i++;
        else                           //如果以上都不是
        {
            error = 1;
            return;
        }
    }
}
/*  *****************     词法分析结束      *****************  */