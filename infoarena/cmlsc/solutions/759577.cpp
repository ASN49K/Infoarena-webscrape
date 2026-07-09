#include <fstream>



using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
ofstream foutv ("verif.out");
void cmlsc ( int, int);
void subsir ( int, int);
void afisare();
int a[1025],n,b[1025],m,rez[1025][1025],k,maxi,rezultat[1025];
int main()
{

    int i,dim,j;
    k++;
    fin>>n>>m;
    for ( i=1;i<=n;i++)
        fin>>a[i];
    for ( i=1;i<=m;i++)
        fin>>b[i];
    cmlsc(n,m);
    for ( i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
            foutv<<rez[i][j]<<" ";
        foutv<<"\n";
    }
    foutv<<rez[n][m]<<"\n";
    dim=rez[n][m];


    if ( dim )
        subsir(n,m);
    else
        fout<<0;
    //fout<<dim<<"\n";
    //for (i=dim;i>0;i--)
    //    fout<<rezultat[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}

void subsir (int i , int j)
{
    //fout<<"functia este apelata pentru "<<i<<" si "<<j<<"adica "<<a[i]<<" si "<<b[j]<<"\n";
    if ( i>=1 && j>=1 )
    {
        if (a[i]==b[j])
        {

            rezultat[k]=a[i];
            k++;
            //fout<<"pentru "<<i<<" si "<<j<<"adica "<<a[i]<<" si "<<b[j]<<" elementele sunt egale si returneaza subsir de "<<i-1<<" si "<<j-1<<"\n";
            if ( k==rez[n][m]+1)
            {



              afisare ();
              return;
            }
            subsir ( i-1,j-1);
            //return k;
        }
        else
        {
            if ( rez[i-1][j]>rez[i][j-1])
                {
                    //fout<<"pentru "<<i<<" si "<<j<<"adica "<<a[i]<<" si "<<b[j]<<" elementele nu sunt egale, si returneaza subsir de "<<i-1<<" si "<<j<<"adica "<<a[i-1]<<" si "<<b[j]<<"\n";
                    subsir(i-1,j);

                }
            else
                {
                    //fout<<"pentru "<<i<<" si "<<j<<"adica "<<a[i]<<" si "<<b[j]<<" elementele nu sunt egale si returneaza subsir de "<<i<<" si "<<j-1<<"adica "<<a[i]<<" si "<<b[j-1]<<"\n";
                    subsir (i,j-1);

                }
        }
    }
    else
    {
        if (k==rez[n][m])
       {

            //afisare();
            //return;
        }//return k;
    }
}
void afisare ()
{

    int i;
    fout<<rez[n][m]<<"\n";
    for ( i=rez[n][m] ; i>=1;i-- )
        fout<<rezultat[i]<<" ";
}
void cmlsc (int n, int m)
{
    int i,j;
    for ( i=1;i<=n;i++ )
        for (j=1;j<=m;j++ )
            if ( a[i]==b[j] )
                rez[i][j]=1+rez[i-1][j-1];
            else
                if ( rez[i-1][j]>rez[i][j-1])
                    rez[i][j]=rez[i-1][j];
                else
                    rez[i][j]=rez[i][j-1];
}
