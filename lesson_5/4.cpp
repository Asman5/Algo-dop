#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> min_s(n, 1e4);
    vector <int> max_c(m, -1e4);
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if(min_s[i] > a[i][j]){
                min_s[i] = a[i][j];
            }
            if(max_c[j] < a[i][j]){
                max_c[j] = a[i][j];
            }
        }
        
    }
    int otv = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j] == min_s[i] && a[i][j] == max_c[j])
                otv++;
        }
        
    }
    cout << otv;


    return 0;
}