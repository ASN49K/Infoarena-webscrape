#include <fstream>
using namespace std;
int gcd(int a, int b)
{
   if(a==b) return a;
   if(a>b) return gcd(a-b,b);
   if(b>a) return gcd(a,b-a);
   return 1;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T, a, b;
    fin >> T;
    for (;T;T--)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
