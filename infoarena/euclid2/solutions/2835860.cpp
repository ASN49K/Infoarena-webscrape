#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
    int t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        int m,n;
        fin>>n>>m;
        while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    fout<<n<<endl;
    }
}