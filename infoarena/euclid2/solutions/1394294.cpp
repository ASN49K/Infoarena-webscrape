#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long t,i,a[1000000],b[1000000],x,y,r;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a[i]>>b[i];
    }
    for(i=1;i<=t;i++)
    {
        x=a[i];
        y=b[i];
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
