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

Node* input_tree(Node* root)
{
    int val; cin >> val;
    if(val == -1) root = NULL;
    else root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();
        int l, r; cin >> l >> r;
        Node* myleft;
        Node* myright;
        if(l == -1) myleft = NULL;
        else myleft = new Node(l);
        if(r == -1) myright = NULL;
        else myright = new Node(r);
        f->left = myleft;
        f->right = myright;
        if(f->left) q.push(myleft);
        if(f->right) q.push(myright);
    }
    return root;
}

vector<int> v;

void print_outer(Node* root)
{
    if(root == NULL) return;
    if(root->left) print_outer(root->left);
    else print_outer(root->right);
    v.push_back(root->val);
}

void print_outer2(Node* root)
{
    if(root == NULL) return;
    v.push_back(root->val);
    if(root->right) print_outer2(root->right);
    else print_outer2(root->left);
}

int main()
{
    Node* root = NULL;
    root = input_tree(root);
    if(root->left) print_outer(root);
    if(root->left == NULL) cout << root->val << " ";
    if(root->right) print_outer2(root->right);
    for(auto i : v) cout << i << " ";
}