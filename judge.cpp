#include "judge.h"

int is_I(string a){             //是否为I(标识符)中的值,如果不是，则存入
    if(I.count(a))
        return I[a];
    else{
        Ik.push_back(a);
        return I[a]=Ik.size();
    }
}

int is_C1(string a){            //是否为C1(常整数)中的值,如果不是，则存入
    if(C1.count(a))
        return C1[a];
    else{
        C1k.push_back(a);
        return C1[a]=C1k.size();
    }
}

int is_C2(string a){      //是否为C2(常实数)中的值,如果不是，则存入
    double num=stod(a);
    stringstream ss;
    ss<<scientific<<num;
    a=ss.str();
    if(C2.count(a))
        return C2[a];
    else{
        C2k.push_back(a);
        return C2[a]=C2k.size();
    }
}

int is_CT(string a){            //是否为CT(字符常量)中的值,如果不是，则存入
    if(CT.count(a))
        return CT[a];
    else{
        CTk.push_back(a);
        return CT[a]=CTk.size();
    }
}

int is_ST(string a){            //是否为ST(字符串常量)中的值,如果不是，则存入
    if(ST.count(a))
        return ST[a];
    else{
        STk.push_back(a);
        return ST[a]=STk.size();
    }
}

int is_S(string a){            //是否为S(数组表)中的值,如果不是，则存入
    size_t p=a.find("["),q=a.find("]");
    string n=a.substr(0,p),l=a.substr(p+1,q-p-1);
    try{
        p=stoi(l,&q);
        if(I.count(n)||l.find_first_not_of(" ",q)!=string::npos)
            throw runtime_error("");
    }catch(exception e){
        return -1;
    }
    Array arr(n,l);
    if(S[arr])
        return S[arr];
    else{
        Sk.push_back(arr);
        return S[arr]=Sk.size();
    }
}