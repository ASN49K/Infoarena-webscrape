#include <cstdio>
#include <stack>
using namespace std;

int input1[1024], input2[1024], n, m;
int counter[1025][1025];
stack<int> c;

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
            }
            else {
                counter[i][j] = (counter[i - 1][j] > counter[i][j - 1]) ? counter[i - 1][j] : counter[i][j - 1];
            }
        }
    }
}

void write() {
    FILE *g = fopen("cmlsc.out", "w");

    int pozi = n, pozj = m;
    fprintf(g, "%i\n", counter[pozi][pozj]);
    while (counter[pozi][pozj] != 0) {
        while (counter[pozi - 1][pozj] == counter[pozi][pozj]) pozi--;
        while (counter[pozi][pozj - 1] == counter[pozi][pozj]) pozj--;
        //fprintf(g, "%i ", input1[pozi - 1]);
        c.push(input1[pozi - 1]);
        pozi--;
        pozj--;
    }
    while(!c.empty()) {
        fprintf(g, "%i ", c.top());
        c.pop();
    }
}

int main() {
	read();
	process();
	write();
}
