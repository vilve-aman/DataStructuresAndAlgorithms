#include <iostream>

using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    cout<<"hello world.😉";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
 
    int i=0,j=n-1;

    while (i<=j){
        
        while (a[i]<0&&i<n){
            i++;
            //cout<<"i="<<i;
        }

        while (a[j]>=0&&j>=0){
            j--;
            //cout<<"j="<<j;
        }
        
        if (i<j){
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
        
    }
    
    cout<<'\n';
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return  0;
}


//tested inputs

// 9
// -1 2 -3 4 5 6 -7 8 9

// 5
// 1 2 3 -2 5