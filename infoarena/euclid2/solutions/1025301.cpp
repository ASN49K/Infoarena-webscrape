#include <iostream>
#include <fstream>

using namespace std;
int cmmdc(int a, int b)
{
    int r,aux;
    r=a%b;
    while(r)
    {
        aux=a;
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int n,i,a[100][10];
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
        fout<<cmmdc(a[i][1],a[i][2])<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
