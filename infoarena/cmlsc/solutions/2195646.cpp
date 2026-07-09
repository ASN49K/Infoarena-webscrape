#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,mm,a[1026],b[1026],m[1026][1026];

void afisare(int i, int j, int k) {
    if(k>=1) {
        if(i>=1)
            if(j>=1)
                if(a[i]==b[j])
                {
                    afisare(i-1,j-1,k-1);
                    fout<<a[i]<<" ";
                } else {
                    if(m[i][j-1]>m[i-1][j])
                        afisare(i,j-1,k);
                    else
                        afisare(i-1,j,k);
                }

    }

}

int main()
{   int i,j,k;
    fin>>n>>mm;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=mm;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=mm;j++)
        {
            if(a[i]==b[j])
                m[i][j]=1+m[i-1][j-1];
            else
                m[i][j]=max(m[i-1][j], m[i][j-1]);
        }
    fout<<m[n][mm]<<endl;
    afisare(n,mm,m[n][mm]);
    return 0;
}
