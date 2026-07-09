#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dirl[3]={0,-1,-1};
int dirc[3]={-1,0,-1};

struct interval
{
    int lungime,directie;
}mat[1024][1024];
int v[1024],w[1024],nrfin[1024];

int main()
{
    int i,j,m,n,l,c,lmax,dl,dc;
    fin >> n >> m;
    for(i=0;i<n;i++)
        fin >> v[i];
    for(j=0;j<m;j++)
        fin >> w[j];
    if(v[0]==w[0])
        mat[0][0].lungime=1;
    for(i=1;i<n;i++)
    {
        if(v[i]==w[0])
        {
             mat[i][0].lungime=1;
             mat[i][0].directie=2;
        }

        else
        {
            mat[i][0].lungime=mat[i-1][0].lungime;
            mat[i][0].directie=1;
        }
    }
    for(j=1;j<m;j++)
    {
        if(v[0]==w[j])
        {
            mat[0][j].lungime=1;
            mat[0][j].directie=2;
        }

        else
        {
            mat[0][j].lungime=mat[0][j-1].lungime;
            mat[0][j].directie=0;
        }
    }

    for(i=1;i<1024;i++)
    {
        for(j=1;j<1024;j++)
        {
            if(v[i]==w[j])
            {
                mat[i][j].lungime=mat[i-1][j-1].lungime+1;
                mat[i][j].directie=2;
            }
            else
                if(mat[i-1][j].lungime>mat[i][j-1].lungime)
                {
                    mat[i][j].lungime=mat[i-1][j].lungime;
                    mat[i][j].directie=1;
                }
                else
                {
                    mat[i][j].lungime=mat[i][j-1].lungime;
                    mat[i][j].directie=0;
                }
        }
    }
    lmax=mat[n-1][m-1].lungime;
    l=n-1;
    c=m-1;
    while(l>=0 && c>=0)
    {
        if(v[l]==w[c])
        {
            nrfin[lmax-1]=v[l];
            lmax--;
        }
        dl=dirl[mat[l][c].directie];
        dc=dirc[mat[l][c].directie];
        l+=dl;
        c+=dc;
    }
    fout << mat[n-1][m-1].lungime << '\n';
    for(i=0 ; i<mat[n-1][m-1].lungime ; i++)
        fout << nrfin[i] << " ";

    return 0;
}
