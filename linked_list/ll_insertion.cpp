#include <iostream>
class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int _data)
{
    Node *new_node = new Node();
    new_node->data = _data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(Node *temp)
{
    while (temp != NULL)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
}

void append(Node **head_ref, int new_data)
{
    Node *last = *head_ref;
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void insertAfter(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        std::cout << "Previous node cannot be NULL" << std::endl;
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main()
{
    Node *head_ref = NULL;
    push(&head_ref, 5);
    push(&head_ref, 7);
    push(&head_ref, 8);
    append(&head_ref, 2);
    append(&head_ref, 6);
    insertAfter(head_ref->next, 12);
    print(head_ref);
    return 0;
}