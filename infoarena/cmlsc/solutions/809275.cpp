#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024],b[1025],lcs[1025][1025],op[1025][1025];
int n,m;

void citire();
int nrmax(int x,int y);
void pd();
void afisare();

int main()
{
    citire();
    pd();
    afisare();
    fout.close();
    return 0;
}

void citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
}

void pd()
{
    int i,j;
    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
            if(a[i]==b[j])
            {
                lcs[i][j]=1+lcs[i+1][j+1]; op[i][j]=1;
            }
            else
            {
                 lcs[i][j]=nrmax(lcs[i+1][j],lcs[i][j+1]);
                 if(lcs[i][j]==lcs[i+1][j])  op[i][j]=2;
                 if(lcs[i][j]==lcs[i][j+1])  op[i][j]=3;
            }

}

int nrmax(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

void afisare()
{
    int i=1,j=1;
    fout<<lcs[1][1]<<'\n';
    while(i!=n+1&&j!=m+1)
    {
        if(op[i][j]==1)
        {
            fout<<a[i]<<' ';
            i++; j++;
        }
        if(op[i][j]==2)
            i++;
        if(op[i][j]==3)
            j++;
    }


}
