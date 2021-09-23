#include <bits/stdc++.h>

using namespace std;

int main(){
    deque <int> p1;
    deque <int> p2;
    int n;
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if(i == 0){
                cin >> n;
                p1.push_back(n);
            }
            else if(i == 1){
                cin >> n;
                p2.push_back(n);
            }
        }   
    }

    int count = 0;
    while (count <= 1e6)
    {
        if(p1.empty()){
            cout << "second" << " " << count;
            return 0;
        }
        else if(p2.empty()){
            cout << "first" << " " << count;
            return 0;
        }
        else if(p2.front() == 9 && p1.front() == 0){
            p1.push_back(p1.front());
            p1.push_back(p2.front());
            p1.pop_front();
            p2.pop_front();
            count++;
        }
        else if(p2.front() == 0 && p1.front() == 9){
            p2.push_back(p1.front());
            p2.push_back(p2.front());
            p1.pop_front();
            p2.pop_front();
            count++;
        }
        else if(p1.front() > p2.front()){
            p1.push_back(p1.front());
            p1.push_back(p2.front());
            count++;
            p1.pop_front();
            p2.pop_front();
        }
        else if(p2.front() > p1.front()){
            p2.push_back(p1.front());
            p2.push_back(p2.front());
            count++;
            p1.pop_front();
            p2.pop_front();
        }
        else if(p2.front() == p1.front())
        {
            count++;
            cout << count << " ";
        }
        
    }
    cout << "botva";
    

    return 0;
}