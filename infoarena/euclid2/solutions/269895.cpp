#include <fstream>


using namespace std;
int N,v[100],a,b,i,r;

 
int main()
{ ifstream f("euclid2.in");
  ofstream g("euclid2.out");
   f>>N;
   for(i=1;i<=N;i++)
   {
    
           f>>a>>b; 
 r=a%b;
 while(r!=0)  
    { a=b;
    b=r;
    r=a%b;
}
   g<<b<<"\n";           
  f.close();
  g.close();
    
}
return 0;
}
