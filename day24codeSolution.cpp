#include <iostream>
#include <queue>
#include <string>
using namespace std;

string a[100005];

struct node {
    int data;
    node *lt, *rt;
    node(int v) {
        data = v;
        lt = NULL;
        rt = NULL;
    }
};

node* makeTree(string a[], int n) {
    if(n==0 || a[0]=="null") return NULL;

    node* root = new node(stoi(a[0]));
    queue<node*> qu;
    qu.push(root);

    int i=1;
    while(!qu.empty() && i<n) 
    {
        node* temp = qu.front();
        qu.pop();

        if(i<n && a[i]!="null") 
        {
            temp->lt = new node(stoi(a[i]));
            qu.push(temp->lt);
        }
        i++;

        if(i<n && a[i]!="null") 
        {
            temp->rt = new node(stoi(a[i]));
            qu.push(temp->rt);
        }
        i++;
    }
    return root;
}

node* searchNode(node* root, int x) 
{
    if(root==NULL){
         return NULL;
    }

    if(root->data==x) {
        return root;
    }

    node* l = searchNode(root->lt, x);

    if(l!=NULL) {
        return l;
    }
    return searchNode(root->rt, x);
}

node* LCA(node* root, node* p, node* q) {
    if(root==NULL || root==p || root==q) {
        return root;
    }

    node* l = LCA(root->lt, p, q);
    node* r = LCA(root->rt, p, q);

    if(l && r) {
        return root;
    }
    if(l!=NULL) {
        return l;
    }
    return r;
}

int main() 
{
    int n;
    cout<<"how many elements in tree array: ";
    cin>>n;

    cout<<"enter elements (put null for empty) : ";
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
    }

    node* root = makeTree(a, n);

    int x, y;
    cout<<"enter node p value : ";
    cin>>x;
    cout<<"enter node q value : ";
    cin>>y;

    node* p = searchNode(root, x);
    node* q = searchNode(root, y);

    if(p==NULL || q==NULL) 
    {
        cout<<"one/both nodes not in tree\n";
        return 0;
    }

    node* ans = LCA(root, p, q);
    cout<<"LCA is: "<<ans->data<<endl;

    return 0;
}
