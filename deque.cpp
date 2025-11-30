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

class myDeque
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void pushfront(int val)
    {
        sz++;
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    void pushback(int val)
    {
        sz++;
        Node *newnode = new Node(val);
        if (tail == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void popfront()
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

    void popback()
    {
        if (tail == NULL)
            return;
        sz--;
        Node *deletenode = tail;
        tail = tail->prev;
        delete deletenode;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }

    int front()
    {
        return head->val;
    }

    int back()
    {
        return tail->val;
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
    myDeque dq;

    dq.pushback(10);
    dq.pushfront(20);
    dq.pushback(30);
    dq.pushfront(40);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.popfront();
    dq.popback();

    while (!dq.empty())
    {
        cout << dq.front() << endl;
        dq.popfront();
    }

    return 0;
}
