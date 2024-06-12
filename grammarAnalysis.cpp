#include "grammarAnalysis.h"

int Next_w = 0,x3, x4,y2 = 0;
string x1, x2,yy;

/*  *****************     语法分析开始      *****************  */
void count_data(){                       //辅助函数   x1为表的名字，x2为具体值,x3为token的第一个数字，x4为token的第二个数字
    if(Next_w>=token.size())
        return ;
    tie(x3,x4)=token[Next_w];
    int mm=x4-1, i, j;
    x1 = formType[x3];
    if (x1=="H")
        x2= Hk[mm];
    else if (x1=="K")
        x2= Kk[mm];
    else if (x1=="P")
        x2= Pk[mm];
    else if (x1=="I")
        x2= Ik[mm];
    else if (x1=="C1")
        x2= C1k[mm];
    else if (x1=="C2")
        x2= C2k[mm];
    else if (x1=="CT")
        x2= CTk[mm];
    else if (x1=="ST")
        x2= STk[mm];
    else if (x1=="S")
        x2= Sk[mm].name;
}

void CX(){          //程序开始   <CX> → {<WB>}<HD>{<HD>}
    count_data();
    while (x2=="include"){
        Next_w++; count_data();
        if (x1=="H"){
            Next_w++; count_data();
        }else{
            error = 1;
            return;
        }
    }
    while (x2=="int"||x2=="float"||x2=="char"||x2=="string"){
        WB();
        if (error) 
            return;
    }
    HD();
    if (error) 
        return;
    while (x2=="void"){
        HD();
        if (error) 
            return;
    }
    if (Next_w < token.size()) 
        error = 1;
}

void WB(){          //外部声明   <WB> → <BL>|<"BS">[{<','><"BS">}|<FG>]<';'>|<"SZ">[<SF>]<';'>)
    int aa= BL();
    if (!aa)
        return;
    if (x1=="I"){
        for (int q = 0; q <I_Type.size(); q++)
            if (Ik[q]==x2){
                error = 1;
                return;
            }
        I_Type.push_back({aa,1});
        Next_w++; count_data();
        if (x2=="="){
            Next_w--; count_data();
            s.push(x2);
            Next_w++; count_data();
            FG(aa);
            if (error)
                return;
        }
        while (x2==","){
            Next_w++; count_data();
            if (x1!="I"){
                error = 1;
                return;
            }
            I_Type.push_back({aa,1});
            Next_w++; count_data();
            if (x2=="="){
                Next_w--; count_data();
                s.push(x2);
                Next_w++; count_data();
                FG(aa);
                if (error)
                    return;
            }
        }
        if (x2==";"){
            Next_w++; count_data();
        }else{
            error = 1;
            return;
        }
    }
    else if (x1=="S"){
        int s_len1;
        for (int q = 0; q < S_Type.size(); q++)
            if (Sk[q].name==x2){
                error = 1;
                return;
            }
        s_len1 = stoi(Sk[S_Type.size()].len);
        S_Type.push_back(aa);
        Next_w++; count_data();
        if (x2=="="){
            SF(aa, s_len1);
            if (error)
                return;
        }
        if (x2==";"){
            Next_w++; count_data();
        }else{
            error = 1;
            return;
        }
    }else{
        error = 1;
        return;
    }
}

int BL(){           //变量声明   <BL> → int | float | char |string
    if (x2=="int"){
        Next_w++; count_data();
        return 1;
    }else if (x2=="float"){
        Next_w++; count_data();
        return 2;
    }else if (x2=="char"){
        Next_w++; count_data();
        return 3;
    }else if (x2=="string"){
        Next_w++; count_data();
        return 4;
    }else{
        error = 1;
        return 0;
    }
}

void FG(int aa){    //赋值格式   <FG> → <'='>(<"ZC">|<SB>)
    if (x2=="="){
        Next_w++; count_data();
        if (x1=="CT" && aa == 3){
            s.push(x2);
            Next_w++; count_data();
        }else if (x1=="ST" && aa == 4){
            s.push(x2);
            Next_w++; count_data();
        }else{
            SB(aa);
            if (error) 
                return;
        }
        quadAssign();
    }else
        error = 1;
}

