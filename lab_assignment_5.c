#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int i=0;
	while(head!=NULL){
		head=head->next;
		i++;
	}
	return i;

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{	
	int num = length(head);
	char* res = malloc((num+1)*sizeof(char));
	int i=0;
	while(head!=NULL){
		res[i]=head->letter;
		head=head->next;
		i++;
	}
	res[num]='\0';
	return res;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* new = (node*)malloc(sizeof(node));
	new->letter = c;
	new->next = NULL;
	node*t = *pHead;

	if((*pHead) == NULL){
		*pHead = new;
		return;
	}
	while(t->next != NULL){
		t=t->next;
	}
	t->next=new;

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node*t=*pHead;
	while(t!=NULL){
		node * temp=t;
		t=t->next;
		free(temp);
	}
	*pHead = NULL;
}

int main(void)
{
	
	
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
	
	
}