#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int c = min(a, b);
    for (int i = c; i > 1 ; i--)
    {
        if(b % i == 0 && a % i == 0){
            cout << i;
            return 0;
        }
    }
    
    return 0;
}
