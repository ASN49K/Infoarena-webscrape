#include <fstream>

using namespace std;

int main()
{int n,a,b,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;
    for(int i=0;i<n;i++)
    {f>>a>>b;

     while(b)
    {r=a%b;
     a=b;
     b=r;


    }
     g<<a<<endl;
}
f.close();
g.close();
}
