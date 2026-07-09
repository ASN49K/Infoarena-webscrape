#include<fstream>
using namespace std;

int T,a,b,i;

int cmd(int a, int b)
{
   if(b%a==0) return a;
     else return cmd(b,a%b);
}

int main()
{
  ifstream inFile("euclid2.in");
  inFile>>T;
  ofstream outFile;
  outFile.open("euclid2.out");
  for(i=1;i<=T;i++)
  {
    inFile>>a>>b;
    outFile<<cmd(a,b)<<endl;
  }
  return 0;
}



