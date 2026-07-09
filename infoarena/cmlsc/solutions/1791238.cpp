#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v1[1005], v2[1005], v[105][1005], n, m, i, j, dim;

void afis(int v[], int n)
{   fout<<n<<' ';
    for(int i=1;i<=n;i++)
        fout<<v[i]<<' ';
}
void inter(int a[], int n, int lin, int c[], int &d)
{   int i=1; j=1; d=0;
    while(i<=2 && j<=v[lin][0])
        if(a[i]<v[lin][j])
            i++;
        else if(a[i]>v[lin][j])
                j++;
            else
            {   d++;
                c[d]=a[i];
                i++; j++;
            }
}
int main()
{
    for(i=1;i<=2;i++)
    {   fin>>v[i][0];
        for(j=1;j<=v[i][0];j++)
            fin>>v[i][j];
    }
    dim=v[1][0];
    for(j=1;j<=dim;j++)
        v1[j]=v[1][j];

    for(int k=2;k<=2;k++)
        if(k%2==0) inter(v1,dim,k,v2,dim);
        else inter(v2,dim,k,v1,dim);

    if(2%2!=0) afis(v1,dim);
    else afis(v2,dim);

    return 0;
}
