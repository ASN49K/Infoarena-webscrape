#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    if (a<b)
    {
        int mid=a;
        a=b;
        b=mid;
    }
    int c=1;
    while(c!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int T,a,b,i;
    f >> T;
    for(i=0; i < T; i++)
    {
        f >> a >> b;
        g << euclid(a,b) << '\n';
    }
    return 0;
}
