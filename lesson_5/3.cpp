#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    string data;
    int data1;
    Node *next, *prev;

    Node(string data, int data1) {
        this->data = data;
        this ->data1=data1;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *front, *tail;

    LinkedList() {
        front = NULL;
        tail = NULL;
    }

    void push_back(string data, int data1) {
        Node *node = new Node(data, data1);
        if (tail == NULL) {
            front = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void push_front(string data, int data1) {
        Node *node = new Node(data, data1);
        if (front == NULL) {
            front = node;
            tail = node;            
        } else {
            node->next = front;
            front->prev = node;
            front = node;
        }
    }

    void pop_back() {
        if (tail == NULL)
            return;
        tail = tail->prev;
        
        if (tail != NULL)
            tail->next = NULL;
        else
            front = NULL; 
    }

    void pop_front() {
        if (front == NULL)
            return;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        else 
            tail = NULL;
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " " << node->data1 << endl;
            node = node->next;
        }
        cout << endl;
    }

    Node *find_node(string data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next;            
        }
        return NULL;
    }

    void insert_node(Node *a, string data, int data1) {
        if (a == tail) 
            push_back(data, data1);
        else {
            Node *b = a->next;
            Node *node = new Node(data, data1);
            a->next = node;
            node->prev = a;
            node->next = b;
            b->prev = node;
        }
    }

    void delete_node(Node *node) {
        if (node == tail)
            this->pop_back();
        else if (node == front)
            this->pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    string s;
    vector <pair < string, int > > v;
    ifstream file("input.txt");
    while (file >> s)
    {
        if(ll->find_node(s) == NULL){
            ll->push_back(s, 1);
            v.push_back(make_pair(s, 1));
        }
        else{
            // Node * a = ll->find_node(s);
            // a->data1 = a->data1 + 1;
            for (int i = 0; i < v.size(); i++)
            {
                if(v[i].first == s){
                    v[i].second++;
                    break;
                }
            }
            
        }
    }
    
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        ofstream fout("output.txt", ios::app); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
        fout <<  v[i].first << " " << v[i].second << endl;; // запись строки в файл
        fout.close();
        // cout << v[i].first << " " << v[i].second << endl;
    }
    
    

    return 0;
}