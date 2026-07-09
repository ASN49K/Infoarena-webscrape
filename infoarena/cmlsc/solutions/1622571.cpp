#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int h,a[1025],b[1025],m,n,k,lcs[1025][1025],d[1025],i;
void citire()
{fin>>m>>n;
for(k=1;k<=m;k++)fin>>a[k];
for(k=1;k<=n;k++)fin>>b[k];
}
void rezolvare()
{for(k=1;k<=m;k++)
{
    for(h=1;h<=n;h++)
    {if(a[k]==b[h]){
        lcs[k][h]=1+lcs[k-1][h-1];}
    else if(lcs[k-1][h]>lcs[k][h-1])
        {lcs[k][h]=lcs[k-1][h];}
    else
    {lcs[k][h]=lcs[k][h-1];}

    }
}

}
void scriere()
{fout<<lcs[m][n]<<"\n";
for(i=0,k=m,h=n;lcs[k][h];)
    if(a[k]==b[h]){
            d[i++]=a[k];
    k--;
    h--;}
    else if(lcs[k][h]==lcs[k-1][h])
        k--;
    else
    h--;
    for(k=i-1;k>=0;k--)
    fout<<d[k]<<" ";
}
int main()
{citire();
rezolvare();
scriere();

return 0;
}
