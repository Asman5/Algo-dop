#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack <int> st[n];
    stack <int> st_1[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int t;
            cin >> t;
            st[i].push(t);
            st_1[i].push(t);
        }
    }
    bool pr;
    for (int i = 0; i < n; i++)
    {
        int len_2  = st_1[i].size();
        for (int j = 0; j < len_2; j++)
        {
            
            if((i + 1) != st_1[i].top())
            {
                pr = false;
                
                break;
                
            }
            st_1[i].pop();
            // cout << st[i].top() << " ";
        }
        if(pr == false){
            break;
        }
        
        
    }
    if(pr == true)
    {
        return 0;
    }
    
    int count_1 = 0;
    for (int i = 1; i < n; i++)
    {
        while(!st[i].empty())
        {
            st[0].push(st[i].top());
            if(n == 2){
            // cout << i + 1 << " " << 1;
                count_1++;
                st[i].pop();
            }
            else if(n != 2)
            {
                cout << i + 1 << " " << 1 << endl;
                st[i].pop();
            }
        }
        
    }
    
    int count = 0;
    if(n == 2)
    {
        
        int l_0 = st[0].size();
        for (int i = 0; i < l_0; i++)
        {
            if(st[0].top() == 2)
            {
                count++;
                st[0].pop();
            }
            else if(st[0].top() == 1)
            {
                for (int j = 0; j < l_0 - i; j++)
                {
                    if(st[0].top() == 2)
                    {
                        cout << 0;
                        return 0;
                    }
                    st[0].pop();
                    
                    
                }
                break;

                
            }
        }
        
    }
    
    if(n == 2)
    {
        for (int i = 0; i < count_1; i++)
        {
            cout << 2 << " " << 1 << endl;
        }
        for (int i = 0; i < count; i++)
        {
            cout << 1 << " " << 2 << endl;
        }
        return 0;
        
    }
    
    int l0 = st[0].size();
    for (int i = 0; i < l0; i++)
    {
        if(st[0].top() != 1)
        {
            st[st[0].top() - 1].push(st[0].top());
            cout << 1 << " " << st[0].top() << endl;
            st[0].pop();
        }
        else
        {
            st[n - 1].push(st[0].top());
            cout << 1 << " " << n << endl;
            st[0].pop();
        }
        
    }
    int l1 = st[n - 1].size();
    for (int i = 0; i < l1; i++)
    {
        if(st[n - 1].top() != 1)
        {
            st[n - 2].push(st[n - 1].top());
            cout << n << " " << n - 1 << endl;
            st[n - 1].pop();
        }
        else
        {
            st[0].push(st[n - 1].top());
            cout << n << " " << 1 << endl;
            st[n - 1].pop();
        }
        
    }
    int l2 = st[n - 2].size();
    for (int i = 0; i < l2; i++)
    {
        while(st[n - 2].top() != (n - 1))
        {
            st[n - 1].push(st[n - 2].top());
            cout << n - 1 << " " << n << endl;
            st[n - 2].pop();
            if(st[n - 2].empty())
            {
                return 0;
            }
        }
    }
    
    return 0;
}