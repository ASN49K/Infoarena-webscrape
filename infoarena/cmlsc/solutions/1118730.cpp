#include <iostream>
#include <fstream>
using namespace std;
int n,a[21][21];
void Citire()
{
    int i,j;
    ifstream fin("tabla.in");
    fin >> n;
    for(i = 1; i <= n; i++)
     for(j = 1; j<=n;j++)
      fin >> a[i][j];
    fin.close();
}
void Punctaj(int x , int y , int xx , int yy)
{
    int aux,i,j,c,sum,nr,tot,jj,k,ok;
     aux = a[x][y];
     a[x][y] = a[xx][yy];
     a[xx][yy] = aux;
     sum = 0;
        for(i = 1; i<= n; i++)
        {
            c = a[i][1];
            for(j = 1; j<=n;j++)
           {
             c = j+1;
              tot = 1;
              ok = 0;
                  while(a[i][j] == a[i][c])
                   { c++; tot++; }
            cout << tot <<" ";
                for(jj = j; jj < c; jj++)
                 {
                     k = i+1;
                     nr = 1;
                  while(a[k][jj] == a[i][jj])
                    {
                        nr++;
                        k++;
                    }
                 if (tot >= 3) ok = 1;
                     if(nr == 3 && tot == 3) sum+=5;
                 }


                if(ok == 0 && nr == 3) sum+=1;
            j = c-1;
           }
        }

       // cout << sum;
     aux = a[x][y];
     a[x][y] = a[xx][yy];
     a[xx][yy] = aux;
}
void Afisare()
{
    ofstream fout("tabla.out");
    Punctaj(0,0,0,0);
    fout.close();
}
int main()
{
    Citire();
    Afisare();
    return 0;
}
