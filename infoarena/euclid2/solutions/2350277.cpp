#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int N,x,y;

int cmmd(int x,int y){
    if(!y)return x;
    return cmmd(y,x%y);
}

void citire(){
    fin>>N;
    for(int i=1;i<=N;i++)
        fin>>x>>y,
        fout<<cmmd(x,y)<<"\n";
}

int main()
{
    citire();
    return 0;
}
