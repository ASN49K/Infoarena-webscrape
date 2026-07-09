#include <iostream>
#include <fstream>

using namespace std;

int main()
{int n,a,b,r;
    ifstream f("euclid2.in ");
    ofstream g("euclid2.out");

    f>>n;
    for(int i=0;i<n;i++)
    {f>>a>>b;
     r=a%b;
     while(r)
    {a=b;
        b=r;

    r=a%b;
    }
     g<<b<<endl;
}
f.close();
g.close();
}
