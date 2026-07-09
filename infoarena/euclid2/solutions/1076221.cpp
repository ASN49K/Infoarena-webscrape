#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T;
long long a,b;
f>>T;
for(int i=1; i<=T; i++)
            {f>>a>>b;
            while(a!=b)
                        if(a>b)
                                    a=a-b;
                        else
                                    b=b-a;
            g<<a<<endl;
            }



return 0;
}
