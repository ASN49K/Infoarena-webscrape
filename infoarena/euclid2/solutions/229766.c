#include <stdio.h>

int euclid (int a, int b) {
	if (!b)
		return a;
			
	return euclid (b, a % b);
}

int main (int argc, char * argv []) {
  FILE * fin = fopen ("euclid2.in", "rt");
  FILE * fout = fopen ("euclid2.out", "wt");

  int n, i;
  fscanf (fin, "%d", &n);
    
  for (i = 0 ; i < n ; i ++) {
	// read two numbers
	int a, b;
	fscanf (fin, "%d %d", &a, &b);
	fprintf (fout, "%d\n", euclid (a, b));
  }
  
  fclose (fin);
  fclose (fout);
}
