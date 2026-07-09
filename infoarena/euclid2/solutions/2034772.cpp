#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,a,b;
void cmmdc(int a,int b)
{
   if(b==0)fout<<a<<endl;
   else cmmdc(b,a%b);

}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
        {fin>>a>>b;
        cmmdc(a,b);
        }

}
