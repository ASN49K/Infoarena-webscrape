#include<fstream>
using namespace std;
long n,p,m[1025][1025],a[1025],b[1025],i,j,k,v[1025],ok;
long maxim(long a, long b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
f>>n>>p;
for(i=1;i<=n;i++)
    f>>a[i];
for(i=1;i<=p;i++)
    f>>b[i];
for(i=1;i<=n;i++)
    {ok=0;
    for(j=1;j<=p;j++)
        {
            if(a[i]==b[j] && ok==0)
                {m[i][j]=m[i-1][j-1]+1;
                ok=1;}
            else
                m[i][j]=maxim(m[i-1][j],m[i][j-1]);
        }
    }
g<<m[n][p]<<'\n';
i--;
j--;
while(i>1 || j>1)
    {
        if(m[i-1][j]==m[i][j])
            {
            while(m[i-1][j]==m[i][j])
                i--;
            while(m[i][j-1]==m[i][j])
                j--;
            }
        else if(m[i][j-1]==m[i][j])
            {
                while(m[i][j-1]==m[i][j])
                    j--;
                while(m[i-1][j]==m[i][j])
                    i--;
            }
        v[++k]=a[i];
        i--;
        j--;
    }
for(i=k;i>=1;i--)
    g<<v[i]<<" ";
return 0;
}
