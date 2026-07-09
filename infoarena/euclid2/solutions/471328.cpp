#include <iostream>
#include <fstream>

using namespace std;

int main()
{
 ifstream in("euclid2.in");
 ofstream out("euclid2.out");
 
 int a,b,c;
 in>>a>>b;cout<<a<<b;
 if (b>a) {c=a;a=b;b=c;}
 
 while (a!=0)
 {
  b=b%a;
  c=a;a=b;b=c;
 }
 
 out<<b;
 return 0;
}
