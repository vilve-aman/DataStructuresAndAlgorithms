#include <iostream>
using namespace std;

string rods[4]={"","Source","Helper","Destination"};

void towerOfHanoi(int s,int h,int d,int n){
    // base condition
        if(n==1){
            cout<<"move disk 1 "<<" from "<<rods[s]<<" to "<<rods[d]<<endl;
            return;
        }

    // normal condition
        towerOfHanoi(s,d,h,n-1);
        cout<<"move disk "<<n<<"  from "<<rods[s]<<" to "<<rods[d]<<endl;
        towerOfHanoi(h,s,d,n-1);
}

int main(){

    int n;
    cin>>n;

    towerOfHanoi(1,2,3,n);

    return  0;
}


// mistake commited - do not hard code the inputs in towerOfHanoi() function.