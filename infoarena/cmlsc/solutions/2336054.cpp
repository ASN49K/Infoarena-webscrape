#include <bits/stdc++.h>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

stack <short> coada;

short a, b;
short sa[1025];
short sb[1025];
short len[1025];
short mem[1025];

void citire();

void rezolvare() {
    short max_c = 0;
    short elem_c = 0;

    short max_g = 0;
    short elem_g = 0;

    for(int i = 1; i <= b; ++i) {
        max_c = 0;
        for(int j = 1; j <= a; ++j) {
            // Ia lungimea maxima pana la momentul curent
            if(len[j] > max_c) {
                max_c = len[j];
                elem_c = j;
            }
            // Daca gasim elementul din b in a
            if(sa[j] == sb[i]) {
                // Daca nu am mai marcat elementul, il marcam acum
                if (len[j] == 0) {
                    len[j] = max_c + 1;
                    mem[j] = elem_c;
                }
                // Altfel, vedem daca maximul de pana acum merita pus
                // in locul lungimii curente
                else if (len[j] < max_c + 1) {
                    len[j] = max_c + 1;
                    mem[j] = elem_c;
                }
            }
            if (len[j] > max_g) {
                max_g = len[j];
                elem_g = j;
            }
        }
    }

//    for (int i = 1; i <= a; ++i) {
//        g << len[i] << ' ';
//    }
//    g << '\n';
//    for (int i = 1; i <= a; ++i) {
//        g << mem[i] << ' ';
//    }

    g << max_g << '\n';

    while(!mem[elem_g] == 0) {
        // Afiseaza elementul din subsir
        coada.push(sa[elem_g]);
        elem_g = mem[elem_g];
    }
    coada.push(sa[elem_g]);

    while(!coada.empty()) {
       g << coada.top() << ' ';
       coada.pop();
    }
}

int main()
{
    citire();
    rezolvare();
    return 0;
}

void citire() {
    f >> a >> b;
    if(a < b) {
        swap(a, b);
    }

    for(int i = 1; i <= a; ++i) {
        f >> sa[i];
    }

    for(int i = 1; i <= b; ++i) {
        f >> sb[i];
    }
}
