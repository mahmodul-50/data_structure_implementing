#include<bits/stdc++.h>
using namespace std;

#define int long long

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack
{
public:
    Node *head;
    int sz;

    Stack()
    {
        head = NULL;
        sz = 0;
    }

    int getSize()
    {
        return sz;
    }

    bool isEmpty()
    {
        if (sz == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int data)
    {
        Node *New_Node = new Node(data);
        sz++;

        if (head == NULL)
        {
            head = New_Node;
            return;
        }
        New_Node->next = head;
        head = New_Node;
    }

    void pop()
    {
        if (isEmpty() == true)
        {
            return;
        }

        Node *delete_node = head;

        head = head->next;

        delete delete_node;
        sz--;
    }

    int getTop()
    {

        if (isEmpty() == true)
        {
            return -1;
        }

        else
            return head->data;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
}