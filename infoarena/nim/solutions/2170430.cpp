#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n,i,total=0;
    fin>>t;
    while(t--) {
        fin>>n;
        for(int k=1; k<=n; k++) {
            fin>>i;
            total^=i;
        }
        if(!total) fout<<"NU";
        else fout<<"DA";
        fout<<"\n";
    }
    return 0;
}
