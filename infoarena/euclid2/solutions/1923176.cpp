#include<stdio.h>

long long cmmdc (long long a, long long b){
  long long r;
  while (b > 0){
    r = a%b;
    a = b;
    b = r;
  }
  return a;
}

int main (){
  FILE *in,*out;
  in = fopen ("euclid2.in","r");
  out = fopen ("euclid2.out","w");
  int t;
  long long a,b,d;
  fscanf(in,"%d",&t);
  for (;t>=1;t--){
    fscanf(in,"%lld%lld",&a,&b);
    d = cmmdc (a,b);
    fprintf (out,"%lld\n",d);
  }


  fclose (in);
  fclose (out);
  return 0;
}
