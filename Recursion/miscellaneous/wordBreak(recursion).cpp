// problem : https://practice.geeksforgeeks.org/problems/word-break-part-23249/1#

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> dp;

bool check(string s, vector<string> &dict){
    for (int i = 0; i < dict.size(); i++)    {
        if( s== dict[i]){
            return true;
        }
    }
    return false;    
}

bool wordBreak(string s, string temp, vector<string> &op, vector<string> &dict){

    // base case
    if (s.size() == 0)    {
        temp.pop_back();
        op.push_back(temp);
        return true;
    }

    // recursive case
    bool flag = 0;
    string checkString = "";
    string sf = temp;
    for (int i = 0; i < s.size(); i++)    {
        checkString += s[i];
        temp = sf;
        if (check(checkString, dict))        {
            s.erase(s.begin() + 0, s.begin() + i + 1);
            temp += checkString + " ";

            if (wordBreak(s, temp, op, dict))              flag = 1;
            else                                                                    flag = 0;
         
            s = checkString + s;            //          backtracking------------------------------------------------------------------------
        }
    }
    if (flag == 1)
        return true;
    return false;
}


int main(){
    cout << "hello world.😉\n";

    int n;
    vector<string> dict;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)    {
        cin >> s;
        dict.push_back(s);
    }
    cin >> s;

    string temp="";
    vector<string> op;
    cout<<endl<<wordBreak(s, temp, op, dict);

    for(auto i : op){
        cout<<"[";
        for(auto j: i){
            cout<<j;
        }
        cout<<"]"<<endl;
    }

    return 0;
}




