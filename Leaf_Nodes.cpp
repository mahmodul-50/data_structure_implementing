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
    if(val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node*> q;
    if(root)
    {
        q.push(root);
    }
    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();
        int l, r; cin >> l >> r;
        Node* myleft;
        Node* myright;

        if(l == -1)
        {
            myleft = NULL;
        }
        else
        {
            myleft = new Node(l);
        }

        if(r==-1)
        {
            myright = NULL;
        }
        else
        {
            myright = new Node(r);
        }

        f->left = myleft;
        f->right = myright;

        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }
    }
    return root;
}

vector<int> leaf(Node* root)
{
    vector<int> v;
    if(root == NULL)
    {
        return v;
    }
    if(root->left == NULL && root->right == NULL)
    {
        v.push_back(root->val);
    }
    vector<int> left = leaf(root->left);
    vector<int> right = leaf(root->right);

    v.insert(v.end(), left.begin(), left.end());
    v.insert(v.end(), right.begin(), right.end());

    return v;
}

int main()
{
    Node* root = NULL;
    root = input_tree(root);

    vector<int> v = leaf(root);
    sort(v.begin(), v.end(),greater<int>());
    for(auto it : v)
    {
        cout << it << " ";
    }
}