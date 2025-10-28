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

void depthprint(Node* root , int x)
{
    if(root == NULL) return;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        Node* f = q.front().first;
        int d = q.front().second;
        q.pop();
        if(d == x) cout << f->val << " ";
        if(f->left) q.push({f->left, d+1});
        if(f->right) q.push({f->right, d+1});
    }
}

int main()
{
    Node* root;
    root = input_tree(root);
    int x; cin >> x;
    if(depth(root)>x) depthprint(root, x);
    else cout << "Invalid";
}