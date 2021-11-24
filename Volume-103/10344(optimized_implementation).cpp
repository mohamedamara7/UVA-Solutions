#include <bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

vector<int>v(5);
vector<bool>visited(5, 0);
bool solved = false;
void solve2(int result, int idx = 0, bool first_call = 1)
{
    if (solved)
        return;
    if (idx == 5)
    {
        solved = (result == 23);
        return;
    }
    for (int i = 0;i < 5;i++)
        if (!visited[i])
        {
            visited[i] = 1;
            if (first_call)
                solve2(v[i], idx + 1, 0);
            else
            {
                solve2(result + v[i], idx + 1, 0);
                solve2(result - v[i], idx + 1, 0);
                solve2(result * v[i], idx + 1, 0);
            }
            visited[i] = 0;
        }
}
int main()
{
    fastIO();
    while (true)
    {
        solved = false;
        for (int i = 0;i < 5;i++)
            cin >> v[i];
        if (!v[0])
            return 0;
        solve2(0);
        if (solved)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}
