#include <iostream>

using namespace std;

int main(){
    int max = -1e8;
    int vasa = -1e8;
    int n;
    int k;
    cin >> n;

    
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if(max < k){
            vasa = max;
            max = k;
        }
        if(k > vasa && k < max){
            vasa = k;
        }
    }
    cout << vasa;


    return 0;
}