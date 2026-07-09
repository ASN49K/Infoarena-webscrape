#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{   int n,a,b;
    fin>>n;
    for (int i;i<n;i++)
    {
        fin>>a>>b;
         while(a != b)
        if(a > b)
            a -= b;
        else
            b -= a;
        fout<<a<<'\n';
    }
    return 0;
}
