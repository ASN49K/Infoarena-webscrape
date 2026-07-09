#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    
    FILE* in ,*out ;
    in = fopen("euclid2.in","rt");
    out = fopen("euclid2.out","wt");
    int n,x,y,i,r;
    fscanf(in, "%i",&n);
    for (i=0; i<n ; i++)
    {
        if (fscanf (in, "%i %i", &x,&y) == 2)
        {
         if ( x== 0 && y == 0 ) fprintf(out,"%i\n", 0);
         else
             if ( x== 0 && y != 0) fprintf (out,"%i\n", y);
             else
                  if ( y== 0 && x !=0 ) fprintf (out, "%i\n",x);
                  else 
                      if ( x == y ) fprintf (out, "%i\n" , x);
                      else 
                           {
                                while ( x !=y && x% y != 0 && y % x != 0 )
                           {
                                      if ( x < y ) y = y % x;
                                      else x = x %y;     
                           }
                            if ( x % y == 0 || y % x == 0 ) fprintf(out, "%i\n", x ? y : x <= y);     
                           }
                   
        }
         
    }
    fclose(in);
    fclose(out);
    return 0;
}
