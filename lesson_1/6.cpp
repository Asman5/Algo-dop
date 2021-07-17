#include <iostream>
#include <stack>

using namespace std;


int main(){
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.top() << endl;;
    cout << st.size() << endl;
    st.pop();
    cout << st.empty();
    cout << st.top();
    return 0;
}