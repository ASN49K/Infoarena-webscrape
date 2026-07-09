#include<fstream>
using namespace std;
int hack(int x, int y) 
{ 
    if (!y) return x; 
    return hack(y, x % y); 
} 
int main()
{
  ifstream f("euclid2.in");  
  ofstream g("euclid2.out");  
  int t,a,b;
 f>>t;  
 for(t;t;--t)  
  {f>>a>>b;  
    g<<hack(a,b)<< '\n';}
}
