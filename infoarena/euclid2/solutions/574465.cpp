#include <fstream>
using namespace std;

int a,b,t;

int cmmdc(int A,int B)
{
    if(!B) return A;
    return cmmdc(B,A%B);
}
int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f>>t;
    for(;t;--t)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
        return 0;
}
