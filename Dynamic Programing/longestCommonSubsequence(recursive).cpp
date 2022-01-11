#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string x, string y, int n,  int m){
    // base condition 
    if (n==0 || m==0 ){
        return 0;
    }

    // recursive case 
    if( x[n-1] == y[m-1] ){
        return 1 + longestCommonSubsequence(x,y,n-1,m-1);
    }
    else{
        return max( longestCommonSubsequence(x,y,n-1,m) , longestCommonSubsequence(x,y,n,m-1) );
    }

}

int main(){
    cout<<"hello world.😉\n";
    string x,y;
    cin>>x>>y;

    cout<<longestCommonSubsequence(x,y,x.length(),y.length());

    return  0;
}