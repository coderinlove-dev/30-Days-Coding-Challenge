#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* makeTree(int n) {
    if (n == 0) 
    {
        return NULL;
    }
    string x;
    cin >> x;
    if (x == "null") {
        return NULL;
    }

    Node* root = new Node(stoi(x));
    queue<Node*> q;
    q.push(root);

    for (int i = 1; i < n; i++) 
    {
        Node* cur = q.front();
        q.pop();

        cin >> x;
        if (x != "null") {
            cur->left = new Node(stoi(x));
            q.push(cur->left);
        }

        i++;
        if (i >= n) break;

        cin >> x;
        if (x != "null") {
            cur->right = new Node(stoi(x));
            q.push(cur->right);
        }
    }
    return root;
}

bool check(Node* root, long long low, long long high) 
{
    if (!root) return true;
    if (root->data <= low || root->data >= high) return false;
    return check(root->left, low, root->data) && check(root->right, root->data, high);
}

bool isBST(Node* root) 
{
    return check(root, LLONG_MIN, LLONG_MAX);
}

int main() 
{
    int n;
    cout << "Enter The Number Of Nodes  : ";
    cin >> n;
    cout << "Enter The Values (root) Of The Nodes use null for empty node : ";
    Node* root = makeTree(n);
    if (isBST(root)) {
        cout << "true";
    } else {
        cout << "false";
    }

}
