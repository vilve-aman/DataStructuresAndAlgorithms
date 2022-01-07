#include <iostream>

using namespace std;

int ways(int n){
    if (n==1 || n==2 ){
        return n ;
    }
    else if (n==3){
        return 4;
    }
    else if (n<1){
        return 0;
    }
    
    int ans = ways(n-1) + ways(n-2) + ways(n-3);
    return ans;

}

int main(){
    cout<<"hello world.😉";
    int n;
    cin>>n;

    cout<<ways(n);

    return  0;
}

// tested inputs 
// 4
// op=7

// 5
// op=13
