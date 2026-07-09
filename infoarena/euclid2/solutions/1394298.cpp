#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long t,i,x,y,r,a,b;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
    }
    for(i=1;i<=t;i++)
    {
        x=a;
        y=b;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    fin.close();
    fout.close();
}
