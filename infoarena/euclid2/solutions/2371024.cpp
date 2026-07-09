#include <iostream>
#include <fstream>
using namespace std;
int n,a,b,d,i;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>a>>b;
        while (a!=b) {
        if (a>b) {
            a-=b;
        }
        else if (a<b) swap (a,b);
    }
        fout<<a<<"\n";
    }
    return 0;
}
