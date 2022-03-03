#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool > dp;

string keyCreate(string a, string b){
    string result="";
    result=a+"#"+b;
    return result;
}

bool ss(string a, string b){
    int n=a.size();
    // cout<<n<<" a: "<<a<<"\t b: "<<b<<endl;
    // base case 
    if(a.compare(b)==0 ){
        return true;
    }
    if(n<1 || (n==1 && a.compare(b)!=0) ){
        return false;
    }
    // recursive case 

    // memorization
    string key=keyCreate(a,b);
    if(dp.find(key) != dp.end()){
        return dp[key];
    }

    bool flag =0;
    for (int i = 0; i < n-1; i++)
    {
        if (
            ss( a.substr(0,i+1), b.substr(n-i-1 ,i+1) ) && ss(a.substr(i+1, n-i-1), b.substr(0,n-i-1 ) ) 
            ||
            ss( a.substr(0,i+1), b.substr(0,i+1) ) && ss( a.substr(i+1, n-i-1), b.substr(i+1, n-i-1) )
            )        
        {
            flag = 1;
            break;
        }
        
    }
    dp[key]=flag;                   //------------------------------------------memorization------------------------------------------------------------------------
    return flag;

}

int main(){
    cout<<"hello world.😉\n";
    string a,b;
    cin>>a>>b;
    cout<<"\n"<<ss(a,b);   
    return  0;
}

// inputs tested 
// great
// ategr
// output 
// hello world.😉
// 5 a: great	 b: ategr
// 1 a: g	 b: r
// 1 a: g	 b: a
// 2 a: gr	 b: gr
// 3 a: eat	 b: ate
// 1 a: e	 b: e
// 2 a: at	 b: at

// 1



// grea
// rage
// output 
// hello world.😉
// 4 a: grea	 b: rage
// 1 a: g	 b: e
// 1 a: g	 b: r
// 2 a: gr	 b: ge
// 1 a: g	 b: e
// 1 a: g	 b: g
// 1 a: r	 b: e
// 2 a: gr	 b: ra
// 1 a: g	 b: a
// 1 a: g	 b: r
// 3 a: gre	 b: age
// 1 a: g	 b: e
// 1 a: g	 b: a
// 2 a: gr	 b: ge
// 1 a: g	 b: e
// 1 a: g	 b: g
// 1 a: r	 b: e
// 2 a: gr	 b: ag
// 1 a: g	 b: g
// 1 a: r	 b: a
// 1 a: g	 b: a
// 3 a: gre	 b: rag
// 1 a: g	 b: g
// 2 a: re	 b: ra
// 1 a: r	 b: a
// 1 a: r	 b: r
// 1 a: e	 b: a
// 1 a: g	 b: r
// 2 a: gr	 b: ag
// 1 a: g	 b: g
// 1 a: r	 b: a
// 1 a: g	 b: a
// 2 a: gr	 b: ra
// 1 a: g	 b: a
// 1 a: g	 b: r

// 0