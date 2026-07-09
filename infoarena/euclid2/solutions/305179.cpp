#include<fstream>
using namespace std;

int main()
{
    long t, a, b,i;
    
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
      f>>t;
      
    for(i=1;i<=t;i++)
     {
       f>>a>>b;
       while(a!=b)
       {
         if(a>b)
           a=a-b;
         else
           b=b-a;
       }
       g<<a<<endl;
     }
    f.close();
    g.close();
  return 0;
  
}
