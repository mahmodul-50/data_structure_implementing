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
        return;
    }
    Node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}

void sorting(Node* &head)
{
    if(head == NULL || head->next == NULL) return;
    Node* sorted = NULL;
    Node* tmp = head;
    while(tmp != NULL)
    {
        Node* next = tmp->next;
        if(sorted == NULL || sorted->val >= tmp->val)
        {
            tmp->next = sorted;
            sorted = tmp;
        }
        else
        {
            Node* temp = sorted;
            while(temp->next != NULL && temp->next->val < tmp->val)
            {
                temp = temp->next;
            }
            tmp->next = temp->next;
            temp->next = tmp;
        }
        tmp = next;
    }
    head = sorted;
}

bool searching_unsorted(Node* head, int val)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->val == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool search_sorted(Node* head, int val)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->val == val)
        {
            return true;
        }
        if(temp->val > val)
        {
            return false;
        }
        temp = temp->next;
    }
    return false;
}

void insert_at_position(Node* &head, int pos, int val)
{
    Node* newnode = new Node(val);
    if(pos == 0)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    Node* tmp = head;
    pos--;
    while(pos--)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void sorted_insertion(Node* &head, int val)
{
    insert(head, val);
    sorting(head);
}

void deletion_at_position(Node* &head, int pos)
{
    if(head == NULL) return;
    Node* tmp = head;
    if(pos == 0)
    {
        Node* tmp2 = head;
        head = head->next;
        delete tmp2;
        return;
    }
    while(pos--)
    {
        tmp = tmp->next;
    }
    Node* tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    delete tmp2;
}

void deletion_by_item(Node* &head, int val)
{
    
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
}