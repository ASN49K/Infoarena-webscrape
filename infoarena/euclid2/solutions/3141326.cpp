#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int AlE(int a,int b){
    while (a && b){
        if (a>b){
            a %= b;
        }else{
            b %= a;
        }
    }
    return a+b;
}

int main()
{
    int t;
    fin >> t;
    for (int i=1;i<=t;++i){
        int a,b;
        fin >> a >> b;
        fout << AlE(a,b) << '\n';
    }
    return 0;
}
