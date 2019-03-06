#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* next ;
	int data ;
} node ;

node* create_node()
{
	return (node*) malloc(sizeof(node)) ;
}

void push( node** head, int dat )
{
	node* new_node = create_node() ;
	new_node->data = dat ;
	if(!*head)
	{
		new_node->next = NULL ;
		*head = new_node ;
        // Error without the following return statement, why can't we only do new_node->next = *head
        return ;
	}
	new_node->next = *head ;
	*head = new_node ;
}

int pop(node** head)
{
    int data_to_be_popped = (*head)->data ;
	node* tmp = *head ;
	*head = (*head)->next ;
	free(tmp) ;
	return data_to_be_popped ;
}

void print(node* head)
{
	node *elt = head ;
	while(elt)
	{
		printf("%d " , elt->data) ;
		elt = elt->next ;
	}
}

void shift_disks(int n, node** head_a, node** head_b, node** head_c)
{
    if(n==1)
    {
    	if(head_a)
    	{
            push(head_c, pop(head_a)) ;
	        return ;
    	}
    }
    
    shift_disks(n-1, head_a, head_c, head_b) ;
    if(head_a)
    {
        push(head_c, pop(head_a)) ;
    }
    shift_disks(n-1, head_b, head_a, head_c) ;
}

int main()
{
    //node* head_a, head_b, head_c ;
    //head_a = head_b = head_c = NULL ;
    node* head_a = NULL ;
    node* head_b = NULL ;
    node* head_c = NULL ;
    int n ;
    printf("\nEnter the no of disks on tower A:- ") ;
    scanf("%d" , &n) ;
    for(int i=n; i>=1 ; i--)
        push(&head_a, i) ;
    printf("\n---BEFORE---") ;
    printf("\nPole A: ") ;
    print(head_a) ;
    printf("\nPole B: ") ;
    print(head_b) ;
    printf("\nPole C: ") ;
    print(head_c) ;
    printf("\n") ;
    shift_disks(n, &head_a, &head_b, &head_c) ;
    printf("\n---AFTER---") ;
    printf("\nPole A: ") ;
    print(head_a) ;
    printf("\nPole B: ") ;
    print(head_b) ;
    printf("\nPole C: ") ;
    print(head_c) ;
}
