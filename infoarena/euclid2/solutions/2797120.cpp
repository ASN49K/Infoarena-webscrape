#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b, i;

int gcd(int a, int b){
    if(b>a){
        int aux=b; b=a; a=aux;
    }
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    t=0;
    fin>>t;
    for(i=0;i<t;i++){
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
    return 0;
}
