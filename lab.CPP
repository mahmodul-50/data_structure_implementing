#include<bits/stdc++.h>
using namespace std;

#define int long long

class Node
{
public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert(Node* &head, int val)
{
    Node* newnode = new Node(val);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    Node* tmp = head;
    while(tmp->next != head)
    {
        tmp = tmp->next;
    }

    tmp->next = newnode;
    newnode->next = head;
}

void print_linked_list(Node* head)
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

void deletion_at_position(Node* &head, int pos)
{
    if(head == NULL) return;

    Node* tmp = head;

    if(pos == 0)
    {
        if(head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;
        while(last->next != head)
        {
            last = last->next;
        }

        last->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }
}

void push_back(Node* &head, int val)
{
    Node* newnode = new Node(val);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    Node* tmp = head;
    while(tmp->next != head)
    {
        tmp = tmp->next;
    }

    tmp->next = newnode;
    newnode->next = head;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = NULL;

    for(int i = 10; i <= 100; i += 10)
    {
        insert(head, i);
    }

    print_linked_list(head);

    deletion_at_position(head, 0);
    print_linked_list(head);

    deletion_at_position(head, 3);
    print_linked_list(head);
}
