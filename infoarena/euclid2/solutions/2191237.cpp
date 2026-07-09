#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int x, int y){
    int t;
    while(y!=0){
        t = y;
        y=x%y;
        x=t;
    }
    return x;
}

int main()
{
    int a,b,x;
    fin>>x;
    for(int i=0;i<x;i++){
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';

    }

    return 0;
}
