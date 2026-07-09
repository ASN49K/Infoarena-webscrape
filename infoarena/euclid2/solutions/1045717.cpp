#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int main()
{int t,i,a[10000],b[10000],r;
fin>>t;
for(i=0;i<t;i++)
fin>>a[i]>>b[i];
for(i=0;i<t;i++)
{while(b[i]){r=a[i]%b[i];a[i]=b[i];b[i]=r;} fout<<a[i]<<"\n";}
    return 0;
}
