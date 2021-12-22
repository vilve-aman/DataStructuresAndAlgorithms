#include <bits/stdc++.h>
using namespace std;

void insert(vector <int> &v , int value){
    // base case
        if(v.size()==0 || v[v.size()-1]< value){
            v.push_back(value);
            return;
        }

    // normal case
        int temp=v[v.size()-1];
        v.pop_back();
        insert(v,value);
        v.push_back(temp);
}  

void sortArr(vector <int> &v , int n){
    // base case 
        if(n==1){
            return;
        }

    // normal case 
        int temp=v[n-1];
        v.pop_back();
        sortArr(v,n-1);
        insert(v,temp);
}

int main(){
    cout<<"hello world.😉 \n";
    int n;
    cin>>n;
    vector <int> v(n);
    
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    sortArr(v,n);

    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }

    return  0;
}