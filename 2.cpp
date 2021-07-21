#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this -> data = data;
    }
    
};


int main(){
    Node * node1 = new Node(50);
    Node * node2 = new Node(10);
    Node * node3 = new Node(5);
    node1 -> next = node2;
    node2 -> next = node3;
    cout << node1 << " " << node2 << " " << node3 << endl;
    cout << node1 -> next << endl;
    cout << node1 -> data << endl;
    cout << node1 -> next -> next -> data;

    return 0;
}