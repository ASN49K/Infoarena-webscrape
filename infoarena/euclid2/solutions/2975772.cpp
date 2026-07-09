#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;
int euclid(int a,int b){
    if(!b)
        return a;
    else euclid(b,a%b);
}
int main()
{
    fin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
