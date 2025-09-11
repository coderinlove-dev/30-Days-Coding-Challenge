#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    Node(int x) {
        val = x;
        l = NULL;
        r = NULL;
    }
};

bool same(Node* a, Node* b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {
        return false;
    }
    if (a->val != b->val) {
        return false;
    }
    return same(a->l, b->r) && same(a->r, b->l);
}

bool symetric(Node* root) {
    if (root == NULL) {
        return true;
    }
    return same(root->l, root->r);
}

Node* makeTree(string arr[], int n) {
    if (n == 0 || arr[0] == "null") {
        return NULL;
    }

    Node* root = new Node(stoi(arr[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        Node* temp = q.front();
        q.pop();

        if (i < n && arr[i] != "null") {
            temp->l = new Node(stoi(arr[i]));
            q.push(temp->l);
        }
        i++;

        if (i < n && arr[i] != "null") {
            temp->r = new Node(stoi(arr[i]));
            q.push(temp->r);
        }
        i++;
    }
    return root;
}

int main() {
    cout << "Enter tree nodes (space separated in 1 line , null for empty) : ";
    string line;
    getline(cin, line);

    stringstream ss(line);
    string w;
    string arr[10005];
    int n = 0;
    while (ss >> w) {
        arr[n++] = w;
    }

    Node* root = makeTree(arr, n);

    if (symetric(root)){
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
