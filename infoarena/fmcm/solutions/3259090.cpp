#include <fstream>
#include <queue>
using namespace std;

ifstream cin ("fmcm.in");
ofstream cout ("fmcm.out");

struct Muchie { int nod_vecin , capacitate , cost , urmatorul; } muchii[25000];
int numar_noduri , numar_muchii , inceput , sfarsit , capat[351] , distanta[351] , __distanta[351] , initial[351];
pair <int , int> nod_sursa[351];

inline void Bellman_Ford ()
{
    for (int indice = 1 ; indice <= numar_noduri ; indice++)
        { distanta[indice] = 1000000000; }

    queue <int> candidati;
    bool in_coada[351] = { };
    for (candidati.push(inceput) , distanta[inceput] = 0 , in_coada[inceput] = true ; !candidati.empty() ; candidati.pop())
    {
        const int nod_actual = candidati.front();
        for (int indice = capat[nod_actual] ; indice != -1 ; indice = muchii[indice].urmatorul) {
            if (distanta[muchii[indice].nod_vecin] > distanta[nod_actual] + muchii[indice].nod_vecin)
            {
                distanta[muchii[indice].nod_vecin] = distanta[nod_actual] + muchii[indice].cost;
                if (!in_coada[muchii[indice].nod_vecin])
                    { candidati.push(muchii[indice].nod_vecin); in_coada[muchii[indice].nod_vecin] = true; }
            }
        }

        in_coada[nod_actual] = false;
    }
}

inline bool Dijkstra ()
{
    for (int indice = 1 ; indice <= numar_noduri ; indice++)
        { __distanta[indice] = 1000000000; }

    priority_queue < pair <int , int> > candidati;
    candidati.push({__distanta[inceput] = 0 , inceput});
    while (!candidati.empty())
    {
        const int nod_actual = candidati.top().second;
        if (__distanta[nod_actual] != -candidati.top().first)
            { candidati.pop(); continue; }

        candidati.pop();
        for (int indice = capat[nod_actual] ; indice != -1 ; indice = muchii[indice].urmatorul) 
        {
            const int cost = distanta[nod_actual] + muchii[indice].cost - distanta[muchii[indice].nod_vecin];
            if (muchii[indice].capacitate && __distanta[muchii[indice].nod_vecin] > __distanta[nod_actual] + cost)
            { 
                nod_sursa[muchii[indice].nod_vecin] = {nod_actual , indice}; 
                candidati.push({-(__distanta[muchii[indice].nod_vecin] = __distanta[nod_actual] + cost) , muchii[indice].nod_vecin}); 
                initial[muchii[indice].nod_vecin] = initial[nod_actual] + muchii[indice].cost;
            }
        }
    }

    return __distanta[sfarsit] != 1000000000;
}

int main ()
{
{   int __numar_muchii;
    cin >> numar_noduri >> __numar_muchii >> inceput >> sfarsit;

    for (int indice = 1 ; indice <= numar_noduri ; indice++)
        { capat[indice] = -1; }

    while (__numar_muchii--)
    {
        int nod[2] , capacitate , cost;
        cin >> nod[0] >> nod[1] >> capacitate >> cost;
        
        muchii[numar_muchii].nod_vecin = nod[1];
        muchii[numar_muchii].capacitate = capacitate;
        muchii[numar_muchii].cost = cost;
        muchii[numar_muchii].urmatorul = capat[nod[0]];
        capat[nod[0]] = numar_muchii++;
        
        muchii[numar_muchii].nod_vecin = nod[0];
        muchii[numar_muchii].capacitate = 0;
        muchii[numar_muchii].cost = -cost;
        muchii[numar_muchii].urmatorul = capat[nod[1]];
        capat[nod[1]] = numar_muchii++;
    }
}
    Bellman_Ford();
    int64_t rezultat = 0;
    while (Dijkstra()) 
    {
        int termen = 1000000000;
        for (int nod_actual = sfarsit ; nod_actual != inceput ; nod_actual = nod_sursa[nod_actual].first)
            { termen = min(termen , muchii[nod_sursa[nod_actual].second].capacitate); }

        rezultat += (int64_t)termen * initial[sfarsit];
        for (int nod_actual = sfarsit ; nod_actual != inceput ; nod_actual = nod_sursa[nod_actual].first)
        { 
            muchii[nod_sursa[nod_actual].second].capacitate -= termen; 
            muchii[nod_sursa[nod_actual].second ^ 1].capacitate += termen;
        }
    }

    cout << rezultat;
    cout.close(); cin.close();
    return 0;
}