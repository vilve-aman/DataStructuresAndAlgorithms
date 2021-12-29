#include <bits/stdc++.h>
using namespace std;

int Output=0;

void op(int n,  int currOutput, bool cpyFlag=0, int cpyBuffer=0){
    // cout<<n<<" "<<currOutput<<"\n";
    int co1 = currOutput,co2 = currOutput,co3 = currOutput,co4 = currOutput;

    // base case 
        if (n==0){
            if (currOutput > Output){
                Output=currOutput;
            }
            // cout<<n<<" "<<currOutput<<"\n";
            return;
        }
        
    // normal case 
    
    //      key 1 is pressed
        co1++;
        op(n-1,co1);

    //      key 1+2+3+4 is pressed
        if (n>=4 && !cpyFlag ){
            co2++;
            cpyBuffer=co2;
            co2+=cpyBuffer;
            op(n-4,co2,1,cpyBuffer);
        }
                
    //      key 4 is pressed
        if (cpyFlag){
            co3+=cpyBuffer;
            op(n-1,co3,1,cpyBuffer);
        }
        
        //      key 2+3+4 is pressed
        if (cpyFlag && n>=3){
            cpyBuffer=currOutput;
            co4+=cpyBuffer;
            op(n-3,co4,1,cpyBuffer);
        }
        
}

int main(){
    // cout<<"hello world.😉";

    int n;
    cin>>n;


    op(n,0);
    cout<<"output is "<<Output;

    return  0;
}