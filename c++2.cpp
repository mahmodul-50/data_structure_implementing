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

Node* input()
{
    int val; cin >> val;
    Node* root;
    if (val == -1) root = NULL; else root = new Node(val);
    queue<Node*> q; if (root) q.push(root);
    while(!q.empty())
    {
        Node* current = q.front(); q.pop();
        int l, r; cin >> l >> r;
        Node* myleft; Node* myright;
        if (l == -1) myleft = NULL; else myleft = new Node(l); if (r == -1) myright = NULL; else myright = new Node(r);
        current->left = myleft; current->right = myright;
        if (current->left) q.push(current->left); if (current->right) q.push(current->right);
    }
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

int count_node(Node* root)
{
    if (root == NULL) return 0; 
    int l = count_node(root->left); int r = count_node(root->right);
    return l + r + 1;
}

int count_leaf(Node* root)
{
    if (root == NULL) return 0;
    int l, r;
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else 
    {
        l = count_leaf(root->left); r = count_leaf(root->right);
    }
    return l + r;
}

int height(Node* root)
{
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r) +1;
}

int main()
{
    //int n; cin >> n;
    Node* root = input();
    print_level(root);
    cout << endl << count_node(root) << " " << count_leaf(root) << " " << height(root);
}