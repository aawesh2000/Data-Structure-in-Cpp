//Basic LL, creating and travesing and printing 

#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};

void printList(node *n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
}

int main(){
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);              //given argument of starting i.e head so it will print from head till last

}
