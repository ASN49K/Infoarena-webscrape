#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,M,r,P,rest;
    fin>>M;
    for(r=1; r<=M; r++)
    {
        fin>>a>>b;
        P=a*b;
        while (b != 0)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
        fout<<a<<endl;

    }
    return 0;
}
