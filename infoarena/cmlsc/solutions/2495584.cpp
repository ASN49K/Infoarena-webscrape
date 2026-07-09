#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], c[1025][1025], d[1025], k = 0;

int main()
{
    int maxa, maxb;
    fin >> maxa >> maxb;

    for(int i = 1; i <= maxa; i++)
        fin >> a[i];
    for(int i = 1; i <= maxb; i++)
        fin >> b[i];

    for(int i = 1; i <= maxa; i++)
        for(int j = 1; j <= maxb; j++)
            if(a[i] == b[j]){
                c[i][j] = c[i-1][j-1] + 1;
                d[k] = a[i];
                k++;
            }
            else if(c[i-1][j] > c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];


    fout << c[maxa][maxb] << "\n";
    for(int i = 0; i < k; i++)
        fout << d[i] << " ";

    return 0;
}
