#include <fstream>
#include <algorithm>

using namespace std;
ofstream fout("cmlsc.out");

int na,nb,a[1030],b[1030],lcs[1030][1030];

inline void Read()
{
    int i;
    ifstream fin("cmlsc.in");
    fin>>na>>nb;
    for(i=1;i<=na;i++)
        fin>>a[i];
    for(i=1;i<=nb;i++)
        fin>>b[i];
    fin.close();
}

inline void Afis(int i, int j)
{
    if(i>0 && j>0)
        if(a[i]==b[j])
        {
            Afis(i-1,j-1);
            fout<<a[i]<<" ";
        }
        else
            if(lcs[i-1][j]>lcs[i][j-1])
                Afis(i-1,j);
            else
                Afis(i,j-1);
}

int main()
{
    int i,j;
    Read();
    a[0]=1;b[0]=2;
    for(i=1;i<=na;i++)
        for(j=1;j<=nb;j++)
            if(a[i]==b[j])
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
    fout<<lcs[na][nb]<<"\n";
    Afis(na,nb);
    fout<<"\n";
    fout.close();
    return 0;
}
