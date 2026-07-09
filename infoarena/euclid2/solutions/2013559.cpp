///Afla cmmdc a 2 numere. pt. mai multe cazuri
#include <fstream>

using namespace std;

ifstream q("euclid2.in");
ofstream w("euclid2.out");

int euclid(int a, int b)
{
    if(b==0) return a;
    else euclid(b,a%b);
}

int main()
{int t,a,b;
    q>>t;
    for(int i=1;i<=t;i++)
    {
        q>>a>>b;
        w<<euclid(a,b)<<"\n";
    }

    return 0;
}
