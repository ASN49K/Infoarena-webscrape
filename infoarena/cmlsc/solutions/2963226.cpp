#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1025], b[1025], d[1025][1025];
vector<int> sol;
int main(){
    fin>>n>>m;
    for(int i=1; i<=n; i++) fin>>a[i];
    for(int i=1; i<=m; i++) fin>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j]) d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = (d[i][j-1]>d[i-1][j]?d[i][j-1]:d[i-1][j]);
    for(int i=n, j=m; i;){
        if(a[i] == b[j]) sol.push_back(a[i]), i--, j--;
        else if(d[i-1][j] >= d[i][j-1]) i--;
        else j--;
    }
    fout<<sol.size()<<"\n";
    for(int i=sol.size()-1; i>=0; i--) fout<<sol[i]<<" ";
}
