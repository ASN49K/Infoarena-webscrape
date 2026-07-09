#include<fstream>
using namespace std;
int main()
{
    int a, b,cont,n;
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
   cin>>n;
   for(int i=0;i<n;i++)
  {  cin>>a>>b;
   while(a%b!=0)
   {cont=a%b;
   a=b;
   b=cont;}
  
           cout<<b<<"\n";}
           
    return 0;
    
    
    }
