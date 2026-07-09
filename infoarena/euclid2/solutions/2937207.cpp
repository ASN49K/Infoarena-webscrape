/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int a,int b)
{
    if(!b)
       return a;
     else
      return euclid(b,a%b);
}
int main()
{
   int n,x,y;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>x>>y;
       cout<<euclid(x,y)<<'\n';
   }

    return 0;
}
