#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned long long ull;

ull cmmdc(ull a,ull b)
{ull r;
r=a%b;
while(r!=0)
{a=b;
b=r;
r=a%b;
}
return b;
}

int main(int argc, char *argv[])
{
    
    int t;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> t;
    ull a,b;
    for(int i=0;i<t;i++)
    {
     fin >>a >>b;
     fout<<cmmdc(a,b)<<"\n";
    }
    return EXIT_SUCCESS;
}
