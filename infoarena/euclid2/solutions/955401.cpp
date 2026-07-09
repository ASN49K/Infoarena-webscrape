#include <fstream>
using namespace std;

int x1,x2,p;

int CMMDC(int a, int b)
{
    if(!b) return a;
    else return CMMDC(b,a%b);
}
int main()
{
    ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    f>>x1>>x2;
    p=CMMDC(x1,x2);
    if(p==1) g<<0;
    else g<<p;
    return 0;
}
