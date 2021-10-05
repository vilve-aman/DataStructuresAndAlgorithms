#include <iostream>
#include<unordered_set>
using namespace std;

int arrUnion(int a[], int b[], int n, int m){
    int count=0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.count(a[i])==0)
        {
            s.insert(a[i]);
            count++;
        }
        
    }

    for (int i = 0; i < m; i++)
    {
        if (s.count(b[i])==0)
        {
            s.insert(b[i]);
            count++;
        }
        
    }
    
    return count;
}

int main(){
    //cout<<"hello world.😉";

    int n,m;
    cin>>n>>m;
    int a[n],b[m];

    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    for (int i = 0; i < m; i++){
        cin>>b[i];
    }

    cout<<arrUnion(a,b,n,m);
    

    return  0;
}


// Union of two arrays -- DSA cracker sheet 

// tested inputs 
// 5 3
// 1 2 3 4 5
// 1 2 3


// 6 2 
// 85 25 1 32 54 6
// 85 2