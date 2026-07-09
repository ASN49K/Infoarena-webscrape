#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, M, x, rs;


int main(){
    ifstream cin("nim.in");
    ofstream cout("nim.out");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(; N; N--)
    {
        rs = 0;
        cin >> M;
        for(int i = 1; i <= M; i++){ 
                cin >> x;
                rs^= x;
        }
        if(rs!=0) cout << "DA\n";
            else cout << "NU\n"; 
    }
    return 0;
}
