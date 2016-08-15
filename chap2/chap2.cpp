// chap2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<map>
using namespace std;



struct node 
{
	int data;
	node* next;
};

void append(node** head,int data)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	node* n = *head;
	while (n->next != NULL)
		n = n->next;
	n->next = new_node;

}
void print_node(node* head)
{
	node* n = head;
	while (n != NULL)
	{
		printf("%d\n", n->data);
		n = n->next;
	}
}

void delete_node(node** head, int data)
{
	if (*head == NULL)
		return;

	node* previous_node,*temp_node=*head;

	if (temp_node->data == data)
	{
		*head = temp_node->next;
		free(temp_node);
		return;
	}

	while ((temp_node != NULL)&&(temp_node->data != data))
	{
		previous_node = temp_node;
		temp_node = temp_node->next;
	}
	if (temp_node == NULL)
		return;

	previous_node->next = temp_node->next;
	free(temp_node);
}

void delete_node_position(node**head, node*delete_node)
{
	if (*head == NULL)
		return;

	node *prev_node,*temp_node = *head;

	if (temp_node == delete_node)
	{
		*head = temp_node->next;
		free(temp_node);
		return;
	}

	while((temp_node != NULL) && (temp_node != delete_node))
	{
		prev_node = temp_node;
		temp_node = temp_node->next;
	}
	if (temp_node == NULL)
		return;
	prev_node->next = temp_node->next;
	free(temp_node);
}

int main()
{
	map<int, bool> m;



	node* n = NULL;
	append(&n, 1);
	append(&n, 2);
	append(&n, 3);
	append(&n, 4);
	append(&n, 5);
	append(&n, 6);
	append(&n, 7);
	append(&n, 8);
	append(&n, 1);
	append(&n, 2);
	append(&n, 3);
	append(&n, 6);
	append(&n, 7);
	append(&n, 8);

	node* node_hash = n;
	node* temp_next;
	while (node_hash != NULL)
	{
		if (m[node_hash->data] == false)
		{
			m[node_hash->data] = true;
			node_hash = node_hash->next;

		}
		else
		{
			temp_next = node_hash->next;
			delete_node_position(&n, node_hash);
			node_hash = temp_next;
		}
		
	}


	//print_node(n);

	//cout << endl;

	//delete_node(&n, 4);
	//delete_node(&n, 5);
	//delete_node(&n, 1);

	print_node(n);




	return 0;
}