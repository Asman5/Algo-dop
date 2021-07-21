#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Stack{
    public:
    Node * top;
    int sz;
    Stack(){
        top = NULL;
        sz = 0;
    }
    void push(int data){
        Node * node = new Node(data);
        node -> next = top;
        top = node;
        sz++;
    }
    void pop(){
        if(top != NULL){
            top = top -> next;
        }
    }
    int size(){
        return this -> sz;
    }
    bool empty(){
        return(sz==0);
    }
};

int main(){
    Stack * st = new Stack();
    st -> push(10);
    st -> push(20);
    st -> push(30);
    cout << st->size() << " " << st -> empty();
    // cout << st->top->data;
    // st->pop();
    // cout << st -> top -> next -> data;

    return 0;
}