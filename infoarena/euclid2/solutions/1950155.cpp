#include<fstream>
using namespace std;
ifstream input("euclid2.in");
ofstream output("euclid2.out");
int cmmdc(int a, int b)
{
    int r;
    if(b==0)
    {
        return a;
    }
    r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int n,a,b,i;
    input >> n;
    for(i=0; i<n; i++)
    {
        input >> a >> b;
        output << cmmdc(a,b) << '\n';
    }
}
