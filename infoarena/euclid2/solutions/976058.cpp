#include<fstream>
using namespace std;

int T,a,b;

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
  for(int i=T;i>0;i--)
  {
    inFile>>a>>b;
    outFile<<cmd(a,b)<<endl;
  }
  return 0;
}



