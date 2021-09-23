#include <bits/stdc++.h>

using namespace std;

int main(){
    stack <int> st;
    string s;
    int a = 0;
    int result = 0;
    while (cin >> s)
    {
        if(s == "+" || s == "*" || s == "-"){
            a = st.top();
            st.pop();
            if(s == "+"){
                result = a + st.top();
            }
            else if(s == "-"){
                result = st.top() - a;
            }
            else if(s == "*"){
                result = a * st.top();
            }
            st.pop();
            st.push(result);
            // result = 0;  
        }
        if(s >= "0" && s <= "9"){
            st.push(int(s[0] - 48));
        }
    }
    cout << st.top();

    return 0;
}