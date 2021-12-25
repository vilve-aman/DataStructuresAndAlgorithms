#include <bits/stdc++.h>
using namespace std;


void josephusProblem(vector <int> &v, int n, int sword, int k){
    // base condition
    if(n==1){
        cout<<v[0];
        return;
    }

    // normal condition   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //    hint: after killing a man, the sword will be given to the person standing at his place (i.e sword will remain at same place in reduced array)
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int kill=(sword+k-1)%n;
    v.erase(v.begin()+kill);
    josephusProblem(v,n-1,kill,k);
}

int main(){
    // cout<<"hello world.😉";
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for (int i = 0; i < n ; i++){
        v[i]=i+1;
    }

    josephusProblem(v,n,0,k);

    return  0;
}