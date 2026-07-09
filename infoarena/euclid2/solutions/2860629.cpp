#include <fstream>

using namespace std;

   ifstream f("euclid2.in");
   ofstream ft("euclid2.out");
    long long a,b,r,n,i;

int main()
{   f>>n;
for(i=1;i<=n;i++)
{
    f>>a>>b;
    if(a<b) swap(a,b);
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    ft << b << "\n";
}
}
