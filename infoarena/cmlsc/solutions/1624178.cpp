#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int fr[257],a[1025],b[1025];
int main()
{
    int n,m,i,k=0,x;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
        fr[a[i]]++;
    }
    for(i=1;i<=m;i++)
    {
        fin>>x;
        if(fr[x]>0)
        {
            b[++k]=x;
        }
    }
    for(i=1;i<=n;i++)
    {
       //caut corespondent
    }
    return 0;
}
