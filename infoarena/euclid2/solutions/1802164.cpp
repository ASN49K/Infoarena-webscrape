#include <fstream>

using namespace std;
int n,a,b,r,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
int main()
{
    f>>n;
    for(i=0;i<n;i++)
    {f>>a>>b;
     while(b)
    {r=a%b;
     a=b;
     b=r;
}
     g<<a<<endl;
}
}
