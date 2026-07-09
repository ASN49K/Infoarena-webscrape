#include <fstream>

using namespace std;

ifstream in  ("euclid2.in");
ofstream out ("euclid2.out");
void euclid(int a,int b)
{
    if(b==0)
        out<<a<<"\n";
    else
        euclid(b,a%b);
}
int main()
{
   int a,b,n;
   in>>n;
   for(int i=1;i<=n;i++)
   {
       in>>a>>b;
       euclid(a,b);
   }

    return 0;
}
