#include <iostream>
#include<unordered_set>
#include<climits>
using namespace std;

int findmax(int a ,int b){
    
    if (a>=b)
        return a;
    else 
        return b;

}

int main(){
    //cout<<"hello world.😉";
    int n,temp,min,max,result=0;
    cin>>n;
    int a[n];

    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    
    unordered_set<int> s;

    for (int i = 0; i < n; i++){
        s.insert(a[i]);
    }



    for (auto  element : s){
        //cout<<element<<" ";
        
        // this segment find the head of the consecutive chain
        temp=element;
        while (s.count(temp-1) !=0 ){
            temp-=1;
            s.erase(temp);
        }
        min=temp;


        // this segment find the tail of the consecutive chain
        temp=element;
        while (s.count(temp+1) !=0 ){
            temp+=1;
            s.erase(temp);
        }
        max=temp;
        //cout<<max;

        //this segment check for the max length
        result=findmax(result,max-min+1);
        //cout<<result<<endl;
    }

    cout<<result;


    return  0;
}



//inputs tested


// 5
// 1 2 3 -2 5
// ans: 3



// 10
// 12 10 3 1 5 8 4 2 6 11
// ans: 6