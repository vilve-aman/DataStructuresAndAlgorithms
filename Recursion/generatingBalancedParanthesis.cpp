#include <iostream>
using namespace std;

void generatingBalancedParenthesis(int open,int close,string output){
    // cout<<"ingeneratingBalancedParenthesis\topen:"<<open<<"\tclose:"<<close<<endl;
    // base case
    if(open==0 && close==0){
        cout<<output<<endl;
        return;
    }

    // normal case
    if (open<close){

        string op1=output;
        string op2=output;

        if (open!=0){                                                                                                           //  when both choices are available (i.e:   open=2  close=3)
            op1.push_back('(');
            generatingBalancedParenthesis(open-1,close,op1);

            op2.push_back(')');
            generatingBalancedParenthesis(open,close-1,op2);
        }   
        else{                                                                                                                       //  when open gets empty (i.e:   open=0  close=3)         
            op2.push_back(')');
            generatingBalancedParenthesis(open,close-1,op2);
            return;
        }     
    }
    else{                                                                                                                            //  when both open and close are equal (i.e:   only we can insert open bracket)                       
        output.push_back('(');
        open--;
        generatingBalancedParenthesis(open,close,output);
    }

       
}

int main(){
    // cout<<"hello world.😉";

    int n;
    cin>>n;
    generatingBalancedParenthesis(n,n,"");
    return  0;
}