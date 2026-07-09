#include <fstream>
using namespace std;
int gcd(int a, int b)
{
   int r;
   r = a%b;
   if(r) return gcd(b,r);
   else return b;
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
