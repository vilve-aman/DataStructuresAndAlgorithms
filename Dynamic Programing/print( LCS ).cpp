#include <bits/stdc++.h>
using namespace std;

void mapdp(string a, string b, vector<vector<int>> &dp)
{

    int n = dp.size();
    int m = dp[0].size();

    string op = "";
    int i=n,j=m;
    while( i>=0 && j>=0 ){
            
        if (i == 0 || j == 0)    {
            break;
        }
        else    {
            if (a[i - 1] == b[j - 1])        {
                op = a[i - 1] + op;
                i--;
                j--;
            }
            else        {
                if (dp[i][j - 1] > dp[i - 1][j])            {
                    j--;
                }
                else            {
                    i--;
                }
            }
        }
    }

    cout<<endl<<op<<endl;

}

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

void printlcs(string a, string b, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // base case
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    // recursive case
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (auto i : dp)
    {
        printvector(i);
        cout << endl;
    }

    mapdp(a,b,dp);
}

int main()
{
    cout << "hello world.😉\n";
    string a, b;
    cin >> a >> b;
    printlcs(a, b, a.length(), b.length());
    return 0;
}