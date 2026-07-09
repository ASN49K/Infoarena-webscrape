#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
int cmmdc (int x,int y)
{int r;
while (y!=0) 
{r=x%y;
x=y;
y=r;
}
return x;
}
    
int main ()
{int i,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
f>>n;
for (i=1;i<=n;i++) 
{f>>a;
f>>b;
g<<cmmdc(a,b)<<"\n";
}

    return EXIT_SUCCESS;
}
