#include <fstream>

using namespace std;
long a,b,r,n,c;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    fin>>n;
    for (c=1;c<=n;c++)
    {


    fin>>a>>b;
    do
    {
        r=a%b;
        a=b;
        b=r;
    }
    while (r);

    fout<<a<<'\n';
    }
    return 0;

}
