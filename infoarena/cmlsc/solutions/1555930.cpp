#include <fstream>
#include <vector>

using namespace std;
ofstream fout("cmlsc.out");
    struct nr
    {
        int x,y;
    }v[1030];
int scriere(int z)
{
    if(v[z].y==1)fout<<v[z].x<<" ";
    else
    {
        int p=z-1;
        while(v[p].x>v[z].y && v[p].y!=v[z].y-1)
            p--;
        scriere(p);
        fout<<v[z].x<<" ";
    }
}
int main()
{
    ifstream fin("cmlsc.in");
    int n,m,a[1030],b[1030],k=1,j;
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
        fin.close();
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {   int l=k-1;
            if(a[i]==b[j]){v[k].x=a[i];
                            while(v[k].x<v[l].x)
                                l--;
                            v[k].y=v[l].y+1;
                            k++;
            break;}
        }
    }

    int Max=0;
    for(int i=1;i<k;i++)
        {if(Max<v[i].y)
            {Max=v[i].y;j=i;}
        }

    fout<<Max<<"\n";
    scriere(j);
}
