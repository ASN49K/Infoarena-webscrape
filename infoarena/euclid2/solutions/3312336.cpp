/*Algoritmul lui Euclid
  Cel mai mare divizor comun dintre doua numere naturale a si b este cel mai mare numar natural pozitiv d care divide ambele numere.

  Cerinta
  Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche in parte.

  Date de intrare
  Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi. Urmatoarele T linii contin cate doua numere naturale a si b.

  Date de iesire
  In fisierul de iesire euclid2.out se vor scrie T linii. A i-a linie din acest fisier contine cel mai mare divizor comun al numerelor din perechea de pe linia i+1 din fisierul de intrare.

  Restrictii
  1 ≤ T ≤ 100 000
  Pentru fiecare pereche, 2 ≤ a, b ≤ 2 * 10^9
*/

#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int CMMDC (int a,int b){

  while(b){
    int c=a%b;
    a=b;
    b=c;
  }
  
  return a;
}
int T, a, b, c;
int main() {
  f>>T;
  while (T){
    f>>a>>b;
    g<<CMMDC(a,b)<<'\n';
    --T;
  }
  
  return 0;
}

// https://infoarena.ro/problema/euclid2
// https://infoarena.ro/problema/ciur
// https://infoarena.ro/problema/sdo
// https://www.infoarena.ro/problema/alibaba 
// https://infoarena.ro/problema/cautbin
// https://www.pbinfo.ro/probleme/277/varfuri 