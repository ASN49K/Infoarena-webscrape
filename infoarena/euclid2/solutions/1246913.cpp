#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int A,B,t,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        while (b) {
        c = a % b;
        a = b;
        b = c;
    }
        fout<<a<<"\n";
    }
    return 0;
}
