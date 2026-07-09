#include<cstdio>
#include<fstream>

using namespace std;

int main()
{
  ifstream f("nim.in");
  ofstream g("nim.out");
  
  int t, suma_xor=0, x, n;
  
  f>>t;
  while(t--)
  {
    f>>n;
    for(int i=1;i<=n;i++)
      f>>x, suma_xor = suma_xor ^ x;
    if(suma_xor)
      g<<"DA"<<endl;
    else
      g<<"NU"<<endl;   
  }
  
  
  return 0;
}
