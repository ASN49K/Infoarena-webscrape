#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    short n,i,a[100][10],r,aux,b,x;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a[i][1];
        fin>>a[i][2];
    }
    for(i=1;i<=n;i++)
    {
        int r,aux;
        x=a[i][1];
        b=a[i][2];
    r=x%b;
    while(r)
    {
        aux=x;
        x=b;
        b=r;
        r=x%b;
    }
        fout<<b<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}
