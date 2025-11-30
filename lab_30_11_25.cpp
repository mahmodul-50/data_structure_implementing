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

class myStack
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
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop()
    {
        if (tail == NULL)
            return;
        sz--;
        Node *tmp = tail;
        tail = tail->prev;
        delete tmp;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }

    int top() { return tail->val; }
    bool empty()
    {
        return head == NULL;
    }
    int size()
    {
        return sz;
    }

    void print_stack()
    {
        Node *temp = head;
        cout << "stack: ";
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class myQueue
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
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop()
    {
        if (head == NULL)
            return;
        sz--;
        Node *tmp = head;
        head = head->next;
        delete tmp;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }

    int front()
    {
        return head->val;
    }
    bool empty()
    {
        return head == NULL;
    }
    int size()
    {
        return sz;
    }

    void print_queue()
    {
        Node *temp = head;
        cout << "queue: ";
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class myDeque
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push_front(int val)
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

    void push_back(int val)
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

    void pop_front()
    {
        if (head == NULL)
            return;
        sz--;
        Node *tmp = head;
        head = head->next;
        delete tmp;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }

    void pop_back()
    {
        if (tail == NULL)
            return;
        sz--;
        Node *tmp = tail;
        tail = tail->prev;
        delete tmp;
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

    void print_dq()
    {
        Node *temp = head;
        cout << "duque:";
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
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
        Node *tmp = head;
        head = head->next;
        delete tmp;
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

    void print_pq()
    {
        Node *temp = head;
        cout << "priority queue:";
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    myStack st;
    myQueue q;
    myDeque dq;
    myPriorityQueue pq;
    for(int i = 11; i < 50; i+=5)
    {
        st.push(i);
    }
    for(int i = 11; i < 50; i+=5)
    {
        q.push(i);
    }
    for(int i = 11; i < 50; i+=5)
    {
        dq.push_back(i);
    }
    for(int i = 11; i < 50; i+=5)
    {
        pq.push(i);
    }
    st.print_stack();
    q.print_queue();
    dq.print_dq();
    pq.print_pq();
}
