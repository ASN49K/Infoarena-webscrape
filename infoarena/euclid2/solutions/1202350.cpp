#include<iostream>
#include<fstream>
using namespace std ;
int main()
{
int_fast64_t a, b, c;
int16_t n;
 ifstream  f("euclid2.in");
 ofstream  g("euclid2.out");
   f>>n;
for(int i = 0; i<n;i++)
{
    f>>a>>b;
     while(b != 0)
     {
      c=a%b;
      a=b;
      b=c;
      }
      g<<a<<endl;
}


}
