#include <bits/stdc++.h>
using namespace std;
class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
    };
    Node *head;
    int sz;

public:
    MyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    int get(int index)
    {
        Node *temp = head;
        if (sz - 1 < index)
            return -1;
        else
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void addAtHead(int val)
    {
        sz++;
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        Node *temp = head;

        if (head == NULL)
        {
            head = newNode;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if (index > sz-1)
            return;
        sz++;
        if (index == 0)
        {
            Node* newNode = new Node(val);
            head->next = newNode;
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            for(int i=0; i<index-1; i++)
            {
                temp = temp->next;
            }
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index > sz-1)
            return;
        sz--;
        if (head == NULL)
        {
            return;
        }
        if (index == 0)
        {
            head = head->next;
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            if (temp->next == NULL)
                return;
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */