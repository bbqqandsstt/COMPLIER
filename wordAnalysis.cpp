#include "wordAnalysis.h"

/*  *****************     词法分析开始      *****************  */
void wordAnalyse(){                  //词法分析函数
    string a;               
    for (int i = 0,m; i <Input.length();){
        a.clear();
        for(;Input[i] == ' ';i++);
        if (Input[i] == '#'){
            i++;
            for(;isalpha(Input[i]);i++)
                a.push_back(Input[i]);
            m = K[a];
            if (m)
                token.push_back({1,m});
            else{
                error = 1;
                return;
            }
            i=Input.find("<")+1;
            a.clear();
            for(;Input[i] != '>';i++)
                a.push_back(Input[i]); 
            i++;
            m = H[a];
            if (m)
                token.push_back({8,m});
            else{
                error = 1;
                return;
            }
        }else if(isalpha(Input[i]) || Input[i] == '_'){   //如果首字符是字母或下划线
            a.push_back(Input[i++]);
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
                m=is_S(a);
                if(m+1)
                    token.push_back({9,m});
                else{
                    error = 1;
                    return;
                }
            }else{
                m = K[a];
                if (m)
                    token.push_back({1,m});
                else
                    token.push_back({3,is_I(a)});
            }
        }else if (isdigit(Input[i])){        //如果首字符是数字
            int fl=0,x=1;
            a.push_back(Input[i++]);
            for(;isdigit(Input[i]);i++)
                a+=Input[i];
            if(Input[i]=='.'){
                a+=Input[i++];
                for(;isdigit(Input[i]);i++)
                    a+=Input[i],x=0;
                if(Input[i]=='e'){
                    if(x){
                        error=1;
                        return ;
                    }
                    a+=Input[i++];x=1;
                    if(Input[i]=='-'||Input[i]=='+')
                        a+=Input[i++];
                    for(;isdigit(Input[i]);i++)
                        a+=Input[i],x=0;
                    if(x){
                        error=1;
                        return ;
                    }
                }
                fl++;
            }else if(Input[i]=='e'){
                a+=Input[i++];
                if(Input[i]=='-'||Input[i]=='+')
                    a+=Input[i++];
                for(;isdigit(Input[i]);i++)
                    a+=Input[i],x=0;
                if(x){
                    error=1;
                    return ;
                }
                fl++;
            }
            if (fl)
                token.push_back({5,is_C2(a)});
            else
                token.push_back({4,is_C1(a)});
        }else if(Input[i] == '\'' || Input[i] == '\"'){
            a.push_back(Input[i++]);
            for(;a[0] == '\"' && Input[i] != '\"';i++){
                if(i>=Input.length()){
                    error=1;
                    return ;
                }
                a+=Input[i];
            }
            if (a[0] == '\"')
                a+=Input[i++];
            if (a[0] == '\''){
                a+=Input[i++];
                if (Input[i] != '\''){
                    error = 1;
                    return;
                }else
                    a+=Input[i++];
            }
            if (a[0] == '\'')
                token.push_back({6,is_CT(a)});
            else if (a[0] == '\"')
                token.push_back({7,is_ST(a)});
        }else{       //如果首字符是界符
            a.push_back(Input[i++]);
            if(P.count(a+Input[i]))
                m = P[a+Input[i++]];
            else
                m=P[a];
            if(m)
                token.push_back({2,m});
            else{                           //如果以上都不是
                error = 1;
                return;
            }
        }
    }
}
/*  *****************     词法分析结束      *****************  */