#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void printvec(vector <string> v){
    for(string s : v){
        cout<<s<<endl;
    }
}

void subsets ( string input , string output ){
    // base condition
        if(input.size()==0){
            v.push_back(output);
            return;
        }

    // normal condition
        string op1=output;
        string op2=output;
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        subsets(input,op1);
        subsets(input,op2);
}

int main(){
    cout<<"hello world.😉\n";

    string s ;
    cin>>s;
    subsets(s,"");
    sort(v.begin(), v.end());
    printvec(v);

    return  0;
}




// problem hint
// if  asked  for  Lexicographical subsets then the problem is of vector sorting (i.e: sort(v.begin(), v.end()) )
 