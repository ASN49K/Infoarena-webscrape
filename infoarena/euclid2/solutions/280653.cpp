#include<fstream.h>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a,int b)
{
    if(b==0)
      return a;
    else
     return euclid(b,a%b);
}

int main()
{
    int i,n,x,y;
    fin>>n;
    for(i=1;i<=n;i++)
    {
      fin>>x>>y;
      fout<<euclid(x,y)<<'\n';
    }
    fout.close();
    return 0;
}
