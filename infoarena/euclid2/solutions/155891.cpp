#include <fstream>
using namespace std;

long long cmmdc(long long a, long long b)
{
     if(!b) return a;
     return cmmdc(b,a%b);
}

int main()
{   ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    long long a,b,c,t;
    fin>>t;
    
    while(t--)
    {
        fin>>a>>b;
        c=cmmdc(a,b);
        fout<<c<<endl;
    }
    
    fin.close(); fout.close();
    return 0;
}
