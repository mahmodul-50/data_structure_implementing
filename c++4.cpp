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
        this->val = val; // storing the value
        this->next = NULL; // default next is NULL
        this->prev = NULL; // default previous is NULL
    }
};

// Print the list from head to tail
void print_normal(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Print the list from tail to head
void print_reverse(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// Insert a node at the beginning
void insert_beginning(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Delete the last node
void delete_end(Node *&head)
{
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    if (tmp->prev != NULL) {
        tmp->prev->next = NULL;
    } else {
        head = NULL; // The list has only one node
    }
    delete tmp;
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;

    // Print the list
    print_normal(head);
    print_reverse(tail);

    // Insert at the beginning
    insert_beginning(head, 5);
    cout << "After inserting 5 at the beginning: ";
    print_normal(head);

    // Delete the last node
    delete_end(head);
    cout << "After deleting the last node: ";
    print_normal(head);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
        string name;
        int roll;
        int marks;
        Student(string name , int roll , int marks)
        {
            this->name = name;
            this->roll = roll;
            this->marks = marks;
        }
};
class cmp
{
    public:
        bool operator()(Student l , Student r)
        {
            if (l.name == r.name) return l.roll > r.roll;
            else return l.name > r.name;
        }
};

int main()
{
    priority_queue<Student , vector<Student> , cmp> pq;
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        string name; cin >> name;
        int roll, marks; cin >> roll >> marks;
        Student obs(name , roll , marks);
        pq.push(obs);
    }
    cout << "###" << endl;
    while(!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }
}

#include<bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> v;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int x; cin >> x;
        v.push_back(x);
        
        int cur_idx = v.size() - 1;

        while (cur_idx != 0)
        {
            int parent_idx = (cur_idx - 1) / 2;

            if (v[parent_idx] < v[cur_idx]) swap(v[parent_idx] , v[cur_idx]);
            else break;
            cur_idx = parent_idx;
        }
    }
    for (int val : v) cout << val << " ";
}
