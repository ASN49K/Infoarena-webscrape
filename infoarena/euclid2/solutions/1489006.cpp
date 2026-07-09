#include<bits/stdc++.h>

using namespace std;

long long a,b,r,t,i;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
   fin>>t;
  for (int i=0;i<t;i++)
  {
      fin>>a>>b;
   for (r=1;r!=0;r=a%b,a=b,b=r);

    fout<<a<<"\n";
  }
    fin.close();fout.close();
    return 0;
}
