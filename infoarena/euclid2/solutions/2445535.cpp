
#include <fstream>



using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b)
{
   int c;

   while (a%b != 0)
   {
       c = a%b;
       a = b;
       b = c;
   }

   return b;
}


int main()
{
    int i, n, x, y;
    in>>n;
    for (i=0;i<n;i++)
    {
        in>>x>>y;
        out<<gcd(x,y)<<endl;
    }

    return 0;
}
