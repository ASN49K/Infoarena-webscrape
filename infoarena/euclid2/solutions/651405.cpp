#include<stdio.h>
#include<algorithm>
#define lim 200001

using namespace std;

FILE * f =fopen("heapuri.in","r");
FILE * g =fopen("heapuri.out","w");

int v[lim], H[lim], P[lim]; 
int n, t, x;

void push(int c)
{
	int t=c*2;
	while (t != 0 && v[H[t]] > v[H[c]])
	{
		swap (H[t], H[c]);
		swap (P[H[t]], P[H[c]]);
		
		c=t;
		t=t*2;		
	}
}

void pop(int t)
{
	int c = t/2;
	if (c+1 <= H[0] && v[H[c+1]] < v[H[c]])
		c++;
	while (c <= H[0] && v[H[c]] < v[H[t]])
	{
		swap (H[t], H[c]);
		swap (P[H[t]], P[H[c]]);
		
		t = c;
		c = t/2;
		if (c+1 <= H[0] && v[H[c+1]] < v[H[c]])
			c++;
	}	
}

int main ()
{
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;i++)
	{
		fscanf(f,"%d",&t);
		if (t==3)
		{
			fscanf(f,"%d",&H[1]);			
		}
		else
		{
			fscanf(f,"%d",&x);
			if (t==1)
			{
				v[++v[0]] = x;
				H[++H[0]] = v[0];
				P[v[0]] = H[0];
				push(H[0]);
			}
			else
			{
				H[P[x]] = H[H[0]];
				P[H[H[0]]] = P[x];
				H[0]--;
				push(P[x]);
				pop(P[x]);
			}			
		}		
	}
	return 0;
}

