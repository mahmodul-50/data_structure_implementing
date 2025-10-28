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

int depth(Node* root)
{
    if(root == NULL) return 0;
    if(root == NULL) return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    return max(l, r) + 1;
}

int nnode(Node* root)
{
    if (root == NULL) return 0;
    int l = nnode(root->left);
    int r = nnode(root->right);
    return l + r + 1;
}

int main()
{
    Node* root = NULL;
    root = input_tree(root);
    int d = depth(root);
    int n = nnode(root);
    if (n == pow(2,d) - 1) cout << "YES";
    else cout << "NO";
    return 0;
}