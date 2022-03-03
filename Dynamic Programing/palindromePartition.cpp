#include <bits/stdc++.h>
using namespace std;

bool isPalindrome( string s, int i, int j ){
    while(i<j){
        if( s[i]!=s[j] )    return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartition(string s, int i, int j){
    // base case 
    if(i>=j){
        return 0;
    }
    if( isPalindrome(s,i,j) ){
        return 0;
    }
    // recursive csae 
    int ans=INT_MAX;
    for (int k = i; k < j; k++)    {
        int tempAns=palindromePartition(s,i,k) + palindromePartition(s,k+1,j) + 1 ;
        ans = min(ans,tempAns);
    }
    
    return ans;
}



int main(){
    cout<<"hello world.😉\n";
    string s;
    cin>>s;

    cout<<palindromePartition(s,0,s.size()-1);
    return  0;
}




// in memorization

// in main()
// vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
// cout<<palindromePartition(s,0,s.size()-1,dp);

// int palindromePartition(string s, int i, int j, vector<vector<int>> &dp){
//     // base case 
//     if(i>=j){
//         return 0;
//     }
//     if( isPalindrome(s,i,j) ){
//         return 0;
//     }

//     // recursive csae 
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int ans=INT_MAX;
//     for (int k = i; k < j; k++)    {
//         int tempAns=palindromePartition(s,i,k,dp) + palindromePartition(s,k+1,j,dp) + 1 ;
//         ans = min(ans,tempAns);
//     }
    
//     dp[i][j]=ans;
//     return ans;
// }




// inputs tested 
// nitik
// output
// hello world.😉
// 2

// nitin
// output 
// hello world.😉
// 0

// aman
// output
// hello world.😉
// 1

