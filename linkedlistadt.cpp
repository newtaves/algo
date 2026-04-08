#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void insertEnd(int x)
    {
        Node* temp = new Node(x);

        if(head == NULL)
        {
            head = temp;
            return;
        }

        Node* p = head;

        while(p->next != NULL)
            p = p->next;

        p->next = temp;
    }

    Node* getHead()
    {
        return head;
    }

    void display()
    {
        Node* p = head;

        while(p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};