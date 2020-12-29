
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<math.h>           
#include<cstdio>
#include<stdio.h>
#include<algorithm>       
#include<cmath>           
#include<climits>       
#include<cstring>       
#include<string>        
#include<stdlib.h>
#include<queue>         
#include<stack>         
#include<deque>     

//BST-binary search tree

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* insertInBST(node*root, int data){
    if(root==NULL){
        return new node(data);
    }
    if(data <= root->data){
        root->left = insertInBST(root->left, data);  
    }
    else{
        root->right = insertInBST(root->right, data);  
    }
    return root;
}

//searching in BST
bool searchInBST(node*root, int data){
    if(root==NULL){
        return false;
    }
    if(data == root->data){
        return true;
    }
    else if(data <= root->data){
        return searchInBST(root->left,data);
    }
    else{
        return searchInBST(root->right,data);
    }
}

node* build_or_insert(){                       //return tree
    int d;
    cin>>d;
    node *root = NULL;
    while(d != -1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}


// algo for BFS=>
// take a queue , push, root in it, 
// while loop jabtak tabtak ki queue NOT EMPTY
// pop root, print the element which is popped
// root ke dono neighbours push it then 
// pop once of these and push uske elements in to queue
// and go on like this

void BFS_TRAVERSAL(node*root){
    queue<node*> q;                         
    q.push(root);
    while(!q.empty()){
        node *f = q.front();
        cout<<f->data<<" ";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    cout<<endl;
    return;
}

void inorder(node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//deletion in BST
node* deleteInBST(node*root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(data < root->data){
        root->left = deleteInBST(root->left,data);
        return root;
    }
    else if(data == root->data){
        if(root->left==NULL && root->right==NULL){     //leaf node
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){     
            node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        //case of 2 childrens
        node *replace = root->right;
        while(replace->left != NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else{
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

//to check if BST is or not
bool isBST(node*root, int min=INT_MIN, int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >= min && root->data <= max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max)){
        return true;
    }
    return false;
}

int main(){
    int s;
    cout<<"ENTER VALUES : ";
    node *root = build_or_insert();

    cout<<"INORDER : ";
    inorder(root);

    cout<<endl;
    cout<<"BFS_TRAVERSAL : ";
    BFS_TRAVERSAL(root);

    //searching in BST
    // cout<<"ENTER S : ";
    // cin>>s;
    // if(searchInBST(root, s)){
    //     cout<<"FOUND"<<endl;
    // }
    // else{
    //     cout<<"NOT FOUND"<<endl;
    // }

    //deletion
    // cout<<"ENTER S WHICH U WANT TO DELETE : ";
    // cin>>s;
    // root =  deleteInBST(root, s);
    // cout<<"TREE AFTER DELETION(INORDER) : ";
    // inorder(root);
    // cout<<endl;

    //to check if tree is BST or NOT
    if(isBST(root,INT_MIN, INT_MAX)){
        cout<<"BST"<<endl;
    }
    else{
        cout<<"NOT BST"<<endl;
    }
    
return 0;
}
