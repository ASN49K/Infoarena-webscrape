#define __USE_FILES__
#ifdef __USE_FILES__
#include <fstream>
std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");
#else
#include <iostream>
std::istream& in = std::cin;
std::ostream& out = std::cout;
#endif

// directive preprocesate
#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <math.h>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = unsigned short;

// declaratie functii

// declaratii variablile
ll M, N, index = 0, indexResult = 0;
ll cnt = 0;
struct el {
    ll val;
    ll grupa;
} lista[2050];
ll result[2050];

int main()
{
    in >> M >> N;
    for (ll i = 0; i < M; ++i) {
        struct el ell;
        in >> ell.val;
        ell.grupa = 1;
        lista[index++] = ell;
    }
    for (ll j = 0; j < N; ++j) {
        struct el ell;
        in >> ell.val;
        ell.grupa = 2;
        lista[index++] = ell;
    }

    std::sort(lista, lista + index, [&](el e1, el e2) { return e1.val < e2.val; });

    // debug
    // for (ll i = 0; i < index; ++i)
    //     out << lista[i].val << ' ';
    // out << '\n';
    // for (ll i = 0; i < index; ++i)
    //     out << lista[i].grupa << ' ';

    // out << '\n'
    //     << "~~~~ SOLUTIE ~~~~\n";
    // debug

    el precedent = lista[0];
    /**
     * !!ATENTIE
     * pentru cazul în care valorile din vectori nu sunt distincte, precum asta:
     *  5 3
     *  1 7 3 9 7
     *  7 5 7
     * algoritmul de fata nu merge
     */
    for (ll i = 1; i < index; ++i) {
        if (precedent.val == lista[i].val && precedent.grupa != lista[i].grupa) {
            // am gasit un numar din cmlsc
            ++cnt;
            result[indexResult++] = lista[i].val;
        }
        precedent = lista[i];
    }
    out << cnt << '\n';
    for (ll i = 0; i < indexResult; ++i)
        out << result[i] << ' ';

    return 0;
}
