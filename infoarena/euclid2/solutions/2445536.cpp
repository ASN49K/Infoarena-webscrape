
#include <fstream>



using namespace std;

int a,b;

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
    int i, n;
    in>>n;
    for (i=0;i<n;i++)
    {
        in>>a>>b;
        out<<gcd(a,b)<<endl;
    }

    return 0;
}
