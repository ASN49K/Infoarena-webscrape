#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    if(!b)  return a;
    return cmmdc(b,a%b);
}

int main()
{
    int n,a,b;
    ifstream f1("euclid2.in");
    ofstream f2("euclid2.out");
    f1>>n;
    for(int i=0;i<n;i++)
    {
        f1>>a>>b;
        f2<<cmmdc(a,b)<<'\n';
    }
    f1.close();
    f2.close();
    return 0;
}
