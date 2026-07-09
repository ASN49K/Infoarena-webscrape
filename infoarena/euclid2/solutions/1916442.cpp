#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int i, x,y,n;

void divizor(int a, int b){
  int c;
  while(b){
    c=a%b;
    a=b;
    b=c;
  }
  fout<<a<<'\n';
}

int main()
{
    fin>>n;
    for( i=1;i<=n;i++)
    {
        fin>>x>>y;
        divizor(x,y);
    }

    return 0;
}
