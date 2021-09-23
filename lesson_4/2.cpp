#include <bits/stdc++.h>
using namespace std;

int main(){
    deque <string> deq1;
    deque <string> deq2;
    deque <string> deq3;
    int n;
    string s;
    while (cin >> n)
    {
        if(n == 9){
            cin >> s;
            deq1.push_back(s);
        }
        if(n == 10){
            cin >> s;
            deq2.push_back(s);
        }
        if(n == 11){
            cin >> s;
            deq3.push_back(s);
        }
    }
    for (int i = 0; i < deq1.size(); i++)
    {
        cout << 9 << " " << deq1[i] << endl;
    }
    for (int i = 0; i < deq2.size(); i++)
    {
        cout << 10 << " " << deq2[i] << endl;
    }
    for (int i = 0; i < deq3.size(); i++)
    {
        cout << 11 << " " << deq3[i] << endl;
    }
    

    return 0;
}