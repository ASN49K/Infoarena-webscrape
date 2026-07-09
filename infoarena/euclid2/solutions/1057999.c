/*
 * test.c
 *
 *  Created on: Dec 14, 2013
 *      Author: ciprianconstantin
 */
#include<stdlib.h>
#include<stdio.h>


int main(void) {

	FILE *fin,*fout;
	int a,b,n,i;

	fin = fopen("euclid2.in","r");
	fout = fopen("euclid2.out","w");

	fscanf(fin,"%d",&n);

	i=0;
	while(i < n) {
		fscanf(fin,"%d",&a);
		fscanf(fin,"%d",&b);

		while(b>0) {
			int r=a%b;
			a=b;
			b=r;
		}
		fprintf(fout,"%d\n",a);
		i++;
	}
	fclose(fout);

	return 0;
}
