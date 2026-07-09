#include <cstdio>
using namespace std;

int input1[1024], input2[1024], n, m;
int counter[1025][1025];
int longest = 0;

void read() {
    FILE *f = fopen("cmlsc.in", "r");

    fscanf(f, "%i%i", &n, &m);
    for (int i = 0; i < n; i++) fscanf(f, "%i", &input1[i]);
    for (int i = 0; i < m; i++) fscanf(f, "%i", &input2[i]);
}

void process() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (input1[i - 1] == input2[j - 1]) {
                counter[i][j] = counter[i - 1][j - 1] + 1;
                longest = (longest > counter[i][j]) ? longest : counter[i][j];
            }
            else {
                counter[i][j] = (counter[i - 1][j] > counter[i][j - 1]) ? counter[i - 1][j] : counter[i][j - 1];
            }
        }
    }

    /*for (int i = 0; i <= n; i++) {
        for (int j = 0 ; j <= m ; j++) {
            printf("%i ", counter[i][j]);
        }
        printf("\n");
    }*/
}

void write() {
    FILE *g = fopen("cmlsc.out", "w");

    fprintf(g, "%i\n", longest);

    int before = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (before < counter[i][j]) {
                before = counter[i][j];
                fprintf(g, "%i ", input1[i - 1]);
                i++;
            }
        }
    }
}

int main() {
	read();
	process();
	write();
}
