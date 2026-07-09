#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>

int main () {

int tst, i, a, b, r;

 
FILE *fin, *fout;
 
fin = fopen ("euclid2.in", "r");
 
fout = fopen ("euclid2.out", "w");
 
fscanf (fin, "%d", &tst);

for (i = 0; i < tst; i++) {

	fscanf (fin, "%d %d", &a, &b);

	
		while (a != b) {

			if (a > b) {
				a = a-b;
			}
			else {
				b = b-a;
			}

		}
		fprintf(fout,"%d\n", b);
	

}

fclose (fin);
fclose (fout);

return 0;

}
