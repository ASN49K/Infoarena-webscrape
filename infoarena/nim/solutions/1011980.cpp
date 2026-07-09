#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   int t, x, y, s;
   ifstream f("nim.in");
   ofstream g("nim.out");
   
   f>>t;
   
   while(t)
   {
       s=0;
       f>>x;
       
       for(int i=1; i<=x; i++)
            {
                f>>y;
                s=s^y;
            }
        if(s)
            g<<"DA\n";
        else
            g<<"NU\n";
        t--;
   }
   
   return 0;
}

