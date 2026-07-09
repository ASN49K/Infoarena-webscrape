#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
    int r;
    r=a%b;
    if(r==0)
        return b;
    else
       cmmdc(a,r);
}
int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,i,a,b,r;
fin>>t;
for(i=1;i<=t;i++)
    {fin>>a>>b;
    fout<<cmmdc(a,b)<<endl;
}
    return 0;
    }
