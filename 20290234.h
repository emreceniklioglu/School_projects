#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};


void insertFB(struct nodeFB** head, int id, int age){
	
	if(*head == NULL ){
		struct nodeFB *newFB = (struct nodeFB *)malloc(sizeof(struct nodeFB));
		newFB->id = id;
		newFB->age = age;
		newFB->next = NULL;
		*head = newFB;
	}
	
	
	else{
		struct nodeFB *newFB = (struct nodeFB *)malloc(sizeof(struct nodeFB));
		newFB->id = id;
		newFB->age = age;
		newFB->next = NULL;
		struct nodeFB *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newFB;
	}

}

void insertGS(struct nodeGS** head, int id){
	
	
	if(*head == NULL ){
		struct nodeGS *newGS = (struct nodeGS *)malloc(sizeof(struct nodeGS));
		newGS->id = id;
		newGS->next = NULL;
		*head = newGS;
	}
	
	
	else{
		struct nodeGS *newGS = (struct nodeGS *)malloc(sizeof(struct nodeGS));
		newGS->id = id;
		newGS->next = NULL;
		struct nodeGS *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newGS;
	}
}


void printFB(struct nodeFB* startFB){
	
	struct nodeFB *current = startFB, *index = NULL;
	int idtemp,agetemp;
	
	if (startFB == NULL) {
	return;
	} 
	else {
	while (current != NULL) {
	
	index = current->next;
	
	while (index != NULL) {	
	if (current->id > index->id) {
	  idtemp = current->id;
	  agetemp = current->age;
	  current->id = index->id;
	  current->age = index->age;
	  index->id = idtemp;
	  index->age = agetemp;
	}
	index = index->next;
	}
	current = current->next;
	}
  }
	
	
	struct nodeFB *temp = startFB;
	while(temp!=NULL){
		printf("%d %d\n",temp->id,temp->age);
		temp = temp->next;
	}
	printf("\n");	
}

void printGS(struct nodeGS* startGS){
	
  struct nodeGS *current = startGS, *index = NULL;
  int temp;

  if (startGS == NULL) {
  	return;
  } 
  else {
  while (current != NULL) {
  	
    index = current->next;

    while (index != NULL) {
    if (current->id < index->id) {
      temp = current->id;
      current->id = index->id;
      index->id = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
	
	
	
	
	struct nodeGS *temp2 = startGS;
	while(temp2!=NULL){
		printf("%d\n",temp2->id);
		temp2 = temp2->next;
	}
	
	printf("\n");
}
void createFinalList(struct newNodeFB** startNewFB,struct nodeFB* startFB,struct nodeGS* startGS){
	struct newNodeFB *beg = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
	struct newNodeGS *sec = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));

	
	beg->id = startFB->id;
	beg->age = startFB->age;
	sec->id = startGS->id;
	*startNewFB = beg;
	struct newNodeFB* fn = *startNewFB;
	fn->next = sec;
	
	struct nodeGS *tempgs = startGS->next; //gsnin 2.elemanı
	struct nodeFB *tempfb = startFB->next; //fbnin 2.elemanı
	
	while(tempgs->next != NULL){
		struct newNodeFB* newFB = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
		newFB->id = tempfb->id;
		newFB->age = tempfb->age;
		sec->next = newFB;
		
		struct newNodeGS* newGS = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));
		newGS->id = tempgs->id;
		newFB->next = newGS;
		newGS->next = NULL;
		
		tempgs = tempgs->next;
		tempfb = tempfb->next;
		sec = newGS;
	}
	struct newNodeFB* newFB = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
		newFB->id = tempfb->id;
		newFB->age = tempfb->age;
		sec->next = newFB;
		
		struct newNodeGS* newGS = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));
		newGS->id = tempgs->id;
		newFB->next = newGS;
		newGS->next = NULL;
	
}

void printAll(struct newNodeFB* startNewFB){
	struct newNodeFB *fb = startNewFB;
	struct newNodeGS *gs;
	gs = fb->next;
	while(gs->next != NULL){
		printf("%d %d\n",fb->id,fb->age);
		printf("%d\n",gs->id);
		fb = gs->next;
		gs = fb->next;
	}
	printf("%d %d\n",fb->id,fb->age);
	printf("%d",gs->id);
}
