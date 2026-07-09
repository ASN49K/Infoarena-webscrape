#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long t,i,x,y,r;
int a[1000009],b[1000009];
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
