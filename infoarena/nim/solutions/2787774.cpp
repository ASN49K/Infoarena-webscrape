#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,sum,it;
int main()
{
   f >> t;
   while(t--)
   {
       f >> n;
       n--;
       f >> sum;
       while(n--)
       {
           f >> it;
           sum = sum^it;
       }
       if(sum!=0)
         g << "DA"<<endl;
       else
        g << "NU"<<endl;

   }

    return 0;
}
