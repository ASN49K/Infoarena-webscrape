#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

const int NMax = 10005;

int v[NMax];

void solve(){
    int N, s;
    fin >> N;
    for(int i = 1; i <= N; ++ i){
        fin >> v[i];
    }
    s = v[1];
    for(int i = 2; i <= N; ++ i){
        s ^= v[i];
    }
    if(s == 0){
        fout << "NU\n";
    }
    else{
        fout << "DA\n";
    }
}

int main()
{
    int T;
    fin >> T;
    for(int i = 1; i <= T; ++ i){
        solve();
    }
    return 0;
}
