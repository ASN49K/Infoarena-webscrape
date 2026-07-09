#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, M, x, rs;
ifstream fin("nim.in");
ofstream fout("nim.out");

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(; N; N--)
    {
        rs = 0;
       fin >> M;
        for(int i = 1; i <= M; i++) 
        fin >> x, rs^= x;
        if(rs&1) fout << "DA\n";
            else fout << "NU\n"; 
    }
    return 0;
}
