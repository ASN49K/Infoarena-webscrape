#include <iostream>
using namespace std;
 
int cmmdc(int a, int b) 
{
  while (a != b) 
  {
    if (a > b)
      a -= b;
    else 
      b -= a;
  }
  return a;
}
 
int cmmdc2(int a, int b) 
{
  for (int r = a % b; r != 0; a = b, b = r, r = a % b)
    ;
  return b;
}
 
int main() 
{
  int n, *a, b;
  cout << "n=";
  cin >> n;
  a = new int[n];
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "]:";
    cin >> a[i];
}
 
  for (int i = 1; i < n; i++)
    if(i == 1)
      b = cmmdc(a[i - 1], a[i]);
    else
      b = cmmdc(b, a[i]);
 
  cout << b;
}