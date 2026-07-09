#include <fstream>
#include <vector>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
vector<int> nums1(1025);
vector<int> nums2(1025);
vector<vector<int>> c;
vector<int> rez;

int main(){
    f >> n >> m;
    nums1.resize(n+1);
    nums2.resize(m+1);

    c.resize(n+1, vector<int>(m+1, 0));

    for(int i=0; i<n; i++){
        f >> nums1[i];
    }
    for(int j=0; j<m; j++){
        f >> nums2[j];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(nums1[i-1] == nums2[j-1]){
                c[i][j] = 1 + c[i-1][j-1];
            }
            else{
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    g << c[n][m] << '\n';

    int row = n, col = m;
    while(row !=0 && col !=0){
        if(c[row][col] == 1 + c[row-1][col-1]){
            rez.push_back(nums1[row-1]);
            row--;
            col--;
        }
        else{
            if(c[row][col] == c[row-1][col])
                row--;
            else
                col--;
        }
    }
    for(int i=rez.size()-1; i>=0; i--){
        g << rez[i] << " ";
    }


    return 0;
}