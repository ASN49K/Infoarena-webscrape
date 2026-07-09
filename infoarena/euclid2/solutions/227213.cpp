#include <cstdio>
FILE *in, *out;

int main()
{
  in = fopen ("euclid2.in", "r");
  out = fopen ("euclid2.out", "w");
  int t;
  fscanf (in,"%d",&t);
  for (int i=1; i<=t; i++)
  {
  	int x,y,r;
    fscanf (in,"%d%d",&x,&y);
    
    r=x%y;
    while (r)
    {
      x=y;
      y=r;
      r=x%y;
    }
    fprintf (out,"%d\n",y);
  }
  
  
  fclose (in);
  fclose (out);
  return 0;
  
}
