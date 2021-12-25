#include <bits/stdc++.h>
using namespace std;

void subsets ( string input , string output , int n){
    // base condition
        if(input.size()==0){
            cout<<output<<endl;
            return;
        }

    // for  bypassing first letter 
        if (input.size()==n){
            output.push_back(input[0]);
            input.erase(input.begin()+0);
            subsets(input,output,n);
            return;
        }
        
    // normal condition

        string op1=output;
        string op2=output;

        op1.push_back(input[0]);        //when space not selected (x)
        op2.push_back('_');                 //when space selected (^)
        op2.push_back(input[0]);       //when space selected (^) 

        input.erase(input.begin()+0);
        subsets(input,op1,n);
        subsets(input,op2,n);
}

int main(){
    cout<<"hello world.😉\n";

    string s ;
    cin>>s;
    subsets(s,"",s.size());

    return  0;
}


// sample input 
// abcd
// sample output
// abcd
// abc_d
// ab_cd
// ab_c_d
// a_bcd
// a_bc_d
// a_b_cd
// a_b_c_d