#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

#define INFILE "cmlsc.in"
#define OUTFILE "cmlsc.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int m, n, aux, cnt = 0;
unordered_map<int, int> fr_1, fr_2;
vector<int> ans;

void solve(){

    fin >> m >> n;

    for(int i = 0; i < m; ++i){
        fin >> aux;
        ++fr_1[aux];
    }

    for(int i = 0; i < n; ++i){
        fin >> aux;
        ++fr_2[aux];
    }


    for(auto nr : fr_1){
        cnt += min(nr.second, fr_2[nr.first]);
        for(int i = 1; i <= min(nr.second, fr_2[nr.first]); ++i){
            ans.push_back(nr.first);
        }
    }

    fout << cnt << '\n';
    for(int nr : ans){
        fout << nr << " ";
    }

}

int main(){
    solve();
    return 0;
}