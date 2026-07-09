#include <iostream>
#include <fstream>
using namespace std;


int ecl (int a, int b)
{while(a%b!=0)
        {int r=a%b;
        a=b;
        b=r;
        }

}

int main()
{int r, T, a, b, i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;

for(i=1; i<=T; i++)
    {f>>a;
    f>>b;
    ecl (a, b);
    g<<b<<endl;
    }

    return 0;
}
