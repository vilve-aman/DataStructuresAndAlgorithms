// Printing fibonachi is a bit typical thing if you try to add printing functionality into 
// fibonachi function then it would mesh up......................      it would print repeatedly each time when a specific value is called.
// mtlb ki agar hum fibonachi(5) call krrte h toh yeh fibonachi(4) aur fibonachi(3) ko call marega 
//                                                                             aur fibonachi(4) -->> fibonachi(3) aur fibonachi(2) ko call marega 
//                                                                             jisse fibonachi(3) dono baar malicious value print krega.

#include <iostream>
using namespace std;

int fibonachi(int n){
    // base case
    if( n==1 || n==2 ){
        return n-1;
    }

    // normal case
    int temp = fibonachi(n-1)+fibonachi(n-2);
    return temp;

}

void printFib(int n){
    if(n==0){
        return;
    }
    printFib(n-1);
    cout<<fibonachi(n)<<" ";
}

int main(){
    //cout<<"hello world.😉\n";
    int n;
    cin>>n;

printFib(n);
    
    return  0;
}


// inputs tested 

// 5
// 0 1 1 2 3    -------------------     O/P

// 10
// 0 1 1 2 3 5 8 13 21 34       -------------------     O/P