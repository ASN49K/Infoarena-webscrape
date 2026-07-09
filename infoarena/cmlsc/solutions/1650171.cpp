#include<iostream>
#include<fstream>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1027], b[1027], v[1027], lcs[1027][1027], n, m;

void Citire()
{
   fin >> n >> m;
   for (int i=1; i<=n; i++)
       fin >> a[i];
   for (int i=1; i<=m; i++)
       fin >> b[i];
}

void LCS()
{
   int i,j;
   for (i=1; i<=n; i++)
   {
      for (j=1; j<=m; j++)
        {
           if (a[i] == b[j]) lcs[i][j] = 1 + lcs[i-1][j-1];
           else              lcs[i][j] = max (lcs[i-1][j], lcs[i][j-1]);
        }
   }

}

void Afisare()
{
   int i, j, len, cnt;

   cnt = 1;
   i = n; j=m;  len = lcs[n][m];

   while (lcs[i][j] != 0)
   {
       if (a[i]==b[j]) { v[len-cnt+1] = a[i]; cnt++; i--;j--;}

       else if (lcs[i-1][j] > lcs[i][j-1]) i--;

       else j--;
   }

   fout << len << "\n";

   for (i=1; i<=len; i++)
     fout << v[i] << " ";
}


int main ()
{
  Citire();
  LCS();
  Afisare();
  fin.close();
  fout.close();
  return 0;
}
