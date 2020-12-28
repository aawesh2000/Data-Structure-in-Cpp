
struct node{
    int data;
    node *next;
};
node *front = NULL;
node *rear = NULL;

bool isEmpty(){
    if(front == NULL && rear == NULL){
        return true;
    }
    return false;
}

void enqueu(int value){
    node *ptr = new node();
    ptr->data = value;
    ptr->next = NULL;
    if(front==NULL){
        front = ptr;
        rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
}

void dequeu(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else if(front==rear){
        free(front);
        front = rear = NULL;
    }
    else{
        node *ptr = front;
        front = front->next;
        free(ptr);
    }
}

void showFront(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Front of Queue : "<<front->data<<endl;
    }
}

void display() {
   node *temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}

int main(){
    enqueu(5);
    dequeu();
    display();
    enqueu(6);
    enqueu(7);
    enqueu(8);
    enqueu(9);
    dequeu();
    showFront();
    display();

}
