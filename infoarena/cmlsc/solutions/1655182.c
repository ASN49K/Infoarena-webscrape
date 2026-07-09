#include <stdio.h>
#include <stdlib.h>

#define maxim(a,b) ((a>b) ? a : b)


int a[256],b[256],c[256],N,M,nr = 0;

FILE *fin;
FILE *fout;

int citire(){

int i,j;

fin = fopen("cmlsc.in","r");
fout = fopen("cmlsc.out","w");

fscanf(fin,"%d",&N);fscanf(fin,"%d",&M);

for(i = 0; i < N; ++i)
   fscanf(fin,"%d",&a[i]);
for(i = 0; i < M; ++i)
   fscanf(fin,"%d",&b[i]);

for(i = 0; i < N; ++i){
      for(j = 0; j < M; ++j){
          if(a[i] == b[j]){
              nr++;
              c[i] = b[j];
                                  }
                            }
                      }

fprintf(fout,"%d\n",nr);

for(i = 0; i < N; ++i){
       if(c[i] != 0)
       fprintf(fout,"%d ",c[i]);
                              }
     }

int main(){
    citire();
    
    fclose(fin);
    fclose(fout);
    }
