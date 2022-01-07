// Problem : Kth Smallest / Largest  Element in a given array 
// Solution : Algorithm ---- Quick Select
//                     time complexity : best case -o(n)
//                                                     worst case-o(n^2)
//                     Space complexity : O(1)                              

#include <iostream>
using namespace std;

int partition(int a[], int l, int h){
    int i=l,j=h-1,temp;
    int pivot=h;

    //cout<<l<<" "<<h<<endl;
    while(i<j){
      
        while (a[i]<a[pivot] && i<pivot){
            i++;
        }

        while(a[j]>a[pivot] && j>l){
            j--;
        }
        
        if (i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        
    }

    if (a[i]>a[pivot]){    
        temp=a[i];
        a[i]=a[pivot];
        a[pivot]=temp;
    }

    return i;
} 


int kth_smallele(int a[],int k,int l,int h){
    
    int partitionIndex=partition(a, l,h);
    //cout<<partitionIndex<<" "<<k<<endl;

    if (k==partitionIndex){
        return a[partitionIndex];
    }

// if  the required elementIndex lies after the partition index 
    if(k>partitionIndex){
        return kth_smallele(a,k,partitionIndex+1,h);
    }

// if  the required elementIndex lies before the partition index 
    if(k<partitionIndex){
        return kth_smallele(a,k,l,partitionIndex-1);
    }
    


}

int main(){
    
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    
    cout<<kth_smallele(a,k-1,0,n-1);

    
    return  0;
}





// Inputs tested 
// 5 2
// 5 4 3 2 1

// 6 3
// 7 10 4 3 20 15

// 5 4
// 7 10 4 20 15

