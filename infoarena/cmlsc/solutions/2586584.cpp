#include <iostream>
#include <fstream>
using namespace std;
void ciurul_lui_eratostene(int nr) // i want to implement ciurul lui eratostene. asta iti da care sunt numerele prime mai mici decat n
{
	int i, j, k=0;
	bool prim[nr];
	short prime[nr]= {0};
	prim[0] = prim[1] = false;
	for(i=2;i<nr;i++)
		prim[i] = true;
	for(i=2;i<nr;i++)
	{
		if(prim[i])
		{
			for(j=2;j*i<nr;j++)
			{
				prim[i*j] = false;
			}
			prime[k++] = i;
		}
	}
	for(int i=0;i<k;i++)
		cout<<prime[i]<<" ";
}
int phi(int n)
{
	int i, j;
	long long unsigned sum = 0;
	int p[n+1]={0};
	for(i=2;i<=n;i++)
		p[i] = i; // we set them all to their index value 

	for(i=2;i<=n;i++)
	{
		if(p[i] == i) //if p[i] is prime
		{
			p[i]--; // daca numarul este prim, atunci toate numerele mai mici decat el vor fi prime cu el
			for(j=2*i;j<=n;j+=i)
			{
				p[j] *= (i-1);
				p[j] /= i; // toti multiplii lui i vor avea numarul de numere mai mici si prime cu el egale cu 
			}
		}
	}
	for (int i=2;i<=n;i++)
		sum += p[i];

	sum *= 2;
	sum++;
	return sum;
}
int main()
{
	ifstream in("fractii.in");
	ofstream out("fractii.out");

	int nr;
	in>>nr;
	out<<phi(nr);
	//cout<<get_nr(nr);
}