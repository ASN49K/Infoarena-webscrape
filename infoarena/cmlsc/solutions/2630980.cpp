#include <iostream>
#include <fstream>
using namespace std;
int a, b;
int v[1025];
int v1[1025];
int matrix[1025][1025];
int sir[1025];
int poz = 1;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>a>>b;
    for(int i=1;i<=a;i++)
        f>>v[i];
    for(int j=1;j<=b;j++)
        f>>v1[j];
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            if(v[i]==v1[j])
                matrix[i][j] = 1 + matrix[i-1][j-1];
            else matrix[i][j] = max(matrix[i-1][j]  , matrix[i][j-1]);

        for(int i=a,j=b;i;)
            if(v[i]==v1[j])
                sir[poz++] = v[i] , i-- , j--;
                else if(matrix[i-1][j] < matrix[i][j-1])
                    j--;
                else i--;

    g<<poz-1<<endl;
    for(int i=poz-1;i>=1;i--)
    g<<sir[i]<<" ";
    return 0;
}
