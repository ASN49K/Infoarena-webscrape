#include <iostream>
#include<fstream>
using namespace std;
struct pereche{long a;
long b;
};
int cmmdc(long a,long b)
{
 while(a!=b)
        if(a>b)
        a=a-b;
 else
    b=b-a;
 return a;
}

int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long t,i;
pereche a,b,v[1000];
fin>>t;
for(i=1;i<=t;i++)
    {
        fin>>v[i].a>>v[i].b;
        fout<<cmmdc(v[i].a,v[i].b)<<endl;

    }
    return 0;
}
