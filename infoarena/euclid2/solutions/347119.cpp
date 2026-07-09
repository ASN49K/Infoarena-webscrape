#include <fstream>

using namespace std;

fstream f,g;
int a,b,n;

int euclid(int e,int f)
{
   int r;
   do
     r=e%f,e=f,f=r;
   while(r);
   return f;   
}

int main()
{
    f.open("euclid2.in",fstream::in);
    g.open("euclid2.out",fstream::out);
    f >> n;
    while(n)
      f >> a >> b,g << euclid(a,b);   
    g.close();
    return 0;
}
