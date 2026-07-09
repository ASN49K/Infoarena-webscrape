#include<fstream>
using namespace std;
long a,b,r;
int main()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>a>>b;
    while(a%b!=0)
    {
    r=a%b;
    a=b;
    b=r;             
    }
   if(r==1) g<<0;
   else g<<r;
    f.close();
    g.close();
    return 0;
        
}
