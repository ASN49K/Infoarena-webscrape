#include<iostream>
#include<fstream>
using namespace std;
ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");
int main ()
{
  int i, T, x, y, r;
  fin >> T;
  for (int i=1; i<=T; i++)
  {
    fin >> x >> y;
    while (y!=0)
    {
       r = x%y;
       x = y;
       y = r;
    }
    fout << x << "\n";
  }
  fin.close();
  fout.close();
  return 0;
}
/*


#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
ifstream fin  ("elicoptere.in");
ofstream fout ("elicoptere.out");

struct coord{
   int x1, y1, x2, y2, x3, y3;
};

struct noduri{
   int    nod;
   double cost;
};

struct lista{
   int x, y;
   double cost;
};

vector <noduri> L[110];
bool  viz[110];
int v[110];
coord a[110];
vector <lista> b;
int N, k, vv, nr_comp_conexe, nr_elemente_conexe_din_componenta_prezenta, value;
int t[110], c[110];

inline double Modul(double x)
{
    if (x < 0) return (-1)*x;
    return x;
}

inline bool cmp(const lista nr1, const lista nr2)
{
   return (nr1.cost < nr2.cost);
}

inline int Find(int x)
{
    int y, z;
    while (t[x]!=0)
        x = t[x];
    while (t[y]!=0)
    {
        z = t[y];
        t[y] = x;
        y = z;
    }
    return x;
}

inline void Union (int x, int y)
{
    if (c[x] > c[y])
    {
        c[x] += c[y];
        c[y] = 0;
        t[y] = x;
    }
    else
    {
        c[y] += c[x];
        c[x] = 0;
        t[x] = y;
    }
}

inline double Cost(int x1, int y1, int x11, int y11, int x22, int y22, int tip)
{
    double a, b;
    double x, y;

    if (tip == 0)   /// orizontala
    {
        if ((y1 >= y22 && y1 <= y11) || (y1 <= y22 && y1 >= y11))
       {
           if (x22 == x11) x = x11;
    else { a = (y22 - y11)/(x22 - x11);  b = y11 - a*x11;
           x = (y11 - b)/a;
         }
         return (Modul(x-x1));
       }
       else return (k+10);
    }
    else            /// verticala
    {
        if ((x1 <= x11 && x1 >= x22) || (x1 >= x11 && x1 <= x22))
      {
         if (x22 == x11) 
         { 
           if (y1 <= y11 && y1 <= y22)
           y = min(y11, y22);
           if (y1 >= y11 && y1 >= y22)
           y = max(y11, y22);
         }
   else {
        a = (y22 - y11)/(x22 - x11); b = y11 - a*x11;
        y = a*x1 + b;
        }
        return (Modul(y-y1));
      }
        else return (k+10);
     }
}

inline double Merge(int x1, int y1, int x2, int y2, int x3, int y3, int x11, int y11, int x22, int y22, int x33, int y33)
{
    double cost, d;
    cost = k + 0.001;
    d = cost;

    cost = min (cost, Cost(x1, y1, x11, y11, x22, y22, 0));
    cost = min (cost, Cost(x1, y1, x11, y11, x33, y33, 0));
    cost = min (cost, Cost(x1, y1, x22, y22, x33, y33, 0));
    cost = min (cost, Cost(x2, y2, x11, y11, x22, y22, 0));
    cost = min (cost, Cost(x2, y2, x11, y11, x33, y33, 0));
    cost = min (cost, Cost(x2, y2, x22, y22, x33, y33, 0));
    cost = min (cost, Cost(x3, y3, x11, y11, x22, y22, 0));
    cost = min (cost, Cost(x3, y3, x11, y11, x33, y33, 0));
    cost = min (cost, Cost(x3, y3, x22, y22, x33, y33, 0));

    cost = min (cost, Cost(x1, y1, x11, y11, x22, y22, 1));
    cost = min (cost, Cost(x1, y1, x11, y11, x33, y33, 1));
    cost = min (cost, Cost(x1, y1, x22, y22, x33, y33, 1));
    cost = min (cost, Cost(x2, y2, x11, y11, x22, y22, 1));
    cost = min (cost, Cost(x2, y2, x11, y11, x33, y33, 1));
    cost = min (cost, Cost(x2, y2, x22, y22, x33, y33, 1));
    cost = min (cost, Cost(x3, y3, x11, y11, x22, y22, 1));
    cost = min (cost, Cost(x3, y3, x11, y11, x33, y33, 1));
    cost = min (cost, Cost(x3, y3, x22, y22, x33, y33, 1));

    cost = min (cost, Cost(x11, y11, x1, y1, x2, y2, 0));
    cost = min (cost, Cost(x11, y11, x1, y1, x3, y3, 0));
    cost = min (cost, Cost(x11, y11, x2, y2, x3, y3, 0));
    cost = min (cost, Cost(x22, y22, x1, y1, x2, y2, 0));
    cost = min (cost, Cost(x22, y22, x1, y1, x3, y3, 0));
    cost = min (cost, Cost(x22, y22, x2, y2, x3, y3, 0));
    cost = min (cost, Cost(x33, y33, x1, y1, x2, y2, 0));
    cost = min (cost, Cost(x33, y33, x1, y1, x3, y3, 0));
    cost = min (cost, Cost(x33, y33, x2, y2, x3, y3, 0));

    cost = min (cost, Cost(x11, y11, x1, y1, x2, y2, 1));
    cost = min (cost, Cost(x11, y11, x1, y1, x3, y3, 1));
    cost = min (cost, Cost(x11, y11, x2, y2, x3, y3, 1));
    cost = min (cost, Cost(x22, y22, x1, y1, x2, y2, 1));
    cost = min (cost, Cost(x22, y22, x1, y1, x3, y3, 1));
    cost = min (cost, Cost(x22, y22, x2, y2, x3, y3, 1));
    cost = min (cost, Cost(x33, y33, x1, y1, x2, y2, 1));
    cost = min (cost, Cost(x33, y33, x1, y1, x3, y3, 1));
    cost = min (cost, Cost(x33, y33, x2, y2, x3, y3, 1));

    if (cost >= d)
        return -1;
    else
        return cost;
}

void DFS(int k)
{
    int i;
    viz[k] = 1;
    for (int j=0; j<L[k].size(); j++)
    {
        i = L[k][j].nod;
        if (!viz[i]) DFS(i);
    }
}

void DFS2(int k)
{
    int i;
    viz[k] = 1;
    nr_elemente_conexe_din_componenta_prezenta++;
    for (int j=0; j<L[k].size(); j++)
    {
        i = L[k][j].nod;
        if (!viz[i])
            DFS2(i);
    }
}

void DFS3(int k)
{
    int i;
    v[k] = value;
    for (int j=0; j<L[k].size(); j++)
    {
        i = L[k][j].nod;
        if (!v[i])
            DFS3(i);
    }
}

void Citire()
{
   fin >> vv >> N >> k;
   for (int i=1; i<=N; i++)
       fin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].x3 >> a[i].y3;
}

void Construire_Liste()
{
   int i, j, x1, y1, x2, y2, x3, y3, x11, y11, x22, y22, x33, y33;
   double cost;
   noduri w, w1;
   for (i=1; i<N; i++)
   {
       x1 =  a[i].x1;   y1 =  a[i].y1;
       x2 =  a[i].x2;   y2 =  a[i].y2;
       x3 =  a[i].x3;   y3 =  a[i].y3;
       /// coordonatele varfurilor primului triunghi

       for (j=i+1; j<=N; j++)
       {
           x11 =  a[j].x1;   y11 =  a[j].y1;
           x22 =  a[j].x2;   y22 =  a[j].y2;
           x33 =  a[j].x3;   y33 =  a[j].y3;
       /// coordonatele varfurilor celui de-al doilea triunghi

          cost = Merge(x1, y1, x2, y2, x3, y3, x11, y11, x22, y22, x33, y33);
          if (cost != -1)
          {
             /// cout << cost << endl;
              cout << "avem muchie de la " << i << " la " << j << endl;
              w.nod  = j;
              w.cost = cost;
              L[i].push_back(w);
              w.nod  = i;
              L[j].push_back(w);
          }
       }
   }
}

void Rezolva_1()
{
    int i;
    /// se numara componentele conexe
    nr_comp_conexe = 1;
    for (i=1; i<=N; i++)
      {  if (!viz[i])
        {
            DFS(i);
            nr_comp_conexe++;
        }
      }
    fout << nr_comp_conexe << "\n";
}

void Rezolva_2()
{
    int cnt;
    /// se numara componentele conexe
    nr_elemente_conexe_din_componenta_prezenta = 0; cnt = 0;
    for (int i=1; i<=N; i++)
        if (!viz[i])
        {
            cout << "in componenta conexa cu numarul " << i << " avem ";
            nr_elemente_conexe_din_componenta_prezenta = 0;
            DFS2(i);
            cout << nr_elemente_conexe_din_componenta_prezenta << " muchii\n";
            cnt = cnt + (nr_elemente_conexe_din_componenta_prezenta * (nr_elemente_conexe_din_componenta_prezenta-1))/2;
        }
    fout << cnt << "\n";
}

void Rezolva_3()
{
    /// vom face APM pentru fiecare componenta conexa a grafului in parte
    /// se face lista cu nod1, nod2, cost
    /// se sorteaza crescator dupa cost
    /// se ia si se face Find si Union pe cat de multe se poate pana se formeaza arborele
    lista w;
    /// hai sa ne distram, facem dinamica lista si o golim de fiecare data
    for (int i=1; i<=N; i++)
    {
        if (!v[i])
        {
            value++;
            DFS3(i);
        }
    }
    /// asta imi umple vectorul static v[] cu valori ca sa pot lucra mai departe

    /// le luam pe rand pe toate.
    int i, j, maxim, nr, x, y;
    double suma = 0;
    maxim = -2;
    for (i=1; i<=N; i++)
        maxim = max(maxim, v[i]);

    for (nr=1; nr<=maxim; nr++)
    {
        /// sunt la componenta cu numarul nr
        while (!b.empty())
            b.pop_back();
        for (i=1; i<=N; i++)
        {
            t[i] = 0; c[i] = 1;
        }

        for (i=1; i<=N; i++)
        {
            if (v[i] == nr)
            {
                for (j=0; j<L[i].size(); j++)
                {
                   w.x = i; w.y = L[i][j].nod; w.cost = L[i][j].cost;
                   b.push_back(w);
                }
            }
            sort (b.begin(), b.end(), cmp);
        }

        for (j=0; j<b.size(); j++)
        {
            x = b[j].x;   y = b[j].y;
            x = Find(x);  y = Find(y);
            if (x != y)
            {
                Union(x, y);
                suma += b[j].cost;
            }
        }
    }

    fout << suma << "\n";
}

int main ()
{
    Citire();
    Construire_Liste();
    if      (vv == 1)   Rezolva_1();
    else if (vv == 2)   Rezolva_2();
    else                Rezolva_3();
    system("pause");
    fin.close();
    fout.close();
    return 0;
}

*/
