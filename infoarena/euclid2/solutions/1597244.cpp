#include <iostream>
#include <fstream>
using namespace std;

int main()

{int t,i,x,y;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++)
{f>>x>>y;
while((x!=0)&&(y!=0))
    if(x>y)
    x=x%y;
else
    y=y%x;

    if(x!=0)
    g<<x<<'\n'; else g<<y<<'\n';
}

f.close();
g.close();


}
