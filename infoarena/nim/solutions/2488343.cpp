#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n,x,s,i,j;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>n;
        s=0;
        for(j=1;j<=n;j++)
        {
            fin>>x;
            s=s^x;
        }
        if(s>0)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
}
