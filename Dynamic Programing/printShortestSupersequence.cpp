#include <bits/stdc++.h>
using namespace std;

void mapdp(string a, string b, vector<vector<int>> &dp)
{

    int i = dp.size();
    int j = dp[0].size();

    string op = "";

    while (i > 0 && j > 0)    {

        if (a[i - 1] == b[j - 1])        {
            op = a[i - 1] + op;
            i--;
            j--;
        }
        else        {
            if (dp[i][j - 1] > dp[i - 1][j])            {
                op = b[j - 1] + op;
                j--;
            }
            else            {
                op = a[i - 1] + op;
                i--;
            }
        }
    }

    while (i > 0)    {
        op = a[i - 1] + op;
        i--;
    }

    while (j > 0)    {
        op = b[j - 1] + op;
        j--;
    }

    cout<<endl<< op << endl;
}

void printvector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)    {
        if (v[i] == INT_MAX - 1)
            cout << "IM"<< "  ";
        else
            cout << v[i] << "   ";
    }
}

void printlcs(string a, string b, int n, int m){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // base case
    for (int i = 0; i < n + 1; i++)    {
        for (int j = 0; j < m + 1; j++)        {
            if (i == 0 || j == 0)            {
                dp[i][j] = 0;
            }
        }
    }

    // recursive case
    for (int i = 1; i < n + 1; i++)    {
        for (int j = 1; j < m + 1; j++)        {
            if (a[i - 1] == b[j - 1])            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (auto i : dp)    {
        printvector(i);
        cout << endl;
    }

    mapdp(a, b, dp);
}

int main(){

    cout << "hello world.😉\n";
    string a, b;
    cin >> a >> b;
    printlcs(a, b, a.length(), b.length());
    return 0;
}


// inputs tested 

// pappu
// pass
// hello world.😉
// 0   0   0   0   0   
// 0   1   1   1   1   
// 0   1   2   2   2   
// 0   1   2   2   2   
// 0   1   2   2   2   
// 0   1   2   2   2   

// passppu



// abcdef
// acdfhi
// hello world.😉
// 0   0   0   0   0   0   0   
// 0   1   1   1   1   1   1   
// 0   1   1   1   1   1   1   
// 0   1   2   2   2   2   2   
// 0   1   2   3   3   3   3   
// 0   1   2   3   3   3   3   
// 0   1   2   3   4   4   4   

// abcdefhi


// abdef
// xabdy
// hello world.😉
// 0   0   0   0   0   0   
// 0   0   1   1   1   1   
// 0   0   1   2   2   2   
// 0   0   1   2   3   3   
// 0   0   1   2   3   3   
// 0   0   1   2   3   3   

// xabdyef