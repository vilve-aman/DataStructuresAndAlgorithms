#include <iostream>
#include<vector>

using namespace std;

void printVec(vector <int> v){
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    
}

void printVector(vector <vector <int> > tab){
    cout<<'\n'<<"called"<<'\n';
    for (int row = 1; row < tab.size(); row++){
        for (int column = 1; column < tab[row].size() ; column++){
            cout<<tab[row][column]<<"  ";
        }   
        cout<<endl; 
    }
}


void fillTable(vector < vector <int> > *tab, int n){
    vector <int > v;
    v.push_back(0);

//base condition -----------------------------------
    if (n==1){
        v.push_back(0);
        (*tab).push_back(v);
        return;
    }
    
// recursive call for smaller input-------------------
    fillTable(tab,n-1);
    
//  intuition------------------------------------------

    for (int i = 1; i < (*tab)[n-1].size(); i++){
        
        if ((*tab)[n-1][i]==0)
        {
            v.push_back(0);
            v.push_back(1);
        }
        else if ((*tab)[n-1][i]==1)
        {
            v.push_back(1);
            v.push_back(0);
        }

    }

    (*tab).push_back(v);
    
    return;

}

int kthGrammar(int n, int k) {

    vector < vector <int> > tab;
    vector <int> temp={0};
    tab.push_back(temp);
    
    fillTable(&tab,n);
     
    return tab[n][k];
}

int main(){

    int n,k;
    cin>>n>>k;
    
   cout<<kthGrammar(n,k);
    
}

//this program first fill the table recursively and after that find what is present i that cell

// tested inputs 

// 4 3 
// op = 1

// 4 4
// op=0