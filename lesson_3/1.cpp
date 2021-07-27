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
        top = top -> next;
        sz--;
    }
    int size(){
        return this->sz;
    }
};

int main(){
    Stack * st = new Stack();
    string s;
    while(true){
        cin >> s;
        if(s == "size"){
            cout << st->size() << "\n";
        }
        else if(s == "push"){
            int n;
            cin >> n;
            st -> push(n);
            cout << "ok" << "\n";
        }
        else if(s == "pop"){
            if(st -> sz > 0){
                cout << st -> top -> data << "\n";
                st -> pop();
            }
            else{
                cout << "error" << "\n";
            }
        }
        else if(s == "back"){
            if(st -> sz > 0){
                cout << st -> top -> data << "\n";
            }
            else{
                cout << "error" << "\n";
            }
        }
        else if(s == "clear"){
            while (st -> size() != 0)
            {
                st -> pop();
            }
            cout << "ok" << "\n";
        }
        else if(s == "exit"){
            cout << "bye" << "\n";
            exit(0);
            return 0;
            break;
        }
    }


    return 0;
}
