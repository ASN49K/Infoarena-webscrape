#include <fstream>

using namespace std;

int main()
{
   long int a,b,aux;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");

  long int n,i;
  f>>n;

  for ( i=1; i<=n; i++){

    f>>a>>b;


    while ( b!=0 )
   {
     aux=a % b; a=b; b=aux;
   }

    g<<a<<endl;
  }

    return 0;

}
