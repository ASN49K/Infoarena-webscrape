#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int t,n;
int main()
{ in>>t;
  while(t--)
  { in>>n;
    int x;
    in>>x;
    for(int i=2;i<=n;i++)
    { int y;
      in>>y;
      x^=y;
    }
    if(x)
       out<<"DA\n";
    else
       out<<"NU\n";
  }
  in.close();
  out.close();
  return 0;
}
