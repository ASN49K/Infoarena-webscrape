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
{int n,x,y;
    f>>n;
while(n--)
        {f>>x>>y;
        g<<divizor(x,y)<<endl;
        }
}

