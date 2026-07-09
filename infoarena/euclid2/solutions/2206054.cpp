#define 

void update(int st, int dr, int nod, int idx, int val) {
	if (st==dr) {
		H[nod] = val; //nod frunza
		return;
	} 
	int mid = (st+dr)/2;
	//daca idx se contine in intervalul copilului sting - facem recursie pe copilul sting
	//contrar - pe copilul drept
	if (idx<=mid) update(st, mid, 2*nod, idx, val);
	else update(mid+1, dr, 2*nod+1, idx, val);
	
	H[nod] = H[2*nod] + H[2*nod+1]; //nodul intern va contine suma copiilor sai
}



int query(int st, int dr, int nod, int l, int r) {
	//intervalul reprezentat de nod se afla complet in intervalul cautat
	if (l<=st && dr<=r) return H[nod];
	
	int mid = (st+dr)/2;
	int left = 0, right = 0;  
	//daca intervalele reprezentate de copii se suprapun partial/complet
	//cu intervalul cautat returnam suma interogarii pe nodurile respective
	if (l<=mid) left = query(st, mid, 2*nod, l, r);
	if (r>mid) right = query(mid+1, dr, 2*nod+1, l, r);
	return left+right;
}



void build(int st, int dr, int nod) {
	if (st==dr) H[nod] = a[st]; //am ajuns la nod frunza
	else {
		int mid = (st+dr)/2;
		build(st, mid, 2*nod); // recursie pe copilul sting
		build(mid+1, dr, 2*nod+1); //recursie pe copilul drept
	}
}