void SB(int aa){    //算符表达式 <SB> → <SD><SE>
    SD(aa);
    if (error)
        return;
    SE(aa);
    if (error)
        return;
}

void SE(int aa){    //算符表达式 <SE> → [(+|-)<SD><SE>]
    int cc;
    if (x2=="+"||x2=="-"){
        cc=1+(x2=="-");
        Next_w++; count_data();
        SD(aa);
        if (error)
            return;
        if (cc-1){
            quadMinus();
            jilu++;
        }else{
            quadPlus();
            jilu++;
        }
        SE(aa);
        if (error)
            return;
    }else
        return;
}

void SD(int aa){    //算符表达式 <SD> → <SV><SU>
    SV(aa);
    if (error)
        return;
    SU(aa);
    if (error)
        return;
}

void SU(int aa){    //算符表达式 <SU> → [(*|/)<SV><SU>]
    int cc;
    if (x2=="*"||x2=="/"){
        cc=3+(x2=="/");
        Next_w++; count_data();
        SV(aa);
        if (error)
            return;
        if (cc-3){
            quadDivide();
            jilu++;
        }else{
            quadMultiply();
            jilu++;
        }
        SU(aa);
        if (error)
            return;
    }else
        return;
}

void SV(int aa){    //算符表达式 <SV> → <"BS"> push(i)|<"SS"> push(i)|<'('><SB><')'>
    if (x1=="I" && aa == I_Type[x4 - 1].first){
        s.push(x2);
        Next_w++; count_data();
    }else if (x1=="C1" && aa == 1){
        s.push(x2);
        Next_w++; count_data();
    }else if (x1=="C2" && aa == 2){
        s.push(x2);
        Next_w++; count_data();
    }else if (x2=="("){
        Next_w++; count_data();
        SB(aa);
        if (error)
            return;
        if (x2==")"){
            Next_w++; count_data();
        }else{
            error = 1;
            return;
        }
    }else{
        error = 1;
        return;
    }
}

void SF(int aa, int bb){    //数组开始赋值格式  <SF> → <'='><'{'>(<"SS">{<"SS">}|<"ZC">{<"ZC">})<'}'>
    int i = 0;
    if (x2=="="){
        Next_w++; count_data();
        if (x2=="{"){
            Next_w++; count_data();
            if (x1=="C1" && aa == 1){
                i++;
                Next_w++; count_data();
                while (x2==","){
                    Next_w++; count_data();
                    if (x1=="C1"){
                        i++;
                        Next_w++; count_data();
                    }else{
                        error = 1;
                        return;
                    }
                }
            }else if (x1=="C2"&& aa == 2){
                i++;
                Next_w++; count_data();
                while (x2==","){
                    Next_w++; count_data();
                    if (x1=="C2"){
                        i++;
                        Next_w++; count_data();
                    }else{
                        error = 1;
                        return;
                    }
                }
            }else if (x1=="CT" && aa == 3){
                i++;
                Next_w++; count_data();
                while (x2==","){
                    Next_w++; count_data();
                    if (x1=="CT"){
                        i++;
                        Next_w++; count_data();
                    }else{
                        error = 1;
                        return;
                    }
                }
            }else if (x1=="ST" && aa == 4){
                i++;
                Next_w++; count_data();
                while (x2==","){
                    Next_w++; count_data();
                    if (x1=="ST"){
                        i++;
                        Next_w++; count_data();
                    }else{
                        error = 1;
                        return;
                    }
                }
            }else{
                error = 1;
                return;
            }
            if (i > bb){
                error = 1;
                return;
            }
            if (x2=="}"){
                Next_w++; count_data();
            }else{
                error = 1;
                return;
            }
        }else{
            error = 1;
            return;
        }
    }else{
        error = 1;
        return;
    }
}

