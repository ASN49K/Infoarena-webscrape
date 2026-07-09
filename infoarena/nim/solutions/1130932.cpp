#include<fstream>
using namespace std;
int n,m,i,j,x,s;

ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>m;
        s=0;
        for(j=1;j<=m;j++)
        {
            fin>>x;
            s=s xor x;
        }
        if(s)fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
    return 0;
}
