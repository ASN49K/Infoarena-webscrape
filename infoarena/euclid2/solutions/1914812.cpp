#include<fstream>
using namespace std;

int firstNo, secondNo, remainder,n;


int main(){
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");

  fin>>n;
  for(int i = 0; i <n ;i++)
  {

      fin>>firstNo>> secondNo;
      while(secondNo!= 0)
      {
         remainder = secondNo;
         secondNo = firstNo % secondNo;
         firstNo = remainder;
      }
      fout<<firstNo<<"\n";
  }
  return 0;
}

