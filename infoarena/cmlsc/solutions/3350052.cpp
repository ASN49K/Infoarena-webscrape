#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M,N,vM[1024],vN[1024],a[1024][1024],sol[1024],nr,MAX,k;

int main()
{
    fin>>M>>N;

    for(int i=1;i<=M;i++)fin>>vM[i];
    for(int i=1;i<=N;i++)fin>>vN[i];

    for(int i=1;i<=M;i++)
       for(int j=1;j<=N;j++)
       {
          if(vM[i]==vN[j])a[i][j]=a[i-1][j-1]+1;
          else a[i][j] = max(a[i-1][j],a[i][j-1]);
       }
       
    MAX=a[M][N];

    fout<<MAX<<'\n';

    int i = M, j = N;
    int k = MAX;

    while (i > 0 && j > 0)
    {
        if (vM[i] == vN[j])
        {
            sol[k] = vM[i];
            k--;
            i--;
            j--;
        }
        else if (a[i - 1][j] >= a[i][j - 1])
            i--;
        else
            j--;
    }

    for (int i = 1; i <= MAX; i++)
        fout << sol[i] << " ";
        
    
    fin.close();
    fout.close();

    return 0;
}