#include "wordAnalysis.h"


/*  *****************     词法分析开始      *****************  */
void wordAnalyse(){                  //词法分析函数
    string a;               
    int j, k, m,t = 0;                 
    for (int i = 0; i < len;){
        if (Input[i] == ' ')
            i++;
        else if (Input[i] == '#'){
            i++;
            for(;isalpha(Input[i]);i++)
                a.push_back(Input[i]);
            m = K[a];
            if (m){
                token[token_len][0] = 1;
                token[token_len++][1] = m;
            }else{
                error = 1;
                return;
            }
            for(;Input[i]!='<';i++);
            a.clear();
            i++;
            for(;Input[i] != '>';i++)
                a.push_back(Input[i]); 
            i++;
            m = H[a];
            if (m){
                token[token_len][0] = 8;
                token[token_len][1] = m;
                token_len++;
            }else{
                error = 1;
                return;
            }
        }else if(isalpha(Input[i]) || Input[i] == '_'){   //如果首字符是字母或下划线
            a = string(1,Input[i++]);
            for(;isalnum(Input[i]) || Input[i] == '_';i++)
                a+=Input[i];  
            if (Input[i] == '['){
                a+=Input[i++];
                for(;isdigit(Input[i]);i++)
                    a+=Input[i];
                if (Input[i] == ']')
                    a+=Input[i++];
                else{
                    error=1;
                    return ;
                }
                m = is_S(a);
                token[token_len][0] = 9;
                token[token_len++][1] = m;
            }else{
                m = K[a];
                if (m){
                    token[token_len][0] = 1;
                    token[token_len++][1] = m;
                }else{
                        m = is_I(a);
                        token[token_len][0] = 3;
                        token[token_len][1] = m;
                        token_len++;
                }
            }
        }else if (isdigit(Input[i])){        //如果首字符是数字
            int q = 0;
            a = string(1,Input[i++]);
            for(;(a[0] != '0' || (a[0] == '0' && Input[i] == '.') || (a[0] == '0' && a[1] == '.')) && 
                (isdigit(Input[i]) ||Input[i] == '.' || Input[i] == 'e' || (Input[i - 1] == 'e'&&(Input[i] == '-' ||Input[i] == '+')));i++)
            {
                if (Input[i] == '.') 
                    q = 1;
                if (Input[i] == 'e' && Input[i + 1] == '-') 
                    q = -1;
                a+= Input[i];
            }
            if (isalpha(Input[i])){
                error = 1;
                return;
            }
            if (!q){
                m = is_C1(a);
                token[token_len][0] = 4;
                token[token_len++][1] = m;
            }else{
                m = is_C2(a, q);
                token[token_len][0] = 5;
                token[token_len++][1] = m;
            }
        }else if (!t&& (Input[i] == '\'' || (Input[i] == '"' && Input[i - 1] != '(' && Input[i + 1] != ')') || (Input[i] == '"' && Input[i - 1] == '(' && Input[i + 1] != '%'))){
            a = string(1,Input[i++]);
            for(;a[0] == '"' && Input[i] != '"';i++)
                a+=Input[i];
            if (a[0] == '"')
                a+=Input[i++];
            if (a[0] == '\''){
                a+=Input[i++];
                if (Input[i] != '\''){
                    error = 1;
                    return;
                }else
                    a+=Input[i++];
            }
            if (a[0] == '\''){
                m = is_CT(a);
                token[token_len][0] = 6;
                token[token_len++][1] = m;
            }else if (a[0] == '"'){
                m = is_ST(a);
                token[token_len][0] = 7;
                token[token_len++][1] = m;
            }
        }
        else{       //如果首字符是界符
            a = string(1,Input[i++]);
            if(P.count(a+Input[i]))
                m = P[a+Input[i++]];
            else
                m=P[a];
            if(m){
                token[token_len][0] = 2;
                token[token_len++][1] = m;
            }else{                           //如果以上都不是
                error = 1;
                return;
            }
        }
    }
}
/*  *****************     词法分析结束      *****************  */