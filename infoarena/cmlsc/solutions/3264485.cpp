/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b) {
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    int n, m, v1[1025], v2[1025],max[1025], iterator = 1;

    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fin >> v1[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> v2[i];
    }

    // aici

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) {
                max[iterator] = v1[i];
                iterator++;
            }
        }
    }
    fout << iterator - 1 << endl;
    for (int i = 1; i <= iterator - 1; i++) {
        fout << max[i] << " ";
    }
    return 0;
}