#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int x,i,n,y,j;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>y;
        x=0;
        for(j=1;j<=y;j++)
            x=x^y;
        if(x!=0)
            fout<<"DA"<<'\n';
            else
                fout<<"NU"<<'\n';
    }
}
