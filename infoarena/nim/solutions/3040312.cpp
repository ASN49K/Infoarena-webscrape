/**
Jocul NIM este un joc matematic strategic pentru doi jucători. În NIM, există mai multe grămezi de obiecte (de obicei, piese, pietre sau bețe) și jucătorii își iau rândul pentru a lua orice număr de obiecte dintr-o singură grămadă. Scopul jocului este de a forța adversarul să ia ultimul obiect. Jucătorul care ia ultimul obiect pierde.

Regulile jocului NIM sunt:

Există un număr finit de grămezi, fiecare cu un număr finit de obiecte.
Jucătorii își iau rândul și pot lua orice număr de obiecte dintr-o singură grămadă în timpul unui singur tur.
Jucătorul care ia ultimul obiect pierde.

Acest program C++ simulează jocul NIM pentru două persoane.
Grămezile inițiale sunt definite în variabila piles.
Jucătorii trebuie să introducă numărul grămezii și
numărul de obiecte pe care doresc să le ia în timpul unui tur.
Programul se încheie atunci când unul dintre jucători câștigă
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
// Functie care returneaza valoarea XOR a tuturor elementelor din vector
int nim_sum(const vector<int>& piles) {
    int nim_sum = 0;
    for (int pile : piles) {
        nim_sum ^= pile;
    }
    return nim_sum;
}
void citeste(vector<int>& v, int &n){
    fin>>n;
    int x;
    v.resize(n);
    for(int i=0;i<n;i++){
        fin>>v[i];
    }
}
int main() {
    int T,n;
    vector<int> v;
    fin>>T;
    for(int i=1;i<=T;i++){
        citeste(v,n);
        if(nim_sum(v)==0) fout<<"NU"<<'\n';
        else              fout<<"DA"<<'\n';
    }

/** simulare NIM
    vector<int> piles = {3, 4, 5}; // Grămezile inițiale
    int currentPlayer = 0;

    while (true) {
        cout << "Gramezile: ";
        for (int pile : piles) {
            cout << pile << " ";
        }
        cout << endl;

        int pileIdx, objects;
        cout << "Jucator " << currentPlayer + 1 << ", alege gramada si numărul de obiecte: ";
        cin >> pileIdx >> objects;

        if (pileIdx < 0 || pileIdx >= piles.size() || objects <= 0 || objects > piles[pileIdx]) {
            cout << "Mutare invalidă. Încearcă din nou." << endl;
            continue;
        }

        piles[pileIdx] -= objects;

        if (nim_sum(piles) == 0) {
            cout << "Jucator " << currentPlayer + 1 << " a castigat!" << endl;
            break;
        }

        currentPlayer = 1 - currentPlayer; // Schimbă jucătorul
    }
*/
    return 0;
}
