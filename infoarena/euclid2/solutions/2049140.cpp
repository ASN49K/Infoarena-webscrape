#include <fstream>

using namespace std;
ifstream i("euclid2.in");
ofstream o("euclid2.out");
int main()
{
    int a, b, r, n, i;
    i>>n;
    for(i=1; i<=n; i++)
    {
        i>>a;
        i>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        o<<a<<endl;
    }
    return 0;
}