void HD(){          //函数定义   <HD> → <void><ZF><'{'><YG>{<YG>}<'}'>
    if (x2=="void"){
        Next_w++; count_data();
        ZF();
        if (error)
            return;
        if (x2=="{"){
            Next_w++; count_data();
            if (x2=="}"){
                Next_w++; count_data();
                return;
            }
            YG();
            if (error)
                return;
            while (x2!="}"){
                YG();
                if (error)
                    return;
            }
            Next_w++; count_data();
        }else{
            error = 1;
            return;
        }
    }else{
        error = 1;
        return;
    }
}

void ZF(){          //直接说明符 <ZF> → <"BS"><'('>[<CL>]<')'>
    if (x1=="I"){
        I_Type.push_back({5,0});
        Next_w++; count_data();
        if (x2=="("){
            Next_w++; count_data();
            if (x2=="int"||x2=="float"||x2=="char"||x2=="string"){
                CL();
                if (error)
                    return;
            }
            if (x2==")"){
                Next_w++; count_data();
            }else{
                error = 1;
                return;
            }
        }else{
            error = 1;
            return;
        }
    }else{
        error = 1;
        return;
    }
}

void CL(){          //参数列表   <CL> → <BL><"BS">{<','><BL><"BS">}
    int aa= BL();
    if (x1=="I"){
        I_Type.push_back({aa,2});
        Next_w++; count_data();
        while (x2==","){
            Next_w++; count_data();
            aa = BL();
            if (error)
                return;
            if (x1=="I"){
                I_Type.push_back({aa,2});
                Next_w++; count_data();
            }else{
                error = 1;
                return;
            }
        }
    }else{
        error = 1;
        return;
    }
}

void YG(){          //语句       <YG> → <WB>|<BY><';'>|<XY>|<XH>
    if (x2=="int"||x2=="float"||x2=="char"||x2=="string")
        WB();
    else if (x2=="scanf"||x2=="printf"||x1=="I"||x1=="S"){
        BY();
        if (error)
            return;
        if (x2==";"){
            Next_w++; count_data();
        }else
            error = 1;
    }else if (x2=="if")
        XY();
    else if (x2=="for"||x2=="while")
        XH();
    else
        error = 1;
}

void BY(){          //表达式语句 <BY> → <scanf><'('><RG><')'>|<printf><'('><CG><')'>|<FZ>
    if (x2=="scanf"){
        Next_w++; count_data();
        if (x2=="("){
            Next_w++; count_data();
            RG();
            if (error)
                return;
            if (x2==")"){
                Next_w++; count_data();
            }else
                error = 1;
        }else
            error = 1;
    }else if (x2=="printf"){
        Next_w++; count_data();
        if (x2=="("){
            Next_w++; count_data();
            CG();
            if (error)
                return;
            if (x2==")"){
                Next_w++; count_data();
            }else
                error = 1;
        }else
            error = 1;
    }else
        FZ();
}

void RG(){          //输入格式   <RG> → <GF><','>(<'&'><"BS">|<"SZ">)
    int aa;
    if (x1=="ST"){
        aa = GF();
        if (error)
            return;
        if (x2==","){
            Next_w++; count_data();
            if (x2=="&"){
                Next_w++; count_data();
                if (x1!="I"){
                    error = 1;
                    return;
                }
                if (aa == I_Type[x4 - 1].first){
                    Next_w++; count_data();
                }else
                    error = 1;
            }else if (x1=="S"){
                if (aa == S_Type[x4 - 1]){
                    Next_w++; count_data();
                }else
                    error = 1;
            }else
                error = 1;
        }else
            error = 1;
    }else
        error = 1;
}

void CG(){          //输出格式   <CG> → <'\"'><GF><'\"'><','><"BS">|<"ZC">
    int aa;
    if (x2.find("\"")!=string::npos){
        aa = GF();
        if (error)
            return;
        if (x2==","){
            Next_w++; count_data();
            if (aa == I_Type[x4 - 1].first){
                Next_w++; count_data();
            }else
                error = 1;
        }else
            error = 1;
    }else if (x1=="ST"){
        Next_w++; count_data();
    }else
        error = 1;
}

