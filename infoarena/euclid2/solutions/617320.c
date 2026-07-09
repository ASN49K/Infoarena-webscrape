/******************************************************************************/
/*       File:    euclid.c                                                    */
/*       Author:  bazinga                                                     */
/*       Created: 10/14/2011                                                  */
/******************************************************************************/

#include <stdio.h>

int gcd (int a, int b) {
  if (b == 0)
    return a;
  return gcd (b, a%b);
}

int main () {
  FILE *f = fopen ("euclid2.in", "r");
  FILE *g = fopen ("euclid2.out", "w");

	int T, a, b;

	fscanf (f, "%d", &T);
	for (; T; --T) {
    fscanf (f, "%d%d", &a, &b);
    fprintf (g, "%d\n", gcd (a, b));
  }

  fclose(f);
  fclose(g);

  return 0;
}
