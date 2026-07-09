#include <stdio.h>
using namespace std;
int main(void)
{
FILE *f;
f=fopen ("euclid2.in", "r");
int n;
fscanf(f, "%d",&n);

FILE *g=fopen ("euclid2.out", "w");

int nr1, nr2;
while(fscanf(f,"%d", &nr1)!=EOF)
{
 fscanf(f, "%d", &nr2);
 while(nr1!=nr2)
  if(nr1>nr2)
   nr1-=nr2;
  else
   nr2-=nr1;
 fprintf(g,"%d\n", nr1); 

}

fclose(f);
fclose(g);

return 0;
}

