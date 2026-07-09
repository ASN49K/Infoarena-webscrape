#include<fstream>
#include<vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1025], b[1025], D[1025][1025];
vector<int> v;
int main(){
    fin >> n >> m;
    for( int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for( int i = 1; i <= m; i++){
        fin >> b[i];
    }
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            D[i][j] = max( D[i- 1][j], D[i][j - 1] );
            if( a[i] == b[j] ){
                D[i][j] = D[i - 1][j - 1] + 1;
            }
        }
    }
    fout << D[n][m] << "\n";
    int i = n;
    int j = m;
    while( D[i][j] != 0 ){
        if( a[i] == b[j] ){
            v.push_back( a[i] );
            i--;
            j--;
            continue;
        }
        if( D[i - 1][j] > D[i][j - 1] ){
            i--;
        }else{
            j--;
        }
    }
    for( int i = v.size() - 1; i >= 0; i-- ){
        fout << v[i] << " ";
    }
    return 0;
}
