#include <bits/stdc++.h>
using namespace std;

void subsets ( string input , string output ){
    // base condition
        if(input.size()==0){
            cout<<output<<endl;
            return;
        }

    // normal condition
        if (input.size()!=1 && output.size()!=0){

            string op1=output;
            string inp1="";
            subsets(inp1,op1);                              //  when not selected(x)

            string op2=output;
            op2.push_back(input[0]);
            input.erase(input.begin()+0);
            subsets(input,op2);                             //  when selected(^)
        }
        else{
            string op1=output;
            string op2=output;
            op1.push_back(input[0]);
            input.erase(input.begin()+0);
            subsets(input,op1);                              //  when selected(^)
            subsets(input,op2);                             //  when not selected(x)
        }
        
}

int main(){
    cout<<"hello world.😉\n";

    string s ;
    cin>>s;
    subsets(s,"");

    return  0;
}