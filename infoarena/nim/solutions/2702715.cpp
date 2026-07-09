#include <iostream>
#include <fstream>

using namespace std;
/**
Se dau n grămezi, fiecare conţinând un anumit număr de pietre. Doi jucători vor începe să ia alternativ din pietre, astfel: la fiecare pas, jucătorul
aflat la mutare trebuie să îndepărteze un număr nenul de pietre dintr-o singură grămadă. Câştigătorul este cel care ia ultima piatră.

Cerinţă
Pentru t configuraţii de joc date, să se determine dacă jucătorul care ia primele pietre are strategie sigură de câştig.

Date de intrare
Pe prima linie a fişierului de intrare nim.in se va afla numărul t de configuraţii. Pe următoarele 2*t linii se vor afla descrierile jocurilor, astfel:
pe linia 2*i se va afla numărul ni de grămezi care alcătuiesc jocul i, iar pe linia 2*i+1 se vor afla ni numere, dimensiunile grămezilor.

Date de ieşire
În fişierul de ieşire nim.out se vor afişa t linii, pe linia i aflându-se mesajul "DA", dacă primul jucător are strategie sigură de câştig in jocul i,
respectiv "NU", în caz contrar.

Restricţii
1 ≤ t ≤ 100
1 ≤ ni ≤ 10 000
Numărul de pietre din oricare grămadă este natural pozitiv mai mic sau egal cu 2 * 10^9*/

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int T, N, x, S;
    f >> T;    ///nr de jocuri
    while ( T-- )
    {
        f >> N;  ///nr de gramezi de pietre
        S = 0;
        while ( N-- )
        {
            f >> x;
            S ^= x;
        }
        g << ( S != 0 ? "DA\n" : "NU\n" );
    }
    f.close();
    g.close();
    return 0;
}
