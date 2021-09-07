#include<iostream>
#include<unordered_set>

using namespace std;

int main(){

    int n,sum;
    cin>>n;
    cin>>sum;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    bool flag=0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++){
        
        if (s.count(sum-arr[i])==0){
            s.insert(arr[i]);
        }
        else{
            flag=1;
            cout<<arr[i]<<" "<<sum-arr[i]<<endl;
        }
         
        
    }
    if (flag==0){
        cout<<-1;
    }
    


    return 0;

}



// pair sum problem : find whether a pair exist or not with given sum = k

// this is hashing solution of the problem  
// TC=o(n)
// SC=o(n)


// we can solve this problem with ( sorting + two pointer ) approach also 
// TC=o(nlogn + n)
// SC=o(1)
