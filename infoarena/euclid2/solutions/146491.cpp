#include <fstream>
using namespace std;

long cmmdc(long a, long b)
{
     if(!b) return a;
     return cmmdc(b,a%b);
}

int main()
{   ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    long a,b,c;
    fin>>a>>b;
    c=cmmdc(a,b);
    fout<<c;
    
    fin.close();
    fout.close();
    return 0;
}
