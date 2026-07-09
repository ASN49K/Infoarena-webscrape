#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int n, x, t, sum;

int main()
{
    for (f >> t ;t; t-- )
     {
         f >> n;sum=0;
           while(n--)
            {
                f >> x;
                sum^=x;
            }
      if( sum == 0 )
        g << "NU\n";
       else
        g << "DA\n";
     }


    return 0;
}
