#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * next, *prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

};


class LinkedList{
    public:
    Node * front, * tail;
    
    LinkedList(){
        tail = NULL;
        front = NULL;
    }

    void push_back(int data){
        Node * node = new Node(data);
        if(tail == NULL){
            tail = node;
            front = node;
        }
        else{
            // node -> next = tail;
            // tail -> prev = node;
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void push_front(int data){
        Node * node = new Node(data);
        if(front == NULL){
            tail = node;
            front = node;
        }
        else{
            // front->next = node;
            // node->prev = front;
            node->next = front;
            front->prev = node;
            front = node;
        }
    }
    void insert_node(Node * a, int data){
        if(a = front){
            push_front(data);
        }
        else{
            Node *c = new Node(data);
            Node *b = a -> next;
            a->next = c;
            c->prev = a;
            c->next = b;
            b->prev = c;
        }
    }
    void pop_back(){
        if(tail == NULL)
            return;
            
        tail = tail->prev;
        if(tail != NULL){
            tail->next = NULL;
        }
        else
            front = NULL;
    }

    void pop_front(){
        if(front == NULL){
            return;
        }
        front = front ->next;
        if(front != NULL){
            front -> prev = NULL;
        }
        else
            tail = NULL;
    }
    void delete_node(Node * node){
        if(node == tail){
            this->pop_back();
        }
        else if(node == front){
            this->pop_front();
        }
        else{
            Node *a = node->prev;
            Node * b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void print(){
        Node * node = front;
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
    void *find_node(int data){
        Node * node = front;
        while (front != NULL)
        {
            if(node->data == data){
                return node;
            }
            node = node->next;
        }
        return NULL;
        
    }
};

int main(){
    LinkedList *link = new LinkedList();
    link->push_back(10);
    link->push_back(20);
    link->push_back(2);
    link->push_front(8);
    // link->print();
    // cout << endl;
    // link->pop_back();
    // link->print();
    // link->pop_front();
    // cout << endl;
    // link->print();
    // cout << endl;
    Node * node = link->front;
    // cout << "ihn;ksdj";
    link->insert_node(node, 122);
    // cout << "iohln";
    cout << endl;
    // cout << "yes";
    link->print();
    return 0;
}