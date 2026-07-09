

void updateRange(int st, int dr, int nod, int val) {
	if (lazy[nod]) { //daca exista actualizare in asteptare p-ru elementul respectiv 
		if (st!=dr) {
			//Propagam actualizarea in asteptare la copii nodului (daca nodul nu-i frunza)
			lazy[2*nod]+=lazy[nod];
			lazy[2*nod+1]+=lazy[nod];
		}
		//actualizam elemntul din arbore cu valoarea corespunzatoare lui din tabloul ajutator 
		H[nod] += (dr-st+1)*lazy[nod];
		lazy[nod] = 0;
	}
	if (st>r || dr<l) return; //segmentul resepectiv nu intra in intervalul [l, r]
	
	if (l<=st && dr<=r) {
		//segmentul intra complet in [l, r]
		H[nod]+=val;
		if (st!=dr) {
			//daca nodul nu-i nod terminal
			lazy[2*nod]+=val;
			lazy[2*nod+1]+=val;
		}
		return;
	}
	
	int mid = (st+dr)/2;
	updateRange(st, mid, 2*nod, val);
	updateRange(mid+1, dr, 2*nod+1, val);
	H[nod] = H[2*nod] + H[2*nod + 1];
}



int queryRange(int st, int dr, int nod, int l, int r) {
	if (st>r || st>dr || dr<l) return 0; //segmentul nu intra in intervalul [l, r]
	
	if (lazy[nod]) {
		//actualizam nodul tinind cont de valorile din tabloul ajutator lazy[]
		H[nod] += (dr-st+1)*lazy[nod];
		if (st!=dr) {
			lazy[2*nod] += lazy[nod];
			lazy[2*nod + 1] += lazy[nod];
		}
		lazy[nod] = 0;
	}
	
	if (l<=st && dr<=r) return H[nod]; //HMARE
	int mid = (st+dr)/2;
	int left = 0, right = 0;
	left = queryRange(st, mid, 2*nod, l, r); //l r parametru
	right = queryRange(mid+1, dr, 2*nod+1, l, r);
	return (left + right);
}

