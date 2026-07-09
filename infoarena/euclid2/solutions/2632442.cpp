#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{int a,b,t;
fin>>t;
    for(t;t;t--)
    {


fin>>a>>b;
while(a!=b)
{
    if(a>b)
        a=a-b;
    else
        b=b-a;
}
    fout<<a<<endl;
    }
    return 0;
}
