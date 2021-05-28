#include <bits/stdc++.h>
using namespace std;
#define loop(i, j, k) for (int i = j; i < k; i++)

int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> minCuts(a + 1, vector<int>(b + 1, INT_MAX));
    loop(i, 0, a + 1)
    {
        loop(j, 0, b + 1)
        {
            if (i == j)
                minCuts[i][j] = 0;
            else{
                loop(k, 1, i){
                    minCuts[i][j] = min(minCuts[i][j], minCuts[k][j] + minCuts[i - k][j] + 1);
                }
                loop(k, 1, j){
                    minCuts[i][j] = min(minCuts[i][j], minCuts[i][k] + minCuts[i][j - k] + 1);
                }

            }
        }
    }

    cout << minCuts[a][b];
}
