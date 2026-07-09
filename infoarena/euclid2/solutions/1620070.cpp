#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
void cmmdc(int a,int b)
{
    int r;
    while(b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
    out<<a<<"\n";
}
int main()
{
    int a,b,n;
    in>>n;
    for(int i=1;i<=n;i++)
        {
            in>>a>>b;
            cmmdc(a,b);
        }
    in.close();
    out.close();
    return 0;
}
