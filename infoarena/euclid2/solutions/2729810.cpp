#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b){
int M = min(a, b);
int c;
for(int j=1; j<=M; j++){
    if(a%j==0 && b%j==0){
        c=j;
    }
}
return c;
}

int main()
{
    int n;
    fin>>n;
    for(int i=0; i<n; i++){
        int m, p;
        fin>>m>>p;
        fout<<cmmdc(m, p)<<"\n";

    }
}
