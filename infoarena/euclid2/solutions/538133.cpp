#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 50005;
const int INF = 1000000;

int N, M;
vector< pair<int, int> > G[MAXN];//tin minte muchiiile si costul (practic vecinii si costurile -un fel de lista de vecini)
int Dmin[MAXN];//Distanta minima pana la un nod

void citeste() {
   ifstream fin("dijkstra.in");

  fin >> N >> M;
   for (int i = 0; i < M; ++i) {
       int a, b, c;
 
        fin >> a >> b >> c;
       G[a].push_back(make_pair(b, c));//vecinul lui a este b iar costul arcului (a,b) este c
    }
}
 
void dijkstra() {
   bool viz[MAXN];// tipul bool (prescurtarea de la boolean poate lua valoarea true sau false
                // este deci mai convenabil(din punct de vedere al memoriei folosite) sa folosim bool in de int(4 octeti)
                   
    queue<int> Q;  //queue =coada
 
    memset(Dmin, INF, sizeof(Dmin));//pune in memorie incepand cu adresa de memorie Dmin valoarea INF pentru sizeof(Dmin) locatii
    memset(viz, false, sizeof(viz));//umple vectorul viz cu false -analog cu intructiunea de mai sus

     
 
 
 
    Dmin[1] = 0;
    Q.push(1);// Q.push(x) adauga pe x in coada(strcutura de tip FIFO)
   viz[1] = true;

    while (!Q.empty()) {  //cat timp coada nu s-a golit
       int nod = Q.front(); //retinem in nod primul element din coada (care asteapta sa fie servit)
        Q.pop();           //eliminam primul element din  coada
       viz[nod] = false;
//vector< pair<int, int> >::iterator it   -NU VA SPERIATI
// it este un iterator folosit pentru a parcurge itemii din vector
// este la fel ca si o variabila numai ca ii spunem ca va parcurge valori de tipul vector< pair<int, int> >
 
        //reamintim ca in G[nod][] retinem vecinii lui nod impreuna cu costurile aferente distantei de la nod la vecin
        //it = G[nod].begin() iteratorul cu numele it va retine inceputul listei de vecini a nodului nod
        // G[nod].end() =capatul listei de vecini a lui nod
        for (vector< pair<int, int> >::iterator it = G[nod].begin(); it != G[nod].end(); ++it)
            if (Dmin[nod] + it->second < Dmin[it->first]) {
                Dmin[it->first] = Dmin[nod] + it->second;
               if (!viz[it->first]) {
                   Q.push(it->first);
                    viz[it->first] = true;
              }
           }
   }
}
 
void afisare() {
    ofstream fout("dijkstra.out");
 
    for (int i = 2; i <= N; ++i)
       fout << (Dmin[i] < INF ? Dmin[i] : 0) << " ";
}

int main() {
    citeste();
    dijkstra();
   afisare();
}
