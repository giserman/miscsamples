#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i=(c).begin(); i != (c).end(); i++)

const int N = 10;
vector< vector<int> > W;
vector<int> V;

void dfs(int i)
{
    if(!V[i])
    {
        V[i] = true;
        for_each(W[i].begin(), W[i].end(), dfs);
    }
}

bool check_graph_connected_dfs()
{
    int start_vertex = 0;
    V = vector<int>(N, false);
    dfs(start_vertex);
    return (find(V.begin(), V.end(), 0) == V.end());
}

bool check_graph_connected_bfs()
{
    int start_vertex = 0;
    vector<int> V(N, false);
    queue<int> Q;
    Q.push(start_vertex);
    V[start_vertex] = true;
    while(!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for(vector<int>::const_iterator it=W[i].begin(); it != W[i].end(); it++)
        {
            if(!V[*it])
            {
                V[*it] = true;
                Q.push(*it);
            }
        }
    }
    return (find(V.begin(), V.end(), 0) == V.end());
}

int main()
{
    return 1;
}
