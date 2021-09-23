#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    string data;
    int data1;
    Node * next, *prev;

    Node(string data, int data1){
        this -> data = data;
        this->data1=data1;
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

    void push_back(string data, int data1){
        Node * node = new Node(data, data1);
        if(tail == NULL){
            tail = node;
            front = node;
        }
        else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void push_front(string data, int data1){
        Node * node = new Node(data, data1);
        if(front == NULL){
            tail = node;
            front = node;
        }
        else{
            node->next = front;
            front->prev = node;
            front = node;
        }
    }
    
    

    void print(){
        Node * node = front;
        while (node != NULL)
        {
            cout << node->data << " " << node->data1 << endl;
            node = node->next;
        }
        cout << endl;
    }
    Node *find_node(string data){
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
    LinkedList *ll = new LinkedList();
    string s;
    vector <pair < string, int> > v;
    ifstream file_("input.txt");
    // cout << "lkj";
    // cout <<1234;
    while (file_ >> s)
    {
        cout << s;
        if(ll->find_node(s) == NULL){
            ll->push_back(s, 1);
            v.push_back(make_pair(s, 1));
        }
        else{
            Node * a = ll->find_node(s);
            a -> data1 = a -> data1+1;
            for (int i = 0; i < v.size(); i++)
            {
                if(v[i].first == s){
                    v[i].second++;
                    break;
                }
            }
            
        }
    }
    // cout << 34567;
    ll->print();
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        ofstream fout("output.txt");
        fout << v[i].first << " " << v[i].second;
        fout.close();
    }
    
    return 0;
}