int GF(){           //格式符号   <GF> → </">%d|%f|%c|%s</">
    if (x2.find("%d")!=string::npos){
        Next_w++; count_data();
        return 1;
    }else if (x2.find("%f")!=string::npos){
        Next_w++; count_data();
        return 2;
    }else if (x2.find("%c")!=string::npos){
        Next_w++; count_data();
        return 3;
    }else if (x2.find("%s")!=string::npos){
        Next_w++; count_data();
        return 4;
    }else 
        error = 1;
    return 0;
}

void FZ(){          //赋值表达式 <FZ> → <"BS">(<FG>|<'('>[<DG>]<')'>)|<"SZ"><'['>(<"BS">|<"SS">)<']'><FG>
    int aa;
    if (x1=="I"){
        s.push(x2);
        aa = I_Type[x4 - 1].first;
        Next_w++; count_data();
        if (x2=="("){
            Next_w++; count_data();
            if (x1=="I"||x1=="C1"||x1=="C2"||x1=="CT"||x1=="ST"){
                DG();
                if (error)
                    return;
            }
            if (x2==")"){
                Next_w++; count_data();
            }else
                error = 1;
        }else
            FG(aa);
    }else if (x1=="S"){
        aa = S_Type[x4 - 1];
        Next_w++; count_data();
        if (x2=="["){
            Next_w++; count_data();
            if (x1=="I"){
                Next_w++; count_data();
            }else if (x1=="C1"){    //TODO: C1<数组的最大长度(还未判断)
                Next_w++; count_data();
            }else{
                error = 1;
                return;
            }
            if (x2=="]"){
                Next_w++; count_data();
                FG(aa);
            }else
                error = 1;
        }else
            error = 1;
    }else
        error = 1;
}

//TODO
void DG(){         //调用格式  <DG> → (<"BS">|<"SS">|<"ZC">){<','>(<"BS">|<"SS">|<"ZC">)}  函数中形式参数对应类型相同（未实现）
    if (x1=="I"){
        Next_w++; count_data();
        
    }else if (x1=="C1"){
        Next_w++; count_data();
        
    }else if (x1=="C2"){
        Next_w++; count_data();
        
    }else if (x1=="CT"){
        Next_w++; count_data();
        
    }else if (x1=="ST"){
        Next_w++; count_data();
        
    }else{
        error = 1;
        return;
    }
    while (x2==","){
        Next_w++; count_data();
        if (x1=="I"){
            Next_w++; count_data();
            
        }else if (x1=="C1"){
            Next_w++; count_data();
            
        }else if (x1=="C2"){
            Next_w++; count_data();
            
        }else if (x1=="CT"){
            Next_w++; count_data();
            
        }else if (x1=="ST"){
            Next_w++; count_data();
            
        }else{
            error = 1;
            return;
        }
    }
}

void XY(){          //选择语句  <XY> → <if><'('><"BS"><PG><')'><XG>[<else><XG>]
    int aa;
    if (x2=="if"){
        Next_w++; count_data();
        if (x2=="("){
            Next_w++; count_data();
            if (x1=="I"){
                s.push(x2);
                aa = I_Type[x4 - 1].first;
                Next_w++; count_data();
                PG(aa);
                if (error)
                    return;
                if (x2==")"){
                    Next_w++; count_data();
                    quadIf();
                    XG();
                    if (error)
                        return;
                    if (x2=="else"){
                        Next_w++; count_data();
                        quadElse();
                        XG();
                        if (error)
                            return;
                    }
                }else{
                    error = 1;
                    return;
                }
            }else{
                error = 1;
                return;
            }
        }else{
            error = 1;
            return;
        }
        quadIfEnd();
    }else
        error = 1;
}

void XG(){          //选择语句格式  <XG> →<'{'><YG>{<YG>}<'}'>|<YG>
    if (x2=="{"){
        Next_w++; count_data();
        YG();
        if (error)
            return;
        while (x2!="}"){
            YG();
            if (error)
                return;
        }
        Next_w++; count_data();
    }else
        YG();
}

