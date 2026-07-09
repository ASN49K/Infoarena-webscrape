#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ifstream out("euclid2.out");
int cmmdc(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,m1,m2;
    in>>n;
    while(n!=0)
    {
        in>>m1>>m2;
        out<<cmmdc(m1,m2)<<'\n';
        n--;
    }

}
