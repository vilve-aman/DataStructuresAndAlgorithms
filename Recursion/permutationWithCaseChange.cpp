#include <bits/stdc++.h>
using namespace std;

char caseChange(char c){
    if(isupper(c)){
        return(tolower(c));
    }
    else{
        return(toupper(c));
    }
} 

void permutationWithCaseChange ( string input , string output ){
    // base condition
        if(input.size()==0){
            cout<<output<<endl;
            return;
        }

    // normal condition

        string op1=output;
        string op2=output;

        op1.push_back(input[0]);                                //when selected as it is 
        op2.push_back(caseChange(input[0]));       //when selected  with case change

        input.erase(input.begin()+0);
        permutationWithCaseChange(input,op1);
        permutationWithCaseChange(input,op2);
}

int main(){
    cout<<"hello world.😉\n";

    string s ;
    cin>>s;
    permutationWithCaseChange(s , "" );

    return  0;
}
