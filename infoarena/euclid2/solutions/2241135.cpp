#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fcin("euclid2.in");
    ofstream fcout("euclid2.out");

    int n, r=1;
    fcin>>n;

    int a[n][2];

    for (int i=1; i<=n; i++)
        for(int j=1; j<=2; j++)
            fcin>>a[i][j];

    for(int i=1; i<=n; i++)
    {
        while(a[i][2]) {
            r = a[i][1] % a[i][2];
            a[i][1]=a[i][2];
            a[i][2]=r;
        }
        fcout<<a[i][1]<<endl;
    }
    return 0;
}
