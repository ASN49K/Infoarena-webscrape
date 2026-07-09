#include <bits/stdc++.h>
#define optim ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define let auto
#define popcount __builtin_popcount
#define ctzll __builtin_ctzll
#define clzll __builtin_clzll

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int cmmdc(int a, int b){
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}



int main()
{

    int t, a, b;
    fin>>t;
    while(t--){
        fin>>a>>b;
        fout<<cmmdc(a, b)<<'\n';
    }


    return 0;
}