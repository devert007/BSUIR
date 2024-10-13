#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class graph
{
private:
  vector<vector<int>> adj;

public:
  int V;

  graph(int V) // коструктор
  {
    this->adj = vector<vector<int>>(V);
  }

  void add_rebra(int v, int w) // закидываем ребра в массив смежности
  {
    this->adj[v].push_back(w);
    this->adj[w].push_back(v);
  }

 /* int is_Planar() // осуществляется обходом в глубину
  {
    vector<bool> visit(this->adj.size(), false);
    stack<int> stack;
    for (int i = 0; i < V; i++)
    {
      stack.push(i);
      visit[i] = true;
      while (!stack.empty())
      {
        int vertex = stack.top();
        stack.pop();
        for (int neighbor : adj[vertex])
        {
          if (!visit[neighbor])
          {
            stack.push(neighbor);
            visit[neighbor] = true;
          }
          else if (visit[neighbor] == true && vertex != neighbor)
            return false;
        }
      }
    }
    return true;
  }
*/
  int about_remove()
  {
    vector<vector<int>> cycles;
    vector<bool> visit(this->adj.size(), false);
    stack<int> stack;
    for (int i = 0; i < V; i++)
    {
      stack.push(i);
      visit[i] = true;
      while (!stack.empty())
      {
        int vertex = stack.top();
        stack.pop();
        for (int neighbor : adj[vertex])
        {
          if (!visit[neighbor])
          {
            stack.push(neighbor);
            visit[neighbor] = true;
          }
          else if (vertex != i)
          {
            cycles.push_back({i, neighbor, vertex});
          }
        }
      }
    }
    // ищем циклы где у вершины степень 2или 3
    vector<int> step(V);
    for (int i = 0; i < V; i++)
    {
      for (int j : adj[i])
      {
        step[i]++; // счетчик степени
      }
    }
    int remove = 0;
    for (auto cycle : cycles)
    {
      for (int i = 0; i < 3; i++)
      {
        if (step[cycle[i]] == 2 || step[cycle[i]] == 3)
        {
          remove++;
          for (int j = 0; j < 3; j++)
            step[cycle[j]]--;
        }
        break;
      }
    }
    return remove;
  }
};

int main()
{

  int v, e;
  cout << "vvedite kolichestvo vershin grapha" << '\n';
  cin >> v;
  cout << "vvedite kolichestvo reber grapha" << '\n';
  cin >> e;
  graph gr(v);
  gr.V = v;
  vector<vector<int>> adj(v);
  cout << "vvedite smegnye rebra" << '\n';
  for (int i = 0; i <= e; i++)
  {
    int u, w;
    cin >> u >> w;
    gr.add_rebra(u, w);
  }
  cout << gr.about_remove() << '\n';
}