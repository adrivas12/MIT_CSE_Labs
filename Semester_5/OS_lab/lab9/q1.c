#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct mab{
	int size; 
	int allocated; 
	struct mab *next; 
}; 
typedef struct mab Mab; 
typedef Mab *MabPtr; 
MabPtr temporary; 

void memChk(MabPtr m, int size){
	MabPtr temp = m; 
	while (temp!=NULL){
		if(size <= temp->size && temp->allocated == -1){
			printf("Memory available\n");
			return; 
		}
		temp = temp->next; 
	}
	printf("No memory available\n");  
}	
void memAlloc_BestFit(MabPtr m, int size){
	MabPtr temp = m, b; 
	int minSize = 10000; 
	while(temp!=NULL){
		if(size <= temp->size && temp->allocated == -1){
			if(temp->size - size<=minSize ){
				minSize = temp->size - size; 
				b = temp; 
			}
		}
		temp = temp->next; 
	}
	if(b!=NULL){
		b->allocated = size; 
		temporary = b->next; 
		return; 
	}
	else
		printf("No space available not allocated\n"); 
}
void memAlloc_FirstFit(MabPtr m, int size){
	MabPtr temp= m; 
	while(temp !=NULL){
		if(size <= temp->size && temp->allocated == -1){
			temp->allocated = size; 
			temporary = temp->next; 
			break; 
		}
		temp = temp->next;
	}
}
void memAlloc_WorstFit(MabPtr m, int size){
	MabPtr temp = m, b; 
	int minSize = 0; 
	while(temp!=NULL){
		if(size <= temp->size && temp->allocated == -1){
			if(temp->size-size >= minSize){
				minSize = temp->size-size; 
				b = temp; 
			}
		}
		temp = temp->next; 
	}
	if(b!=NULL){
		b->allocated = size; 
		temporary = b->next; 
		return; 
	}
	else
		printf("No space available, %d not allocated\n", size); 
}
void memAlloc_NextFit(MabPtr m, int size){
	if(temporary == NULL){
		temporary = m;
	}
	memAlloc_FirstFit(temporary, size); 
}
void memFree(MabPtr m){
	MabPtr temp = m; 
	while( temp !=NULL){
		if(temp->allocated!=-1){
			temp->allocated = -1; 
		}
	}
}
void memDisplay(MabPtr m){
	MabPtr temp = m; 
	printf("\n----------------------------\n"); 
	while( temp != NULL){
		printf("%d(%d)\t|", temp->allocated, temp->size); 
		temp= temp->next; 
	}
	temp = m; 
	printf("\n----------------------------\n"); 
}
int main(){
	MabPtr m;
	int n, s, size; 
	printf("Enter the number of containers: "); 
	scanf("%d", &n); 
	m = (MabPtr)malloc(sizeof(Mab)); 
	MabPtr temp = m; 
	for(int i = 0; i<n; i++){
		printf("Enter size of box %d: ", i); 
		scanf("%d", &s); 
		temp->size = s; 
		temp->allocated = -1; 
		if(i == n-1) continue; 
		temp->next = (MabPtr)malloc(sizeof(Mab)); 
		temp = temp->next; 
	}
	printf("Enter the size of process you want to input in memory: "); 
	scanf("%d", &size); 
	memDisplay(m); 
	//memChk(m, size); 
	//printf("\nFirst Fit:\n");
	//memAlloc_FirstFit(m, 6); 
	//memDisplay(m); 

	//printf("Next Fit: \n");
	//memAlloc_NextFit(m, 2); 
	//memDisplay(m); 

	/*printf("Best Fit: \n"); 
	memAlloc_BestFit(m, size); 
	memDisplay(m); */
	printf("Worst Fit: \n"); 
	memAlloc_WorstFit(m, size); 
	memDisplay(m); 
}