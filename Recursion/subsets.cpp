#include <bits/stdc++.h>
using namespace std;

void subsets ( string input , string output ){
    // base condition
        if(input.size()==0){
            cout<<output<<endl;
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

    return  0;
}