#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int A,int B)
{
        int s1,s2,rest;
        s1=max(A,B);
        s2=min(A,B);
        rest=s1%s2;
        while(rest!=0)
        {
            s1=s2;
            s2=rest;
            rest=s1%s2;
        }
        return s2;

}
int main()
{
    int n,a,b,i;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }

    return 0;
}
