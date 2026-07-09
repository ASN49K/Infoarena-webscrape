#include <bits/stdc++.h>
using namespace std;
ifstream fin ("scmax.in");
ofstream fout ("scmax.out");

int v[100000], lungimi[100000], iMax, LMax;
stack<int> Galeata;
int main()
{
    int N, i, k;
    fin >> N;
    for(i=0; i<N; i++) fin >> v[i];
    
    for(k=0; k<N; k++)      // o sa facem k verificari
    {
        lungimi[k]=1;        // presupunem ca numarul nou de analizat nu ar apartine niciunui sir
        for(i=0; i<k; i++)
        {
            if(v[i] < v[k]) lungimi[k] = max(lungimi[k], lungimi[i]+1);     
            // daca numarul curent analizat v[k] este mai mare decat v[i],
            // atunci v[k] poate continua sirul lui v[i]
            // max() are rolul de a se asigura ca v[k] va continua sirul cel mai lung
        }
        if(lungimi[k]>LMax)
        {
            LMax = lungimi[k];
            iMax = k;
        }
    }
    fout << LMax << "\n";
    
    for(; iMax>=0; iMax--)     // trecem prin tot vectorul, de la indicele celui mai mare k la 0
    {
        if(lungimi[iMax]==LMax)     // verificam daca un nr. apartine sirului nostru verificand daca lungimi[indice] == indiceMax
        {                           // daca da, il tinem minte si scadem indiceMax, ca sa cautam pe predecesorul lui
            Galeata.push(iMax);
            LMax--;
        }
    }
    
    /*
    for(i=0; i<N; i++) fout << lungimi[i];
    fout << "\n";
    */
    
    while(!Galeata.empty())
    {
        i = Galeata.top();
        fout << v[i] << " ";
        Galeata.pop();
    }
    return 0;
}
