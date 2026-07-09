#include <iostream>
#include <fstream>
using namespace std;

int main()
{long long a,b,T,r,i;
 ifstream f("algluieuclid.in.txt");
 ofstream g("algluieuclid.out.txt");
 f>>T;
 for(i=1;i<=T;i++)
      {{while(a!=b)
        if(a>b)
            a=a-b;
        else
            b=b-a;}
g<<a<<endl;}
f.close();
g.close();
return 0;
}




