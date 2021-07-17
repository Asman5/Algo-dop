#include <iostream>

using namespace std;

int p[1000002];

void primes(int n){
    for (int i = 2; i * i <= n; i++)
    {
        int k = i;
        if (p[i] == 0)
        {
            while (k + i <= n)
            {
                k += i;
                p[k] = 1;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if(p[i] == 0){
            cout << i << " ";
        }
    }
    
}

int main(){
    int n;
    cin >> n;
    primes(n);

    return 0;
}