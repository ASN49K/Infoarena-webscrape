#include<fstream>

using namespace std;


ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b,n,r;

int main()
{
  cin>>n;
  while (n--)
  {
      cin>>a>>b;
      r=1;
      while (r)
      {
          r=a%b;
          a=b;
          b=r;
      }
      cout<<a<<"\n";
  }

   cin.close();
   cout.close();
    return 0;
}
