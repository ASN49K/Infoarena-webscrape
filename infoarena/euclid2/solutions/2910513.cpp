#include <iostream>
#include <fstream>
using namespace std;


/*int suma(int nr)
{
    if(nr==0)
        return 0;

        return suma(nr/10)+nr%10;
}

    int Euclid (int a, int b)
    {
    while (b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
    }
*/

int Euclid (int a, int b)
{
    if (b == 0) return a;
    return Euclid(b, a % b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int a, b, n;

    fin>>n;

    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;
        fout<<Euclid(a, b)<<'\n';
    }

    return 0;
}
