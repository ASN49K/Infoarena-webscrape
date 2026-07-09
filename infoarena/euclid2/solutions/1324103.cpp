#include <fstream>

using namespace std;

int prelucrare(int x,int y)
{
    int z;
    while(y)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return x;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,n;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<prelucrare(a,b)<<"\n";
    }
}
