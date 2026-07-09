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

	if (a %b == 0)
		fprintf(fout,"%d\n", b);
	
	else if (b % a == 0)
		fprintf(fout,"%d\n", a);

	else {
		while (a != b) {

			if (a > b) {
				r = a-b;
				a = b;
				b = r;
			}
			else {
				b = b-a;
			}

		}
		fprintf(fout,"%d\n", b);
	}

}

fclose (fin);
fclose (fout);

return 0;

}
