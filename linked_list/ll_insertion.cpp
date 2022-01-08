#include <iostream>
#include <array>
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *head = NULL;
    Node **head_ref = &head;
    void push(int _data);
    void print();
    void append(int new_data);
    void insertAfter(Node *prev_node, int new_data);
    void addAll(int int_arr[], int size);
};

void LinkedList::push(int _data)
{
    Node *new_node = new Node();
    new_node->data = _data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void LinkedList::print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
}

void LinkedList::append(int new_data)
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

std::ostream &operator<<(std::ostream &output, LinkedList ll)
{
    ll.print();
    return output;
}

void LinkedList::insertAfter(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
        std::cout << "Previous node cannot be NULL" << std::endl;
    {
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void LinkedList::addAll(int int_arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        append(int_arr[i]);
    }
}

int main()
{
    LinkedList ll;
    ll.append(1);
    ll.append(3);
    ll.append(5);
    ll.append(7);
    int int_arr[5] = {45, 23, 67, 89, 22};
    ll.addAll(int_arr, 5);
    std::cout
        << ll;
    return 0;
}