#include <bits/stdc++.h>
using namespace std;

unordered_set <string> bucket;

void printb(unordered_set<string> s){
    for(string item : s){
        cout<<item<<"\n";
    }
}

void subsets ( string input , string output ){
    // base condition
        if(input.size()==0){
            // cout<<output<<endl;
            if(bucket.count(output)==0){
                    bucket.insert(output);
            }
            return;
        }

    // normal condition
        string op1=output;
        string op2=output;
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        subsets(input,op1);
        subsets(input,op2);
}

int main(){
    cout<<"hello world.😉\n";

    string s ;
    cin>>s;
    subsets(s,"");
    printb(bucket);

    return  0;
}



// problem hint
// if  asked  for  unique subsets then the problem is of maps (i.e: unordered_maps or  unordered_set )
 