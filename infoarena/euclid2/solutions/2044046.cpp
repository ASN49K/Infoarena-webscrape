#include <fstream>

using namespace std;

int divi(int a, int b)
{
    if(a == 1 || b == 1) return 1;
    if (a == b) return a;
    return a < b ? divi(a , b - a):  divi(a - b , b);
}


int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin>>T;
    int a,b;
    for(int i = 0;i < T;i++)
    {
        fin>>a>>b;
        fout<<divi(a,b)<<'\n';
    }
    return 0;
}
