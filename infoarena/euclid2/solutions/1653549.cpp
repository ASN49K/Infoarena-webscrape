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

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int N, st[13], v[13];

void Afisare()
{
  int i;
  for (i=1; i<=N; i++)
   cout << st[i] << " ";
  cout << "\n";
}

void Back(int top)
{
  int i;
  if (top == n+1) Afisare();
  else 
    for (i=1; i<=N; i++)
      if (!v[i])
      {
        st[top] = i;
        v[i] = 1;
        Back(top+1);
        v[i] = 0;
      }
}


int main ()
{
  fin >> N; 
  Back(1);
  fin.close();
  fout.close();
}
/// permutari pur si simplu

------------------------------------------------------------

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int N, st[13], v[13], a[13];

void Afisare()
{
  int i;
  for (i=1; i<=N; i++)
   cout << a[st[i]] << " ";
  cout << "\n";
}

void Back(int top)
{
  int i;
  if (top == n+1) Afisare();
  else 
    for (i=1; i<=N; i++)
      if (!v[i])
      {
        st[top] = i;
        v[i] = 1;
        Back(top+1);
        v[i] = 0;
      }
}


int main ()
{
  fin >> N; 
  for (int i=1; i<=N; i++)
   fin >> a[i];
  Back(1);
  fin.close();
  fout.close();
}
----------------------------------------------------------------------------------
#include<iostream>
#include<fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int N, st[13], v[13];

void Afisare()
{
  int i;
  for (i=1; i<=N; i++)
   cout << st[i] << " ";
  cout << "\n";
}

void Back(int top)
{
  int i;
  if (top == n+1) Afisare();
  else 
    for (i=1; i<=N; i++)
      if (top == 1 || (!v[i] && (i%2 == st[top-1]%2))
      {
        st[top] = i;
        v[i] = 1;
        Back(top+1);
        v[i] = 0;
      }
}


int main ()
{
  fin >> N; 
  Back(1);
  fin.close();
  fout.close();
}

/// permutari care sa nu contina 2 elemente alaturate de aceeasi paritate

---------------------------------------------------------------------------------
#include<iostream>
#include<fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int N, st[13], v[13];

void Afisare()
{
  int i;
  for (i=1; i<=N; i++)
   cout << i << " " st[i] << " ";
  cout << "\n";
}

void Back(int top)
{
  int i;
  if (top == n+1) Afisare();
  else 
    for (i=1; i<=N; i++)
      if (!v[i])
      {
        st[top] = i;
        v[i] = 1;
        Back(top+1);
        v[i] = 0;
      }
}


int main ()
{
  fin >> N; 
  Back(1);
  fin.close();
  fout.close();
}

/// problema turelor

----------------------------------------------------------------------------------
#include<iostream>
#include<fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int N, st[13], v[13];

inline bool Modul(int x)
{
  if (x<0) return (-1)*x;
  return x;
}

void Afisare()
{
  int i;
  for (i=1; i<=N; i++)
   cout << i << " " st[i] << " ";
  cout << "\n";
}

int Valid (int top, int i)
{
   if (v[i] == 1) 
     return 0;     

   for (int j=1; j<=top; j++)
     if (Modul(top, j) == Modul(i, st[j]) 
          return 0;
   return 1;
}


void Back(int top)
{
  int i;
  if (top == n+1) Afisare();
  else 
    for (i=1; i<=N; i++)
      if (Valid(top, i) == 1)
      {
        st[top] = i;
        v[i] = 1;
        Back(top+1);
        v[i] = 0;
      }
}


int main ()
{
  fin >> N; 
  Back(1);
  fin.close();
  fout.close();
}

/// problema damelor


---------------------------------------------------------------------------------------------
/// initial 1, 2, 3 .... n 
/// sa se rearanjeze camilele astfel incat fiecare camila sa aiba IN FATA o camila diferita de configuratia initiala

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int N, st[13], v[13];

void Afisare()
{
  int i;
  for (i=1; i<=N; i++)
   cout << st[i] << " ";
  cout << "\n";
}


void Back(int top)
{
  int i;
  if (top == n+1) Afisare();
  else 
    for (i=1; i<=N; i++)
      if (top == 1 || (v[i] !=0  &&  st[top-1] != i-1))
      {
        st[top] = i;
        v[i] = 1;
        Back(top+1);
        v[i] = 0;
      }
}


int main ()
{
  fin >> N; 
  Back(1);
  fin.close();
  fout.close();
}

------------------------------------------------------------------------------------------------

684. sa se genereze toate numerele de n cifre cu aceleasi cifre
     permutari cu repetitie


#include<iostream>
#include<fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int N, st[13], f[13];

void Afisare()
{
  int i;
  for (i=1; i<=N; i++)
   cout << i << " " st[i] << " ";
  cout << "\n";
}


void Back(int top)
{
  int i;
  if (top == n+1) Afisare();
  else 
    for (i=0; i<=9; i++)
      if (f[i]>0)
      {
        st[top] = i;
        f[i]--;
        Back(top+1);
        f[i]++;
      }
}


int main ()
{
  fin N;
  for (int i=1; i<=N; i++)
  {
     fin >> x;
     f[x]++;    //// vector de frecventa
  } 

  Back(1);
  fin.close();
  fout.close();
}

-------------------------------------------------------------------------------------------------
*/
