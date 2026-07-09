#include <stdio.h>

#define MAX(a, b) (a > b) ? a : b

typedef struct {
	unsigned char *v;
	int l;
} vector;

void read (FILE *in, vector *v1, vector *v2) {		
	fscanf (in, "%d", &v1->l);
	v1->v = new unsigned char[v1->l + 1];
	
	fscanf (in, "%d", &v2->l);
	v2->v = new unsigned char[v2->l + 1];
	
	for (int i = 1; i < v1->l + 1; ++i) {
		fscanf(in, "%hhu", &v1->v[i]);
	}
	
	for (int i = 1; i < v2->l + 1; ++i) {
		fscanf(in, "%hhu", &v2->v[i]);
	}
}

unsigned short ** build_matrix (vector *v1, vector *v2) {
	unsigned short **m = new unsigned short *[v1->l + 1];
	for (int i = 0; i < v1->l + 1; ++i) {
		m[i] = new unsigned short[v2->l + 1]();
	}
	
	for (int i = 1; i <= v1->l; ++i) {
		for (int j = 1; j <= v2->l; ++j) {
			if (v1->v[i] == v2->v[j]) {
				m[i][j] = m[i-1][j-1] + 1;
			} else {
				m[i][j] = MAX(m[i-1][j], m[i][j-1]);
			}
		}
	}
	
	return m;
}

vector * findLcs (unsigned short **m, vector *v1, vector *v2) {
	vector *v = new vector;
	v->l = m[v1->l][v2->l];
	
	v->v = new unsigned char[v->l];
	
	int curr = 0;
	for (int i = 1; i <= v1->l; ++i) {
		for (int j = 1; j <= v2->l; ++j) {
			if (m[i][j] > m[i][j-1] && m[i][j] > m[i-1][j]) {
				v->v[curr] = v1->v[i];
				++curr;
			}
		}
	}
	
	return v;
}
		
int main (void) {
	FILE *in = fopen("cmlsc.in", "r");
	
	vector v1, v2;
	
	read(in, &v1, &v2);
	fclose(in);
	
	FILE *out = fopen("cmlsc.out", "w");
	
	unsigned short **m = build_matrix(&v1, &v2); 
	
	fprintf(out, "%d\n", m[v1.l][v2.l]);
	
	vector *lcs = findLcs(m, &v1, &v2);
	
	for (int i = 0; i < lcs->l; ++i) {
		fprintf(out, "%d ", lcs->v[i]);
	}
	
	fclose(out);
	
	
	//delete lcs
	delete[] lcs->v;
	delete[] lcs;
	
	//delete matrix
	for (int i = 0; i < v1.l; ++i) {
		delete[] m[i];
	}
	delete[] m;
	
	//delete sequences
	delete[] v1.v;
	delete[] v2.v;
	
	return 0;
}
