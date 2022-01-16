// problem : minimum number of opertions(insert/delete) to convert ( string a ---> string b )

#include <bits/stdc++.h>
using namespace std;

void swapGreater(string &a,string &b){
    if(b.length()>a.length()){
        string temp=a;
        a=b;
        b=temp;
    }
}

int lcs (string a, string b, int n, int m){
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

    // base condition 
    for (int i = 0; i < n+1; i++)    {
        for (int j = 0; j < m+1 ; j++)        {
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }        
    }

    // recursive case 
    for (int i = 1; i < n+1; i++)    {
        for (int j = 1; j < m+1 ; j++)        {
            if(a[i-1]==b[j-1]){
                dp[i][j]= dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j]= max ( dp[i-1][j] , dp[i][j-1] );
            }
        }        
    }

    // cout<<"lcs : "<<dp[n][m]<<endl;
    return dp[n][m];
    
}

int main(){
    cout<<"hello world.😉\n";
    string a,b;
    cin>>a>>b;
    swapGreater(a, b);
    int lcsint=lcs(a, b, a.length(), b.length() );
    cout<<"deletions : "<< a.length()-lcsint<<endl;
    cout<<"insertions : "<< b.length()-lcsint;
    return  0;
}


// inputs tested
// abcdef
// acdfhi
// hello world.😉
// deletions : 2
// insertions : 2

// abdyef
// xabdy
// hello world.😉
// deletions : 2
// insertions : 1