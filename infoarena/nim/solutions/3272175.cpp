#include<fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int main()
{
  int t, n, buf, fin;
  cin>>t;

  while(t--)
  {
    cin>>n;
    fin=0;
    for(int i=0; i<n; i++)
    {
      cin>>buf;
      fin ^= buf;
    }
    if(fin != 0)
      cout<<"DA\n";
    else
      cout<<"NU\n";
  }
  return 0;
}
