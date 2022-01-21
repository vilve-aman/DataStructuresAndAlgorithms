#include <bits/stdc++.h>
using namespace std;

int factorial[]={1,1,2,6,24,120,720};


vector<int> kp(int n,int k, vector<int> &digits, vector<int> &op){
    // base case 
    if(digits.size()==1){
        op.push_back((char)digits[0]);
        return op;
    }
    // recursive case 
    int fixedDigit=k/factorial[n-1];
    if(k%factorial[n-1]==0){
        fixedDigit--;
    }
    int nextk=k%factorial[n-1];
    op.push_back((char)digits[fixedDigit]);
    digits.erase(digits.begin()+fixedDigit);

    kp(n-1,nextk,digits,op);
    return op;
}

int main(){
    cout<<"hello world.😉\n";
    int n,k;
    cin>>n>>k;
    vector<int> digits(n, 0);

    for (int i = 0; i < n; i++){
        digits[i]=i+1;
    }

    vector<int> op;
    op=kp(n,k,digits,op);

    for(auto i : op)    cout<<i;

    return  0;
}