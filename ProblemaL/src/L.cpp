#include <bits/stdc++.h>

using namespace std;

typedef long long my_long;

typedef std::pair<int, int> my_pair;

typedef std::vector<my_pair> my_adjacents;

my_adjacents    graph[25001];

bool    in_queue[25001];
bool    processed[25001];
int     max_capacity[25001];

int main(int argc, char * argv[])
{
    int M, N;
    int u, v, c, source, target;

    while (cin >> N >> M)
    {
        for (int n = 0; n < N; n++)
        {
            graph[n].clear();
            processed[n] = false;
            in_queue[n] = false;
            max_capacity[n] = 0;
        }

        for (int m = 0; m < M; m++)
        {
            cin >> u >> v >> c;
            
            graph[u - 1].push_back(my_pair(v - 1, c));
        }
        cin >> source >> target;
        --source;
        --target;
        in_queue[source] = true;
        max_capacity[source] = 10000000; // greater than 10^6

        queue<int>  q;
        q.push(source);

        while (! q.empty())
        {
            u = q.front(); q.pop();
            in_queue[u] = false;

            for (auto & p : graph[u])
            {
                v = p.first;
                c = min(max_capacity[u], p.second);

                if (c > max_capacity[v])
                {
                    max_capacity[v] = c;
                    if (v != target  &&  ! in_queue[v])
                    {
                        in_queue[v] = true;
                        q.push(v);
                    }
                }
            }
            processed[u] = true;
        }

        cout << max_capacity[target] << endl;
    }

    return EXIT_SUCCESS;
}
