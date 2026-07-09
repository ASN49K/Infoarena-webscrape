#include <fstream>
#include <iostream>
#include <stack>

#define maxx(a,b) ((a > b) ? a : b)

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

stack <short> sir;

short a, b;
short sa[1025];
short sb[1025];
short mat[1025][1025];

void citire();

void rezolvare() {
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            if(sa[i] == sb[j]) {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else {
                mat[i][j] = maxx(mat[i-1][j], mat[i][j-1]);
            }
        }
    }

//    for(int i = 1; i <= a; ++i) {
//        for(int j = 1; j <= b; ++j) {
//            g << mat[i][j] << ' ';
//        }
//        g << '\n';
//    }
    g << mat[a][b] << '\n';

    int i = a;
    int j = b;

    while(mat[i][j] != 0) {
        if(mat[i-1][j-1] == mat[i][j]) {
            --i;
            --j;
        }  else if (mat[i][j-1] == mat[i][j]) {
            --j;
        } else if (mat[i-1][j] == mat[i][j]) {
            --i;
        } else {
            sir.push(sa[i]);
            --i;
            --j;
        }
    }

    while(!sir.empty()) {
        g << sir.top() << ' ';
        sir.pop();
    }

}

int main()
{
    citire();
    rezolvare();
}

void citire() {
    f >> a >> b;
    for(int i =1; i <= a; ++i) {
        f >> sa[i];
    }

    for(int j = 1; j <= b; ++j) {
        f >> sb[j];
    }
}
