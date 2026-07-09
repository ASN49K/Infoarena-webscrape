#include <fstream>
using namespace std;

int main()
{int T,i,a,b;
ifstream f("euclid2.in");
f>>T;
for (i=1; i<=T; i++)
{
    f>>a>>b;
    while(a!=b)
    {
        if(a>b)a=a-b;
        if(a<b)b=b-a;
    }

}
f.close();
ofstream g("euclid2.out");
    for(i=1;i<=T;i++)g<<a<<endl;
    g.close();
    return 0;
}
