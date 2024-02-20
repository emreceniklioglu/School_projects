#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

void sortfunc(struct nodeStudent* head){
	
  struct nodeStudent *current = head, *index = NULL;
  int tempnote,tempid;
  

  if (head == NULL) {
  	return;												
  } 
  else {
  while (current != NULL) {
  	
    index = current->next;

    while (index != NULL) {
    if (current->midterm < index->midterm) {
      tempnote = current->midterm;
      tempid = current->studentID;
      
      current->studentID = index->studentID;
      current->midterm = index->midterm;
      
      index->studentID = tempid;
      index->midterm = tempnote;
    }
    else if(current->midterm == index->midterm){
    	if(current->studentID < index->studentID){
    	continue;}
    	else
    	{
	tempnote = current->midterm;
        tempid = current->studentID;
      
        current->studentID = index->studentID;
        current->midterm = index->midterm;
      
        index->studentID = tempid;
        index->midterm = tempnote;
    	}
    }
    
    
    index = index->next;
    }
    current = current->next;
  }
  }
}
void insert(struct nodeClass** head,int id,int  midterm){
	if (*head == NULL){
		
		int i = 1;
		struct nodeClass* temp;
		while(i < 5)
		{
			struct nodeClass* newnode = (struct nodeClass*)malloc(sizeof(struct nodeClass));
			newnode->classID = i;
			newnode->classMidtermAverage = 0;
			newnode->next = NULL;
			newnode->studentPtr = NULL;
			if(i == 1){
				*head = newnode;
				temp = *head;
			}
			else{
				temp->next = newnode;
				temp = newnode;
			}
			i++;
		}
	}
	struct nodeClass* startClass = *head;
	struct nodeStudent* temp1;
	struct nodeStudent* temp2;
	struct nodeStudent* temp3;
	struct nodeStudent* temp4;
	if(id/1000==66){
		
		if(startClass->studentPtr == NULL){
			struct nodeStudent* start1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			start1->studentID = id;
			start1->midterm = midterm;
			start1->next = NULL;		
			startClass->studentPtr = start1;
			temp1 = start1;
		}
		else{
			struct nodeStudent* newst1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			
			newst1->studentID = id;
			newst1->midterm = midterm;
			newst1->next = NULL;
			temp1->next = newst1;
			temp1 = temp1->next;
		}
	}
	
	if(id/1000==77){
		startClass = startClass->next;
		if(startClass->studentPtr == NULL){
			struct nodeStudent* start1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			start1->studentID = id;
			start1->midterm = midterm;
			start1->next = NULL;		
			startClass->studentPtr = start1;
			temp2 = start1;
		}
		else{
			struct nodeStudent* newst1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			
			newst1->studentID = id;
			newst1->midterm = midterm;
			newst1->next = NULL;
			temp2->next = newst1;
			temp2 = temp2->next;
		}
		startClass = *head;
	}
	if(id/1000==88){
		startClass = startClass->next;
		startClass = startClass->next;
		if(startClass->studentPtr == NULL){
			struct nodeStudent* start1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			start1->studentID = id;
			start1->midterm = midterm;
			start1->next = NULL;		
			startClass->studentPtr = start1;
			temp3 = start1;
		}
		else{
			struct nodeStudent* newst1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			
			newst1->studentID = id;
			newst1->midterm = midterm;
			newst1->next = NULL;
			temp3->next = newst1;
			temp3 = temp3->next;
		}
		startClass = *head;
	}
	
	if(id/1000==99){
		startClass = startClass->next;
		startClass = startClass->next;
		startClass = startClass->next;
		if(startClass->studentPtr == NULL){
			struct nodeStudent* start1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			start1->studentID = id;
			start1->midterm = midterm;
			start1->next = NULL;		
			startClass->studentPtr = start1;
			temp4 = start1;
		}
		else{
			struct nodeStudent* newst1 = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
			
			newst1->studentID = id;
			newst1->midterm = midterm;
			newst1->next = NULL;
			temp4->next = newst1;
			temp4 = temp4->next;
		}
		startClass = *head;
	}
}
void computeClassAverage(struct nodeClass *head){
	struct nodeClass *temp2 = head;
	struct nodeStudent *temp1;
	  
	while(temp2!=NULL){
		double total = 0;
		int stcount = 0;
		temp1 = temp2->studentPtr;
		
		while(temp1!=NULL){
			total += temp1->midterm;
			stcount++;
			temp1 = temp1->next;
		}
		temp2->classMidtermAverage = total/stcount;
		temp2 = temp2->next;
	}
}

void printAll(struct nodeClass *head){
	struct nodeClass *temp2 = head;
	struct nodeStudent *temp1;
	while(temp2!=NULL){
		printf("%d     %.2f\n",temp2->classID,temp2->classMidtermAverage);
		
		temp1 = temp2->studentPtr;
		sortfunc(temp1);
		while(temp1!=NULL){
			printf("%d %d\n",temp1->studentID,temp1->midterm);
			temp1 = temp1->next;
		}
		temp2 = temp2->next;
	}
}

int main()
{
	struct nodeClass *head = NULL;

	int id, midterm;
	scanf("%d", &id);
	while(id!=-1)
	{
		scanf("%d", &midterm);
		insert(&head, id, midterm);
		scanf("%d", &id);
	}
	
	computeClassAverage(head);

	printAll(head);

	return 0;
}




