#include <iostream>

#include <queue>

using namespace std;

queue <pair <int, int> > q;//number, steps
int used[1000000];

int f(int a, int b){
    q.push(make_pair(a, 0));
    used[a] = a;
    while (!q.empty())
    {
        int t = q.front().first;
        int d = q.front().second;
        if(t == b){
            return d;
        }
        if(used[t + 1] == 0){
            q.push(make_pair(t + 1, d + 1));
            used[t + 1] = t;
        }
        if(used[t * 2] == 0){
            q.push(make_pair(t * 2, d + 1));
            used[t * 2] = t;
        }
        if(used[t - 1] == 0){
            q.push(make_pair(t - 1, d + 1));
            used[t - 1] = t;
        }
        if(used[t / 2] == 0){
            q.push(make_pair(t / 2, d + 1));
            used[t / 2] = t;
        }
        q.pop();
    }
    return 0;
}


int main(){
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << endl;
    vector <int> v;
    v.push_back(b);
    int t = b;
    while (used[t] != t)    
    {
        t = used[t];
        v.push_back(t);
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}