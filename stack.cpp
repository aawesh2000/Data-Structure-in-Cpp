
#include<iostream>
using namespace std;
#include<math.h>
#include<cstdio>
#include<stdio.h>
#include<algorithm>       
#include<cmath>           
#include<climits>         
#include<cstring>         
#include<string>          
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>


//STACK using VECTOR
/*
class Stack{
private:                    //dont want to tell to anyone thats why private
    vector <int> v;
public:                     //this methods are to be used by users thats why public
    void push(int data){
        v.push_back(data);
    }
    
    bool empty(){           //to check wheather stack is empty or not
        return v.size()==0;
    }
    
    void pop(){             //pop from stack
        if(!empty()){
            v.pop_back();
        }
    }

    int top(){              //to get element at the TOP
        return v[v.size()-1];           //will return (length of stack - 1)th element
    }

};

int main(){
    Stack s;

    for(int i=0;i<=5;i++){
        s.push(i*i);
    }

    cout<<"top value in stack : "<<s.top()<<" "<<endl;         
    
    
    cout<<"after poping values : ";
    while(!s.empty()){
        cout<<s.top()<<" ";    
        s.pop();
    }
    cout<<endl;
}

*/

//-------------------------------------------using template--------------------------------------//


/*
template<typename T>
class Stack{
private:                    //dont want to tell to anyone thats why private
    vector <T> v;
public:                     //this methods are to be used by users thats why public
    void push(T data){
        v.push_back(data);
    }
    
    bool empty(){           //to check wheather stack is empty or not
        return v.size()==0;
    }
    
    void pop(){             //pop from stack
        if(!empty()){
            v.pop_back();
        }
    }

    T top(){              //to get element at the TOP
        return v[v.size()-1];           //will return (length of stack - 1)th element
    }

};

int main(){
    Stack<int>s;     

    for(int i=0;i<=5;i++){
        s.push(i*i);
    }

    cout<<"top value in stack : "<<s.top()<<" "<<endl;         
    
    
    cout<<"after poping values : ";
    while(!s.empty()){
        cout<<s.top()<<" ";    
        s.pop();
    }
    cout<<endl;
}

*/

//stack using LL



struct node{
    int data;
    node *next;
};
 node *top = NULL;      //top ptr is NULL initially

 bool isEmpty(){
     //empty when top ptr is NULL
     if(top == NULL){
         return true;
     }
     else{
         return false;
     }
 }

 void push(int value){
     node *ptr = new node();
     ptr->data = value;
     ptr->next = top;
     top = ptr;
 }

void pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        node *ptr = top;
        top = top->next;
        delete(ptr);
    }
}

void display() {
   struct node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

void showTop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Element at top is : "<<top->data<<endl ;
    }
}

int main(){
    push(1);
    push(2);
    push(4);
    push(5);
    push(6);
    display();
    showTop();
    pop();
    pop();
    display();
    showTop();
    display();
    
}


