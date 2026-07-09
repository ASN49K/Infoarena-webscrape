#include<stdio.h>

#define INPUT "euclid2.in"
#define OUTPUT "euclid2.out"

FILE *fin=fopen(INPUT, "r"),*fout=fopen(OUTPUT, "w");

long nr1, nr2;

inline void readValues(){fscanf(fin, "%ld %ld", &nr1, &nr2);}
void solveFunction();
inline void printSolution(long val){fprintf(fout, "%ld\n", val);}

int main(){
  readValues();
  solveFunction();
  fclose(fin);
  fclose(fout);
  return 0;
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
