#include<stdio.h>
#include<math.h>
FILE*f=fopen("ghinion.in","r");
FILE*g=fopen("ghinion.out","w");
int s,X[30],n,k,v[300],S,x[20],H[20],m,V[10],q,W[10000];

void init(int H[], int P) {
    H[0] = 0;
    while (P) {
        ++H[0];
        H[H[0]] = P % 10;
        P /= 10;
    } 
}

void Add(int A[], int B[]){
	int i,T=0;

    if (B[0]>A[0]){
		for (i=A[0]+1;i<=B[0];) A[i++]=0;
        A[0]=B[0];
    }else 
		for (i=B[0]+1;i<=A[0];)
			B[i++]=0;
    for (i=1;i<=A[0];i++){ 
		A[i]+=B[i]+T;
        T=A[i]/10;
        A[i]%=10;
    }
    if (T) A[++A[0]]=T;
}
int cont(int k) {
	if (X[k]<X[k-1])
		return 0;
	return 1;
}
void tipar(int k) {
	int j;
	for(j=1;j<=m*9;j++)
		v[j]=0;
	s=0;
	for(j=1;j<=m;j++,s+=X[j]);
	v[0]=1;
	for(j=1;j<=m;j++)
		for(int l=s/2;l>=0;l--)
			if(v[l]==1)
				v[l+X[j]]=1;
}
void back(int k) {
	int j;
	int i;
	if (k>m) {
		tipar(m);
		if(v[s/2]==1&&s%2==0){
			S=0;
			//if(s==0)
			//	S++;
			for(j=0;j<=9;j++)
				V[j]=0;
			for(j=1;j<=m;j++)
				V[X[j]]++;
			for(j=2;j<=m;j++){
				int r=j;
				q=0;
				while(r<=m){
					q+=m/r;
					r*=j;
				}
				for(int l=0;l<=9;l++){
					r=j;
					while(r<=V[l]){
						q-=V[l]/r;
						r*=j;
					}
					
				}
				S+=pow(j,q);
				
			}
			init(H,S);
			Add(W,H);
		}
	} else {
		
		for (i=0;i<=n;i++) {
			X[k]= i;
			if (cont(k))
				back(k+1);
		}
		
		
	}
	
}



int main() {
	for(int j=2;j<=19;j++)
		if(!x[j])
			for(int l=j+j;l<=19;l+=j)
				x[l]=1;
	fscanf(f,"%d%d",&m,&n);
	back(1);
	int j;
	for(j=W[0];j;j--)
		fprintf(g,"%d",W[j]);
	
	fclose(g);
	fclose(f);
	return 0;
}
