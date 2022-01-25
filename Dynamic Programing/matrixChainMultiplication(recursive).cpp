#include <bits/stdc++.h>
using namespace std;

int mcm (vector<int> v, int i, int j){
// base case 
    if(i>=j){
        return 0;
    }
// recursive case 
    int ans= INT_MAX;
    for (int k = i; k < j; k++)    {
        int tempans = mcm(v,i,k) + mcm(v,k+1,j) + v[i-1]*v[k]*v[j] ;
        if(tempans<ans) ans=tempans;
    }
    return ans;
}

int main(){
    cout<<"hello world.😉\n";
    int n;
    cin>>n;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++)    {
        cin>>v[i];
    }
    
    cout<<mcm(v,1,n-1);
    return  0;
}

// inputs  tested
// 5
// 40 20 30 10 30
// output 
// hello world.😉
// 26000