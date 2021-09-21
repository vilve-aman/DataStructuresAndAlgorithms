#include <iostream>
using namespace std;

void swap(int a[], int p,int q){
    int temp=a[p];
    a[p]=a[q];
    a[q]=temp;
}

void dnfSort(int a[], int n){
    int low=0,mid=0,high=n-1;
    while (mid<=high)
    {
        if(a[mid]==0){
            swap(a,mid,low);
            low++;  
            mid++;
        }  
        else if (a[mid]==1){
            mid++;
        }
        else{
            swap(a,mid,high);
            high--;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    

}


int main(){
    cout<<"hello world.😉 \n";

    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    dnfSort(a,n);

    return  0;
}




// Sort an array of 0s, 1s and 2s

// tested inputs   

// 8
// 1 1 0 0 2 2 1 1