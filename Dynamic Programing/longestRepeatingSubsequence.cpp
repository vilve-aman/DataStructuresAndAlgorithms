// #include <bits/stdc++.h>
// using namespace std;

// void printvector(vector<int> &v){
//     for (int i = 0; i < v.size(); i++)    {
//         if (v[i] == INT_MAX - 1)
//             cout << "IM"<< "  ";
//         else
//             cout << v[i] << "   ";
//     }
// }

// void printlcs(string a, string b, int n, int m){
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//     // base case
//     for (int i = 0; i < n + 1; i++)    {
//         for (int j = 0; j < m + 1; j++)        {
//             if (i == 0 || j == 0)            {
//                 dp[i][j] = 0;
//             }
//         }
//     }

//     // recursive case
//     for (int i = 1; i < n + 1; i++)    {
//         for (int j = 1; j < m + 1; j++)        {
//             if (a[i - 1] == b[j - 1] && i != j )            {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             }
//             else            {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     for (auto i : dp)    {
//         printvector(i);
//         cout << endl;
//     }

// }

// int main(){

//     cout << "hello world.😉\n";
//     string a;
//     cin >> a;
//     printlcs(a, a, a.length(), a.length());
//     return 0;
// }





// *****************************************************************************************************************************************************

// a slight variation in problem -----   ( above code will return lrs having overlaps )

//                                                         ababab ---- >     lrs return 4   ( abab - abab)
//                                                         whereas we must  have got 2 ( ab  -  ab )
// below code remove this  ambiguity in lrs ----------------------------------------------------------------------------------------------------------------------
// hint : here we used a bool array which keeps record of indexes which are counted inlongest repeating subsequence


#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    for (int i = 0; i < v.size(); i++)    {
        if (v[i] ==  - 1)
            cout << "N"<< "  ";
        else
            cout << v[i] << "  ";
    }
}

void printlcs(string a, string b, int n, int m){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    bool visited[n]={0};
    // base case
    for (int i = 0; i < n + 1; i++)    {
        for (int j = 0; j < m + 1; j++)        {
            if (i == 0 || j == 0 || i==j)            {
                dp[i][j] = 0;
            }
        }
    }

    // recursive case
    for (int i = 1; i < n + 1; i++)    {
        for (int j = 1 ; j < m + 1; j++)        {
            if (a[i - 1] == b[j - 1] && i != j && !visited[i-1] && !visited[j-1])            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                visited[i-1]=1;
                visited[j-1]=1;
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

}

int main(){

    cout << "hello world.😉\n";
    string a;
    cin >> a;
    printlcs(a, a, a.length(), a.length());
    return 0;
}