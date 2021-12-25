#include <bits/stdc++.h>
using namespace std;

void printvector(vector<string> &v){
    for (int i = 0; i < v.size() ; i++){
        cout<<"["<<v[i]<<"]";
    }
    
}

bool emptyPartition(vector <string> &v){
    for (int i = 0; i < v.size(); i++){
        if(v[i].size()==0){
            return true;
        }
    }
    return false;    
}

vector <string> pushInEmptyPartition(vector <string> v , char input){
    for (int i = 0; i < v.size(); i++){
        if(v[i].size()==0){
            v[i] += input;
            return v;
        }
    }
}

vector <vector <string>> pushInExistingPartitions(vector <string> &v , char input){
    vector <vector <string>> obj;
    vector <string> temp;
    for (int i = 0; i < v.size(); i++){
        temp=v;
        if(v[i].size()!=0){
            temp[i]+= input;
            obj.push_back(temp);
        }
    }
    return obj;

}

void kpartitions(string input, vector<string> v){
    // base case
        if(input.size()==0){
            //print the vector in which there is no empty partiton
            if (!emptyPartition(v)){
                printvector(v);
                cout<<endl;
            }
            return;
        }

    // normal case  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (emptyPartition(v)){                                                         //if an empty partition Exists then we have 2 choices       a)push in empty partition 
    //                                                                                                                                                                                                         b)push in existing partitions   
        string inp1,inp2;
        inp1=input;   inp2=input;
        vector<string> temp;    

        //push in empty partition        ------------------------------------------------------------------------------------------------------------
        temp=pushInEmptyPartition(v,inp1[0]);
        inp1.erase(inp1.begin()+0);
        kpartitions(inp1,temp);

        //push in existing partitions    ------------------------------------------------------------------------------------------------------------
        vector <vector <string>> obj;
        obj=pushInExistingPartitions(v,inp2[0]);
        inp2.erase(inp2.begin()+0);

        for (int i = 0; i < obj.size(); i++){
            kpartitions(inp2,obj[i]);
        }
        
 
    }
    else{
        //push in existing partitions   ------------------------------------------------------------------------------------------------------------
        vector <vector <string>> obj;
        obj=pushInExistingPartitions(v,input[0]);
        input.erase(input.begin()+0);

        for (int i = 0; i < obj.size(); i++){
            kpartitions(input,obj[i]);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
}

int main(){
    // cout<<"hello world.😉";

    int n, k;
    cin>>n>>k;
    string input;
    vector<string> v(k);
    for (int i = 1; i <= n; i++){
        input += to_string(i);
    }
    
    kpartitions(input,v);
    // kpartitions("abcd",v);
    return  0;
}