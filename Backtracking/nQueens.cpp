#include <bits/stdc++.h>
using namespace std;

void printVec(vector <int> v){
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    
}

bool check(vector<vector<int>> &v,int row,int col){
    
    // checking the column 
    for (int i = row ; i >= 0; i--){
        if(v[i][col]==1)    return false;
    }

    // checking the normal diagonal     
    int x=row,y=col;
    while (x>=0&&y>=0){
        if (v[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    // checking the reverse diagonal    
    x=row;  y=col;
    while (x>=0&&y<v.size()){
        if (v[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    

    return true;
}
bool nQueens(vector<vector<int>> &v,int row,int n){
    if (row==n){
        return true;
    }
    
    for (int i = 0; i < n; i++){
        if (check(v,row,i)){

            v[row][i]=1;
            if(nQueens(v,row+1,n)){
                return true;
            }
            v[row][i]=0;
            
        }
        
    }
    return false;

}
int main(){
    // cout<<"hello world.😉\n";

    int n;
    cin>>n;
    vector<vector <int>> v(n,vector<int> (n,0));
    nQueens(v,0,n);

    for(auto i : v){
        printVec(i);
        cout<<endl;
    }
    return  0;
}