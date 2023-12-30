#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* create(int n)
{
	struct Node* head=NULL, *pf=NULL, *pb;
	int i;
	printf("ÇëÊäÈëÊı¾İ£º\n");
	for (i = 0; i < n; i++)
	{
		pb = (struct Node*)malloc(sizeof(struct Node));
		scanf("%d", &pb->data);
		if (i == 0) pf = head = pb;
		else pf->next = pb;
		pb->next = NULL;
		pf = pb;
	}
	return head;
}
struct Node* add(struct Node* head1, struct Node* head2)
{
	struct Node* head, * pf, * pb, **pd=&head;
	while (head1&&head2)
	{
		*pd = head1;
		head1 = head1->next;
		pd = &(*pd)->next;
		*pd = head2;
		head2 = head2->next;
		pd = &(*pd)->next;
	}
	if (head1 != NULL)
	{
		*pd=head1;
	}
	if (head2 != NULL)
	{
		*pd=head2;
	}
	return head;
}
void display(struct Node* head)
{
	struct Node* tmp = head;
	for (; tmp; tmp = tmp->next)
	{
		printf("%d ", tmp->data);
	}
}
int main()
{
	struct Node* head1, * head2, * head;
	head1 = create(6);
	head2 = create(3);
	head = add(head1, head2);
	display(head);
	return 0;
}