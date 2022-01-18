// problem : minimum number of operations( either insertion or deletions ) required to make a string palindrome 

// observation : we wil always have to delete or insert same amount of characters to make a stirng palindrome
// for example : for string xabybx we must delete 'a' from string to make it palindrome on the other hand if we add 'a' in 
//                          the string then we can also obtain a palindrome string 


#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == INT_MAX - 1)
            cout << "IM"
                 << "  ";
        else
            cout << v[i] << "   ";
    }
}

int lps( string a , string b){
    int n=a.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    // base condition 
    for (int i = 0; i < n+1 ; i++)    {
        for (int j = 0; j < n+1; j++)        {
            if( i==0 || j==0 ){
                dp[i][j]=0;
            }
        }        
    }
    
    // recursive case 
    for (int i = 1; i < n+1 ; i++)    {
        for (int j = 1; j < n+1; j++)        {
            if( a[i-1]==b[j-1] ){
                dp[i][j]= dp[i-1][j-1] +1 ;
            }
            else{
                dp[i][j]= max ( dp[i-1][j] , dp[i][j-1] );
            }
        }        
    }

    for (auto i : dp)
    {
        printvector(i);
        cout << endl;
    }
    
    return dp[n][n];

}

int main(){
    cout<<"hello world.😉\n";
    string a,b;
    cin>>a;
    b=a;
    reverse(b.begin(), b.end());
    cout<<a.size()-lps(a, b);

    return  0;
}

// inputs tested 

// xabybx
// hello world.😉
// 0   0   0   0   0   0   0   
// 0   1   1   1   1   1   1   
// 0   1   1   1   1   2   2   
// 0   1   2   2   2   2   2   
// 0   1   2   3   3   3   3   
// 0   1   2   3   4   4   4   
// 0   1   2   3   4   4   5   
// 1