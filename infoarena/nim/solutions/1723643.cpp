#include <cstdio>

int main(){
   FILE*fi,*fout;
   int t,n,x,y,i;
   fi=fopen("nim.in" ,"r");
   fout=fopen("nim.out" ,"w");
   fscanf(fi,"%d" ,&t);
   while(t>0){
      t--;
      fscanf(fi,"%d%d" ,&n,&x);
      for(i=1;i<n;i++){
         fscanf(fi,"%d" ,&y);
         x^=y;
      }
      if(x==0)
        fprintf(fout,"NU\n");
      else
        fprintf(fout,"DA\n");
   }
   fclose(fi);
   fclose(fout);
   return 0;
}
