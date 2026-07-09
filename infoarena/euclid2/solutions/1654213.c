#include <stdio.h>
#include <stdlib.h>

int a,b,cmmdc,r,i,T;

//Fisiere
FILE *fin;
FILE *fout;



void euclid(){
     
fin = fopen("euclid2.in","r");
fout = fopen("euclid2.out","w");

fscanf(fin,"%d",&T);

for(i = 0; i < T ; ++i){
      fscanf(fin,"%d",&a);fscanf(fin,"%d",&b); //Citim a si b
      
      //Euclid start
      r = a % b;
      
      while( r != 0){
             a = b;
             b = r;
             r = a % b;
                    }
      
      cmmdc = b;
      //Euclid stop
      
      fprintf(fout,"%d\n",cmmdc);
                       }

fclose(fin);
fclose(fout);
     }


int main(){

euclid();

/*r = a % b;

while( r != 0){
       a = b;
       b = r;
       r = a % b;
                  }
       cmmdc = b;
       printf("CMMDC :%d",cmmdc);*/

system("pause");
    }
