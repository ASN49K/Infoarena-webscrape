#include <cstdio>
inline int gcd(int a,int b){
   int r;
   while(b>0){
      r=a%b;
      a=b;
      b=r;
   }
   return a;
}
int main(){
    FILE*fi,*fout;
    int a,b,t;
    fi=fopen("euclid2.in" ,"r");
    fout=fopen("euclid2.out" ,"w");
    fscanf(fi,"%d" ,&t);
    while(t>0){
       t--;
       fscanf(fi,"%d%d" ,&a,&b);
       fprintf(fout,"%d\n" ,gcd(a,b));
    }
    fclose(fi);
    fclose(fout);
    return 0;
}
