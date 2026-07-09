#include<stdio.h>
#include<string.h>

#define INPUT "cmlsc.in"
#define OUTPUT "cmlsc.out"
#define CL(x) memset(x,0,sizeof(x));
#define maxim(x,y) ((x>y)?x:y)

FILE *fin=fopen(INPUT, "r"),*fout=fopen(OUTPUT, "w");

int vec1[1025],vec2[1025],final[1025],cont,n,m,pd[1025][1025];

void readValues();

void solveFunction();

void printSolution();

int main(){
  readValues();
  solveFunction();
  fclose(fin);
  fclose(fout);
  return 0;
}

void readValues(){
  int i;
  fscanf(fin, "%d %d", &n, &m);
  for(i=1;i<=n;++i)
    fscanf(fin, "%d", &vec1[i]);
  for(i=1;i<=m;++i)
    fscanf(fin, "%d", &vec2[i]);
}

void solveFunction(){
  int i,j;
  CL(pd);
  for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
      if(vec1[i]==vec2[j])
	pd[i][j]=pd[i-1][j-1]+1;
      else
	pd[i][j]=maxim(pd[i][j-1],pd[i-1][j]);
  i=n;
  j=m;
  CL(final);
  cont=1;
  while(i>0&&j>0){
    if(vec1[i]==vec2[j])
    {
      final[cont]=vec1[i];
      ++cont;
      --i;
      --j;
    }
    else
    if(pd[i][j-1]>pd[i-1][j])
	    --j;
    else
	    --i;
  }
  printSolution();
}

void printSolution(){
  fprintf(fout, "%d\n", pd[n][m]);
  int i;
  for(i=cont-1;i>0;--i)
    fprintf(fout, "%d ", final[i]);
  fprintf(fout, "\n");
}
