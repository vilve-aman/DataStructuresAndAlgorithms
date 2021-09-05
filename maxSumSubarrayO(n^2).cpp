
//    tested on  inputs  
//         4
//       -1 4 7 2
    

#include <iostream>
#include <climits>
using namespace std;

int main(){
    cout<<"hello world.😉\n";


    int n,sum=0,maxsum=INT_MIN;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    for (int i = 0; i < n; i++){
        
        for (int j = i; j < n; j++){
            
            sum+=a[j];
            cout<<sum<<"\n";
            maxsum=max(sum,maxsum);
        }
        sum=0;
    }
    
    cout<<"maxsum="<<maxsum;


    return  0;
}