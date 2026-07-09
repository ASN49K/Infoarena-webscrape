#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int t;
    fin >> t;
    while (t--) {
        int a, b;
        fin >> a >> b;
        int r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }

        fout << b << "\n";
    }   
    
    return 0;
}