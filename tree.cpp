//TREE
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

//tree
// Example OF TREE:-
//                   3
//                 /  \ 
//                1    2 
//                    /
//                   4

//this tree is having height - 4
// Types of Traversals:-
// 1)Inorder :- (LEFT,ROOT,RIGHT) => 1,3,4,2
// 2)Preorder :- (ROOT,LEFT,RIGHT) => 3,1,2,4
// 3)Postorder :- (LEFT,RIGHT,ROOT) => 1,4,2,3
// 4)Levelwise :- =>3,1,2,4
//----------------------------------------------------------------------------------------------//

//building binary search tree
//using recurrsion

class node{
    public:                         
        int data;
        node*left;
        node*right;

        node(int d){                
            data = d;
            left = NULL;
            right = NULL;
        }
};



node* buildTree(){          
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;

}

void print_preorder(node *root){                 //preorder=> ROOT, LEFT, RIGHT
    if(root==NULL){
        return;
    }
    //otherwise
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(node *root){                 //postorder=> LEFT, RIGHT, ROOT
    if(root==NULL){
        return;
    }
    //otherwise
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}

int height(node *root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;
}

void print_inorder(node *root){                 //inorder=> LEFT, ROOT, RIGHT
    if(root==NULL){
        return;
    }
    //otherwise
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}

//print kth level
void printK_th_level(node *root, int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    
    printK_th_level(root->left, k-1);
    printK_th_level(root->right, k-1);
}

//level wise traversal
void print_all_level_wise(node *root){
    int k;
    int H = height(root);
    for(int i=1; i<=H; i++){
        printK_th_level(root, i);
        cout<<endl;
    }
    return;
}

void BFS_TRAVERSAL(node*root){
    queue<node*> q;                         //making queue 
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

//count no of nodes in TREE
int count(node *root){
    if(root==NULL){
        return 0;
    }
    return (1 + count(root->left) + count(root->right));
}

//sum of all nodes in TREE
int sum_of_ALLnodes(node *root){
    if(root==NULL){
        return 0;
    }
    return (root->data + sum_of_ALLnodes(root->left) + sum_of_ALLnodes(root->right));
}

int replace_sum(node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int leftSUM = replace_sum(root->left);
    int rightSUM = replace_sum(root->right);

    int temp = root-> data;
    root->data = leftSUM + rightSUM;
    return temp + root->data; 
}



int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2,op3));
}

int main(){
    cout<<"ENTER VALUES : ";
    node* root = buildTree();
    int k,h;
    
    
    cout<<"INORDER : ";
    print_inorder(root);                        //inorder=> LEFT, ROOT, RIGHT
    cout<<endl;
    cout<<"PREORDER : ";
    print_preorder(root);                       //preorder=> ROOT, LEFT, RIGHT
    cout<<endl;
    cout<<"POSTORDER : ";
    print_postorder(root);                      //postorder=> LEFT, RIGHT, ROOT
    cout<<endl;
    cout<<"LEVELWISE : ";
    cout<<endl;
    print_all_level_wise(root);
    
    h=height(root);
    cout<<"HEIGHT OF TREE IS : "<<h<<endl;
    
    cout<<"VALUE OF WHICH LEVEL U WANT?? ENTER K : ";
    cin>>k;
    cout<<"VALUE AT Kth LEVEL : ";
    printK_th_level(root,k);
    cout<<endl;

    cout<<"BFS_TRAVERSAL : ";
    BFS_TRAVERSAL(root);

    cout<<"TOTAL NO COUNT OF NODE'S : ";
    cout<<count(root)<<endl;
    
    cout<<"SUM OF ALL NODES IN TREE : ";
    cout<<sum_of_ALLnodes(root)<<endl;
    
    
    cout<<"DIAMETER OF TREE : ";
    cout<<diameter(root)<<endl;

    cout<<"BFS_TRAVERSAL AFTER REPLACING WITH SUM : ";
    BFS_TRAVERSAL(root);
}
