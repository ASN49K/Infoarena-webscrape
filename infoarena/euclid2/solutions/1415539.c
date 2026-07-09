#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
	int inf;
	struct nod*next;
} nod;


struct om {

	int inaltime;

};

struct om x;


nod* inserare_last(nod* head, int x) {
	if(head ==  NULL) {
		nod* nou = malloc(sizeof(nod));
		nou->inf = x;
		nou->next = NULL;
		return nou;
	}
	else {
	    nod* d = head;
		while(head->next != NULL)
			head = head->next;
		nod* de_adaugat = malloc(sizeof(nod));

		de_adaugat -> inf = x;
		de_adaugat -> next = NULL;
		head->next = de_adaugat; 

		return d;
	 }
}

void sterge_last(nod* head) {

	while(head -> next -> next != NULL)
		head = head->next;
	nod* to_delete = head-> next;
	head->next = NULL;
	free(to_delete);
}

void afis(nod*  head) {

	while(head != NULL) {
		printf("%d\n" , head->inf );
		head = head-> next;
	}
	printf("\n");
}


int return_last(nod*  head) {

	while(head->next != NULL)
		head = head->next;
	return head->inf;
}
 
void adauga(int a, int b) {

	return a + b;
}

void stergere(int x, nod* head)
{
	while(head->next->inf!=x){
		head=head->next;
	}
	if(head->next->next==NULL){
			nod* k=head->next;
			head->next=NULL;
			
			free(k);
	}
	nod* k=head->next;
	head->next=head->next->next;
	free(k);
}

int main()
{
	//x.intaltime=5;
	nod* primul_nod_lista = NULL;

	// p->inf = 5;
	//(*p).inf = 7; //le fel, sagetica e scriere prescurtat
	primul_nod_lista = inserare_last(primul_nod_lista , 4);

	primul_nod_lista = inserare_last(primul_nod_lista, 2);
	primul_nod_lista = inserare_last(primul_nod_lista, 6);
	primul_nod_lista = inserare_last(primul_nod_lista, 7);


	printf("%d\n", return_last(primul_nod_lista));
	sterge_last(primul_nod_lista);
	printf("%d\n", return_last(primul_nod_lista));

	//afis(primul_nod_lista);
	return 0;

}
