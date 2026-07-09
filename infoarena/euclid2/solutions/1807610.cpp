#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b;
    fin>>a>>b;
    while(a!=0&&b!=0)
    {
        if (a<b)
            swap(a, b);
        a=a%b;
    }
    fout<<b;
}
