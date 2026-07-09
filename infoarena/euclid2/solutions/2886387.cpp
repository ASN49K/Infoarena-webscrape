#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;

int cmmdc(int a, int b){
    int r;
    do{
        r=a%b;
        a=b;
        b=r;
    }while(r!=0);
    return a;
}

int main()
{
    fin>>T;
    int a, b;
    while(T--){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }

    fin.close();
    fout.close();
    return 0;
}
