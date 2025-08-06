#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long int

struct Node
{
    int val;
    ll wt;
    struct Node *left;
    struct Node *right;

    Node(int _val,ll weight)
    {
        val = _val;
        wt = weight;
        left = right = nullptr;
    }
};

void Traversal(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->val << endl;
    Traversal(root->left);
    Traversal(root->right);
}

vector<vector<int>> Bfs(Node *root)
{

    queue<Node *> q;
    q.push(root);
    vector<vector<int>> tree;

    while (!q.empty())
    {
        vector<int> level;
        for (int i = 0; i < q.size(); i++)
        {
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        tree.push_back(level);
    }

    return tree;
}

// vector<int> IterativePreorder(Node* root){
//     if(root == nullptr) return {};
//     stack<Node*> st;
//     st.push(root);
//     vector<int> traversal;
//     while(!st.empty()){
//         Node* node = st.top();
//         st.pop();
//         traversal.push_back(node->val);
//         if(node->right != nullptr) st.push(node->right);
//         if(node->left != nullptr) st.push(node->left);
//     }
//     return traversal;
// }

// vector<int> IterativePostOrder(Node* root) {
//     if (root == nullptr) return {};
//     stack<Node*> st1, st2;
//     st1.push(root);
//     vector<int> traversal;
//     while (!st1.empty()) {
//         Node* node = st1.top();
//         st1.pop();
//         st2.push(node);
//         if (node->left != nullptr) st1.push(node->left);
//         if (node->right != nullptr) st1.push(node->right);
//     }
//     while (!st2.empty()) {
//         traversal.push_back(st2.top()->val);
//         st2.pop();
//     }
//     return traversal;
// }

// int Depth(Node* root){
//     priority_queue<pair<int, Node*>> pq;
//     pq.push({1,root});
//     int height = 1;

//     while(!pq.empty()){
//         auto [dd,nn] = pq.top();
//         pq.pop();
//         height = max(height,dd);
//         if(nn->left != nullptr)pq.push({dd+1,nn->left});
//         if(nn->right != nullptr)pq.push({dd+1,nn->right});
//     }

//     return height;
// }

int Height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(Height(root->left), Height(root->right));
}

bool IsBalanced(Node* root) {
    if (root == nullptr) return true;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    if (abs(leftHeight - rightHeight) > 1) return false;
    return IsBalanced(root->left) && IsBalanced(root->right);
}

int MaxPathSum(Node* root){
    priority_queue<pair<ll, Node*>> pq;
    pq.push({0,root});

    while(!pq.empty()){
        auto [wt,nn] = pq.top();
        pq.pop();

        if(nn->left != nullptr)pq.push({wt+nn->wt,nn->left});
        if(nn->right != nullptr)pq.push({wt+nn->wt,nn->right});
    }
}

int main()
{
    struct Node *root = new Node(1,10);

    root->left = new Node(2,11);
    root->right = new Node(3,9);
    root->left->left = new Node(4,11);
    root->left->right = new Node(6,34);
    // Traversal(root);

    // vector<vector<int>> tree = Bfs(root);

    // for(auto i : tree){
    //     cout << "Level\n";
    //     for(auto j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }


    // vector<int> tr = IterativePreorder(root);

    // for(auto it : tr)cout << it << " ";
    // cout << endl;

    // cout << Depth(root) << endl;
}