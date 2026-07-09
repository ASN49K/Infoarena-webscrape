/*
 * Created on: 25th February 2014
 * Author: <Marin Iulian Andrei>
 * Description: cel mai lung subsir comun
 * abordarea cu programare dinamica - optima;
 */

 #include <iostream>
 #include <fstream>
 #define NMAX 1024
 using namespace std;

 int n,m,A[NMAX],B[NMAX],C[NMAX],D[NMAX][NMAX],k;

 void read_data ()
 {
     int i;
     fstream f ("cmlsc.in",ios::in);
     f>>m>>n;
     for (i=1;i<=m;++i)
        f>>A[i];
     for (i=1;i<=n;++i)
        f>>B[i];
    f.close();
 }

 int max(int a,int b)
 {
     if (a > b) return a;
     else return b;
 }

 void solve ()
 {
     int i,j;

     for (i=1;i<=m;++i)
        for (j=1;j<=n;++j)
     {
         D[i][j]=max(D[i-1][j],D[i][j-1]);
         if (A[i] == B[j]) D[i][j]=max(D[i][j],D[i-1][j-1]+1);
     }
 }

 void print (int i,int j)
 {
     fstream g ("cmlsc.out",ios::out);
     g<<D[m][n]<<'\n';

     while (i>0 && j>0)
    {
        if (A[i] == B[j])
        {
            C[++k]=A[i];
            i--;
            j--;
        }
        else
            if (D[i][j] == D[i-1][j]) i--;
        else
            if (D[i][j] == D[i][j-1]) j--;
    }

    for (i=k;i>=1;i--)
        g<<C[i]<<" ";
    g.close();
 }

 int main()
 {
     read_data();
     solve();
     print (m,n);
     return 0;
 }
