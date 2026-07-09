# include <fstream>
using namespace std;
int a[1000], b[1000], c[1000], d[1000], n, m, p, cls;
ofstream fout ("cmlsc.out");
void citire ()
{
     int i;
     ifstream fin ("cmlsc.in");
     fin>>n>>m;
     for (i=1;i<=n;i++)
         fin>>a[i];
     for (i=1;i<=m;i++)    
            fin>>b[i];
}

void copy (int k)
{
     int i;
     if (p<k)
     {
        p=k;
        for (i=1;i<=p;i++)
            c[i]=d[i];
     }
}
     
void bk (int k, int i, int j)
{
     int jj;
     if (i==n+1 || j==m+1)
        copy (k-1); 
     else
     {
         for (;i<=n;i++)
             for (jj=j;jj<=m;jj++)
                 if (a[i]==b[jj])
                 {
                     d[k]=a[i];
                     bk(k+1, i+1, jj+1);
                 }              
     }
}

int main ()
{
    citire ();
    bk(1, 1, 1);
    fout<<p<<endl;
    for (int i=1;i<=p;i++)
        fout<<c[i]<<" ";
    return 0;
}
