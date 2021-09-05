// kadane's  Algorithm


#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main(){
    cout<<"hello world.😉";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int maxsum=INT_MIN,csum=0;
        
        for(int i=0;i<n;i++){
            csum+=a[i];
            maxsum=max(maxsum,csum);
            if (csum<0)
                csum=0;
            
        }
        
        cout<<maxsum;

    return  0;
}