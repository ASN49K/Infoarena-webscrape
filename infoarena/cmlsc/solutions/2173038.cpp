#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1010] , b[1010];
int c[1010],k;
int main()
{
    int i,m,j,m1;

    fin >> m >>m1;


    for(i=1; i<=m; i++)
        fin >> a[i];

    for(i=1 ;i<=m1; i++)
        fin >> b[i];
    sort(a+1,a+m+1);
    sort(b+1,b+m1+1);
    i = j = 1;
    while(i <= m && j <= m1)
       {

           if(a[i] == b[j])
           {
            c[++k] = a[i];
            i++;
            j++;
           }
        else if(a[i] < b[j]) i++;
        else j++;
       }

        fout << k << "\n";
        for(i=1; i<=k; i++)
            fout << c[i] << " ";

            return 0;

    return 0;
}
