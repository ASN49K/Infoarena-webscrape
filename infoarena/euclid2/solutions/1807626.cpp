#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int x, a, b;
    fin>>x;
    for(int i=1; i<=x; i++)
    {
        fin>>a>>b;
        while(a!=0&&b!=0)
        {
            if (a<b)
                swap(a, b);
            a=a%b;
        }
        fout<<b<<'\n';
    }
}
