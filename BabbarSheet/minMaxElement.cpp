#include <iostream>
using namespace std;


void minMax(int a[],int n){

    int min,max,i;
    
    // 1. this is the initializtion of the min and max elements 
    // 2. moreover here important initialization is of itr " i " here 
    // becuase iterator always take a jump of 2 and we need to check for  edge case
    
    if(n%2==0){
        if(a[0]<a[1]){
            min=a[0];   
            max=a[1];
        }
        else{
            min=a[1];
            max=a[0];
        }
        i=2;
    }
    else{
        min=a[0];
        max=a[0];
        i=1;
    }

while (i < n-1){
    

    if(a[i]<a[i+1]){
        if(max<a[i+1]){
            max=a[i+1];
        }
        if (min>a[i]){
            min=a[i];
        }       
    }
    else{
        if(max<a[i]){
            max=a[i];
        }
        if (min>a[i+1]){
            min=a[i+1];
        }
    }
    i+=2;
}

cout<<"min : "<<min<<"\n";
cout<<"max : "<<max;

}


int main(){
// cout<<"hello world.😉";

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    minMax(a,n);
    return  0;
}


// this is an optimized solution for counting min and max element in an array 
// complexities here __are 

//             time Complexity : O(3n/2)
//             space Complexity : O(1)

// tested inputs 

// 5
// 1 2 3 4 5


// 6
// 1000 11 445 1 330 3000