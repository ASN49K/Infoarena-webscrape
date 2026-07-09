#include <fstream>
using namespace std;
int a,b,T;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    f>>T;
    for(int i=0;i<T;i++)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        g<<a<<endl;
    }
    return 0;
}
