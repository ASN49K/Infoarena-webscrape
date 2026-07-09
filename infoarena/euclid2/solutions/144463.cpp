#include<fstream>

#define INPUT "euclid2.in"
#define OUTPUT "euclid2.out"

using namespace std;

ifstream fin(INPUT);
ofstream fout(OUTPUT);

long nr1,nr2;

inline void readValues(){fin>>nr1>>nr2;}

void solveFunction();

inline void printSolution(long val){fout<<val<<endl;}

int main(){
  readValues();
  solveFunction();
  fin.close();
  fout.close();
}

void solveFunction(){
  long r;
  r=nr1%nr2;
  while(r!=0){
    nr1=nr2;
    nr2=r;
    r=nr1%nr2;
  }
  printSolution(nr2);
}
