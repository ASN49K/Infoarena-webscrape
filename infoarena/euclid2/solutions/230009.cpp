#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int x,y;

int main()
{  int r;
   f>>x;
   while(f>>x>>y)
   { r=x%y;
     while(r)
     {  x=y;  y=r; r=x%y;
     }
     g<<y<<endl;
   }
   f.close();
   g.close();
   return 0;
}
