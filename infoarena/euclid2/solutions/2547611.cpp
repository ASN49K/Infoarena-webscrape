#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n,a,b,rest;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a>>b;
        rest=a%b;
        while(rest){
            a=b;
            b=rest;
            rest=a%b;
        }
        fout<<b<<'\n';
    }
    return 0;
}
