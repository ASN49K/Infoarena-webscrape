#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main() {
    int n,i,a,b,r;
    fin>>n;
    for(i=0;i<n;++i)
    {
        fin>>a>>b;
        while(a!=0) {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<b<<char(10);
    }
    return 0;
}
