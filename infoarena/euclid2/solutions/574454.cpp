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
    while(t)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
        t--;
    }
        f.close();
        g.close();
        return 0;
}