void PG(int aa){    //判断格式   <PG> → <PF>(<"BS">|<"SS">)
    int aa1;
    if (x2==">"||x2==">="||x2=="<"||x2=="<="||x2=="=="){
        bo = x2;
        PF();
        if (error)
            return;
        if (x1=="I"){
            s.push(x2);
            aa1 = I_Type[x4 - 1].first;
            Next_w++; count_data();
            if (aa1-aa){
                error = 1;
                return;
            }
        }else if (x1=="C1" && aa == 1){
            s.push(x2);
            Next_w++; count_data();
        }else if (x1=="C2" && aa == 2){
            s.push(x2);
            Next_w++; count_data();
        }else{
            error = 1;
            return;
        }
        quadBool();
        jilu++;
    }else
        error = 1;
}

void PF(){          //判断符号    <PF> → >|>=|<|<=|==
    if (x2==">"||x2==">="||x2=="<"||x2=="<="||x2=="=="){
        Next_w++; count_data();
    }else
        error = 1;
}

void XH(){      //循环语句   <XH> → <while><'('><"BS"><PG><')'><XG>|<for><'('>[<"BS"><FG>]<';'>[<"BS"><PG>]<';'>[<BD>]<')'><XG>
    int aa;
    if (x2=="while"){
        quadWhile();
        Next_w++; count_data();
        if (x2=="("){
            Next_w++; count_data();
            if (x1=="I"){
                s.push(x2);
                aa = I_Type[x4 - 1].first;
                Next_w++; count_data();
                PG(aa);
                if (error)
                    return;
                if (x2==")"){
                    Next_w++; count_data();
                    quadDoWhile();
                    XG();
                    quadWhileEnd();
                }else
                    error = 1;
            }else
                error = 1;
        }else
            error = 1;
    }else if (x2=="for"){
        Next_w++; count_data();
        if (x2=="("){
            Next_w++; count_data();
            if (x1=="I"){
                s.push(x2);
                aa = I_Type[x4 - 1].first;
                Next_w++; count_data();
                FG(aa);
                if (error)
                    return;
            }
            if (x2==";"){
                Next_w++; count_data();
            }else{
                error = 1;
                return;
            }
            quadFor();
            if (x1=="I"){
                s.push(x2);
                aa = I_Type[x4 - 1].first;
                Next_w++; count_data();
                PG(aa);
                if (error)
                    return;
            }
            if (x2==";"){
                Next_w++; count_data();
            }else{
                error = 1;
                return;
            }
            if (x1=="I"||x2=="++"||x2=="--"){
                BD();
                if (error)
                    return;
            }
            if (x2==")"){
                Next_w++; count_data();
                quadDoFor();
                XG();
                if (y2 == 1){
                    s.push(yy);
                    s.push(yy);
                    s.push("1");
                    quadPlus();
                    jilu++;
                    quadAssign();
                    y2 = 0;
                }
                if (y2 == 2){
                    s.push(yy);
                    s.push(yy);
                    s.push("1");
                    quadMinus();
                    jilu++;
                    quadAssign();
                    y2 = 0;
                }
                quadForEnd();
            }else
                error = 1;
        }else
            error = 1;
    }else
        error = 1;
}

void BD(){      //变化表达式 <BD> → <"BS">(<"++">|<"--">)|(<"--">|<"++">)<"BS">
    if (x1=="I" && I_Type[x4 - 1].first == 1){
        yy=x2;
        Next_w++; count_data();
        if (x2=="++"){
            y2 = 1;
            Next_w++; count_data();
        }else if (x2=="--"){
            y2 = 2;
            Next_w++; count_data();
        }else
            error = 1;
    }else if (x2=="++"){
        y2 = 1;
        Next_w++; count_data();
        if (x1=="I" && I_Type[x4 - 1].first == 1){
            yy=x2;
            Next_w++; count_data();
        }else
            error = 1;
    }else if (x2=="--"){
        y2 = 2;
        Next_w++; count_data();
        if (x1=="I" && I_Type[x4 - 1].first == 1){
            yy=x2;
            Next_w++; count_data();
        }else
            error = 1;
    }else
        error = 1;
}

/*  *****************     语法分析结束      *****************  */