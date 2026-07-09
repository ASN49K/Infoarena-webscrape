#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n,i;
    long long int a,b;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        out<<a<<endl;
    }
    return 0;
}
