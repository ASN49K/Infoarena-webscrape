#include <iostream>
using namespace std;
int main()
{

int n , m,r;

cin>>n>>m;

while(m != 0)
{
  int r = n % m;
  n = m;
  m = r;
}

cout<<n;

return 0;
}
