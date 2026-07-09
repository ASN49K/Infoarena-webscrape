#include <iostream>

using namespace std;

int main()
{
  long a, b, r;
  
  freopen("euclid2.in", "r",  stdin);
  freopen("euclid2.out", "w", stdout);
  
  scanf("%ld %ld", &a, &b);
  while ( b!=0 )
  {
    r = a % b;
    a = b;
    b = r;
  }
  printf("%ld", a);
   
  return 0;
}

