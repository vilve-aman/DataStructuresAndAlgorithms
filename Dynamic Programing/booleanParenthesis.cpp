#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> dp;

string createKey(int i, int j, bool isTrue){
    string s;
    s+=to_string(j);
    s+=" ";
    s+=to_string(j);
    s+=" ";
    s+=to_string(isTrue) ;
 
    return s;
}

int eval(int &lt, int &lf, int &rt, int &rf, char &op, bool &isTrue){
    if(op=='|'){
        if(isTrue==true)    return      lt*rf + lf*rt + lt*rt ;
        else                           return      lf*rf ;
    }
    else if(op=='&'){
        if(isTrue==true)    return       lt*rt ;
        else                           return      lf*rf + lt*rf + lf*rt ;
    }
    else if(op=='^'){
        if(isTrue==true)    return      lt*rf + lf*rt ;
        else                           return      lf*rf + lt +rt ;
    }
}

int booleanParenthesis(string s, int i, int j, bool isTrue){
    // basae case 
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==true ){
            if( s[i]=='T' )     return 1;
            else                    return 0;
        }
        else{
            if( s[i]=='T' )     return 0;
            else                    return 1;
        }
    }
    
    // memorization
    string key = createKey(i,j,isTrue);
    if(dp.find(key)!=dp.end()){
        return dp[key];
    }

    // recursive case 
    int lt,lf,rt,rf;
    int ans=0;
    for (int k = i+1 ; k < j; k=k+2)    {
        lt=booleanParenthesis(s,i,k-1,true);
        lf=booleanParenthesis(s,i,k-1,false);
        rt=booleanParenthesis(s,k+1,j,true);
        rf=booleanParenthesis(s,k+1,j,false);

        int tempAns=eval(lt,lf,rt,rf,s[k],isTrue);
        ans+=tempAns;
        
    }
    dp[key]=ans;
    return ans;
}

int main(){
    cout<<"hello world.😉\n";
    string s;
    cin>>s;
    cout<<booleanParenthesis(s,0,s.size()-1,true)<<endl;
    for(auto i : dp){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    return  0;
}


// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// to do memorization 

// in global scope 
// unordered_map<string,int> dp;
// string createKey(int i, int j, bool isTrue){
//     string s;
//     s+=to_string(j);
//     s+=" ";
//     s+=to_string(j);
//     s+=" ";
//     s+=to_string(isTrue) ;
 
//     return s;
// }


// in booleanParenthesis 
    // string key = createKey(i,j,isTrue);
    // if(dp.find(key)!=dp.end()){
    //     return dp[key];
    // }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// inputs tested 
// T^F&T
// output 
// hello world.😉
// 2
// 2 2 0 -> 1
// 2 2 1 -> 1
// 4 4 0 -> 1
// 4 4 1 -> 2


// T&F|F^T
// output 
// hello world.😉
// 5
// 2 2 0 -> 1
// 6 6 1 -> 5
// 6 6 0 -> 1
// 2 2 1 -> 0
// 4 4 1 -> 0
// 4 4 0 -> 1