#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a , int b)
{
    if(b==0) return a;
    euclid(b,a%b);
}
int main()
{int t,a,b;
in>>t;
for(int i=1;i<=t;i++)
{in>>a>>b;
    out<<euclid(a,b);
    out<<'\n';
}
    return 0;
}
