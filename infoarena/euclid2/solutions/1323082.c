#include <stdio.h>


int main(int argc, char* argv[]) {

	FILE *fr;
	FILE *fw;
	char *filenameR;
	char *filenameW;
	filenameR = argv[1];
	filenameW = argv[2];

	printf("%s\n", filenameR);
	printf("%s\n", filenameW);
	
	fr = fopen( filenameR, "r");
	fw = fopen( filenameW, "w");
	
	int D, I, R;
	int nr_of_rounds;

	if( fr == NULL) {

		fprintf(stderr, "Can't open file %s\n", filenameR);
	}
	
	fscanf(fr,"%d", &nr_of_rounds);

	printf("%d\n", nr_of_rounds);

	int count = 1;

	while( count <= nr_of_rounds) {

		fscanf(fr, "%d %d", &D, &I); 
		//printf("The values from the file are: %d %d \n", D, I);	
	
		while( I != 0) {	
			
			R = D % I;
			D = I;
			I = R;
		}
		fprintf(fw, "%d\n", D);
		//printf("Cmmdc-ul este: %d\n", D);
		
		count++;
	}


	fclose(fr);
	fclose(fw);
	return 0;
}
	
