#include <bits/stdc++.h>
using namespace std;

int eggDrop(int eggs, int floors){
    // base case 
    if(eggs==1){
        return floors;
    }
    if(floors==1 || floors ==0){
        return floors;
    }

    // recursive case 
    int minAttempts=INT_MAX;    
    for (int k = 1; k <= floors; k++){
        int tempAns=1+max( eggDrop(eggs-1,k-1) , eggDrop(eggs,floors-k));
        minAttempts=min( minAttempts , tempAns);
    }
    
    return minAttempts;

}

int main(){
    cout<<"hello world.😉\n";
    int eggs,floors;
    cin>>eggs>>floors;
    cout<<eggDrop(eggs,floors);
    return  0;
}


// // inp uts
// 2 15
// // outputs 
// hello world.😉
// 5



// // inp uts
// 3 9
// // outputs 
// hello world.😉
// 4



// re check
