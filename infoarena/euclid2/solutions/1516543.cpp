#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int divizor(int a,int b)
{
    if(!b)return a;
    else return divizor(b,a%b);
}
int main()
{unsigned int n,x,y;
    f>>n;
for(int i=0;i<n;i++)
        {f>>x>>y;
        g<<divizor(x,y)<<"\n";
        }
        return 0;
}

