#include<bits/stdc++.h>
using namespace std;

class Node 
{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* array_to_bst(int a[] , int l , int r)
{
    if (l > r) return NULL;
    int mid = (l+r)/2;
    Node* root = new Node(a[mid]);
    Node* left = array_to_bst(a , l , mid-1); Node* right = array_to_bst(a , mid+1 , r);
    root->left = left;
    root->right = right;
    return root;
}

void print_level(Node* root)
{
    if (root == NULL) return;
    queue<Node*> q; q.push(root);
    while(!q.empty())
    {
        Node* current = q.front(); q.pop();
        cout << current->val << " ";
        if (current->left) q.push(current->left); if (current->right) q.push(current->right);
    }
}

int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    sort (arr , arr+n);
    Node* root = array_to_bst(arr , 0 , n-1);
    print_level(root);
}