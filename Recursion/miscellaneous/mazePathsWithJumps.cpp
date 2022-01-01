// mazePathsWithJumps
// Question :  https://www.youtube.com/watch?v=F6T3tD8Pw20
// Solution :   https://www.youtube.com/watch?v=VaGBRiSdtFI

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
        vector<string> ways,rways,cways,dways;
            // cout<<dr<<" "<<dc<<"\n";

            if (sr==dr && sc==dc ){
                ways.push_back("");
                return ways;
            }
            
  //Write your code here
    
        int mp=max(dr-sr,dc-sc);
        for (int i = 1; i <=mp ; i++){

            if (dr-i>=sr){
                rways=get_maze_paths(sr,sc,dr-i,dc);
                for (int j = 0; j < rways.size(); j++){
                    // cout<<"hi";
                    ways.push_back("h"+to_string(i)+rways[j]);
                }
            }
            
            
            if (dc-i>=sc){
                cways=get_maze_paths(sr,sc,dr,dc-i);
                for (int j = 0; j < cways.size(); j++){
                    // cout<<"hi";
                    ways.push_back("v"+to_string(i)+cways[j]);
                }
            }
            
            
            if(dr-i>=sr && dc-i >=sc){        
                dways=get_maze_paths(sr,sc,dr-i,dc-i);
                for (int j = 0; j < dways.size(); j++){
                    // cout<<"hi";
                    ways.push_back("d"+to_string(i)+dways[j]);
                }        
            }

        }
        
        
        
        return ways;

}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);

  return 0;
}