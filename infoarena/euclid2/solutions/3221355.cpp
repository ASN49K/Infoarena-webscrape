#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int AlgE(int a,int b){
    if (a==0) return b;
    if (b==0) return a;
    while (b>0){
        int rest = a%b;
        a = b;
        b = rest;
    }
    return a;
}

int main()
{
    int n;
    fin >> n;
    for (int i=1;i<=n;++i){
        int a,b;
        fin >> a >> b;
        fout << AlgE(a,b) << '\n';
    }
    return 0;
}
