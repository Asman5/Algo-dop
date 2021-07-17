#include <stack>
#include <iostream>

using namespace std;

bool is_ok(string s){
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            st.push(s[i]);
        else{
            if(st.empty())
                return 0;
            st.pop();
        }
    }
    // if(st.empty() == true)
    //     return 1;
    // else
    //     return false;
    return(st.empty());
    

}

int main(){
    string s;
    cin >> s;
    if(is_ok(s))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}