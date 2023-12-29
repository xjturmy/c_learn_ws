#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> match;
vector<bool> vis;
vector<bool> check;

bool find(int u)
{
    for (int v = 0; v < m; v++)
    {
        if (g[u][v] && !vis[v])
        {
            vis[v] = true;
            if (match[v] == -1 || find(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res = 0;
    match.assign(m, -1);
    for (int i = 0; i < n; i++)
    {
        vis.assign(m, false);
        if (find(i))
            res++;
    }
    return res;
}

void dfs(int u)
{
    check[u] = true;
    for (int v = 0; v < m; v++)
    {
        if (g[u][v] && match[v] != -1 && !check[match[v]])
        {
            dfs(match[v]);
        }
    }
}

int main()
{
    cin >> n >> m;
    g.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)//手动输入需要进行匹配的值
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    int matches = hungary();
    check.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        if (match[i] == -1)
        {
            dfs(i);
        }
    }
    cout << n + m - matches - std::count(check.begin(), check.end(), false) << endl;
    //   cout << n + m - matches - count(check.begin(), check.end(), false) << endl;
    return 0;
}
