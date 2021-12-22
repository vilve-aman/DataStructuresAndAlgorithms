#include <bits/stdc++.h>
using namespace std;

void insert( vector <int> &v , int val ){
    // base case
        if (v.size()==0){
            v.push_back(val);
            return;
        }
    
    // normal case
            int temp=v[v.size()-1];
            v.pop_back();
            insert(v,val);
            v.push_back(temp);
}

void reverseStack( vector <int> &v ){
    // base case
        if (v.size()==1){
            return;
        }
    
    // normal case
        int temp=v[v.size()-1];
        v.pop_back();
        reverseStack( v );
        insert(v,temp);
}

int main(){
    // cout<<"hello world.😉";
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    reverseStack(v);
    
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    return  0;
}