#include <fstream>

using namespace std;


ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
void validarea();
int subsir ();
void validareb();
void back(int,int);
int sol[256],a[256],n,b[256],m,reza[32000][256],rezb[32000][256],pa,pb,v[256];
int main()
{
    int i,j,maxim;

    fin>>n;
    fin>>m;
    for (i=0;i<n;i++)
        fin>>a[i];
    for (i=0;i<m;i++)
        fin>>b[i];
    //fout<<"ok1";

    back(0,n);
    //fout<<"ok2";

    back(0,m);
    //fout<<"ok3";
/*
    for(i=0;i<pa;i++)
    {
        for ( j=1;j<reza[i][0];j++)
        {
            fout<<reza[i][j]<<" ";

        }
        fout<<"\n";
    }*/
    maxim=subsir();
    fout<<maxim<<"\n";
    for ( j=0;j<maxim;j++)
        fout<<v[j]<<" ";
    fin.close();
    fout.close();
    return 0;
}
int subsir ()
{
    int i,j,k,p,max=0;
    for (i=0;i<pa;i++)
        for(j=0;j<pb;j++)
            if (reza[i][0]==rezb[j][0])
            {
                for (k=1;(k<reza[i][0])&&(reza[i][k]==rezb[j][k]);k++);
                if ( k==reza[i][0] )
                {
                    if ( max<k )
                    {
                        for (p=1;p<reza[i][0];p++)
                            v[p-1]=reza[i][p];
                        max=k-1;
                    }
                }
            }
    return max;

}

void back (int k,int x)
{
    int i;
    for ( i=0;i<=1;i++ )
    {
            sol[k]=i;
        if (k==x-1)
            if ( x==n )
                validarea();
            else
                validareb();
        else
            back(k+1,x);
    }
}
void validarea()
{
    int i,j=1;
    for ( i=0;i<n;i++)
        if ( sol[i] )
            {
                reza[pa][j]=a[i];
                j++;
            }
    reza[pa][0]=j;
    pa++;
    //fout<<"\n";

}

void validareb()
{
    int i,j=1;
    for ( i=0;i<m;i++)
        if ( sol[i] )
            {
                rezb[pb][j]=b[i];
                j++;
            }
    rezb[pb][0]=j;
    pb++;
    //fout<<"\n";

}
