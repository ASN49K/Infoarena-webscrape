#include <iostream>
#include <fstream>

std::ifstream fin("nim.in");
std::ofstream fout("nim.out");
int t,n,sum,k;
int main()
{
  fin>>t;
  for(int i=t;i;i--)
  {
    fin>>n>>sum;
    for(int j=n-1;j;j--)
    {
      fin>>k;
      sum=sum^k;
    }
    if(sum)
      fout<<"DA\n";
    else
      fout<<"NU\n";
  }
}
