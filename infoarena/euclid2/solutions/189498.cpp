/* ========================================================================== */
/*                                                                            */
/*   Algoritmul_lui_euclid.c                                                  */
/*   (c) 2008 Dr.Optix                                                        */
/*                                                                            */
/*   This is an implementation of the Euclid's algorithm to find the dreatest */
/*   common divisor of 2 numbers.                                             */
/* ========================================================================== */

#include <stdio.h>

/*
Funtion    : cmmdc
Paramaters : a - the firs number
             b - the second number
Description: This function computes the gcd of 2 numbers
*/
long cmmdc(long a, long b)
{
  return ( b != 0 ? cmmdc(b, a % b) : a );
}

int main()
{
  long Pairs;
  long a, b; 

  FILE *fin=fopen("euclid2.in","r");
  FILE *fout=fopen("euclid2.out","w");
  
  //read the number of pairs
  fscanf(fin,"%ld",&Pairs);
  
  //process each pair
  for(int i=0;i<Pairs;i++)
  {
    fscanf(fin,"%ld %ld",&a,&b);
    fprintf(fout,"%ld\n",cmmdc(a,b));
  }
  
  //Game Over
  return 0;
}
