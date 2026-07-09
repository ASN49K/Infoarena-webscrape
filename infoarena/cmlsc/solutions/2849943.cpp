#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int comb[1050][1050];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m, a[1050], b[1050];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];       
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i] == b[j]){
                comb[i+1][j+1] = comb[i][j] + 1;
            }
            else{
                comb[i+1][j+1] = max(comb[i][j+1], comb[i+1][j]);
            }
        }
    }
    cout << comb[n][m] << '\n';
    vector <int> ans;
    int i = n, j = m;
    while(comb[i][j] != 0){
        if(comb[i][j] > comb[i-1][j] && comb[i][j] > comb[i][j-1]){
            ans.push_back(a[i-1]);
            --i, --j;
        }
        else{
            if(comb[i][j] == comb[i-1][j])
                --i;
            else
                --j;
        }
    }
    for(auto i = ans.rbegin(); i != ans.rend(); ++i){
        cout << *i << ' ';
    }

    
    /*    A B C D
        0 0 0 0 0 
      B 0 - 1 1 1
      C 0 - 1 2 2
      A 0 1 1 2 2
      D 0 1 1 2 3
        
      
     */


}