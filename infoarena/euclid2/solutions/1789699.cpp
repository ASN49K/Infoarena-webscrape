#include <fstream>

using namespace std;
int main()
{
ifstream f("adunare.in");
ofstream g("adunare.out");

int a,b,s;
f>>a>>b;
s=a+b;
g<<s;
  return 0;
}

