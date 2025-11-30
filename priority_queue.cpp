#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class myPriorityQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->val >= val)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return;
        }
        if (temp == NULL)
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            return;
        }
        Node *p = temp->prev;
        p->next = newnode;
        newnode->prev = p;
        newnode->next = temp;
        temp->prev = newnode;
    }

    void pop()
    {
        if (head == NULL)
            return;
        sz--;
        Node *deletenode = head;
        head = head->next;
        delete deletenode;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }

    int top()
    {
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    myPriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);
    pq.push(20);

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}