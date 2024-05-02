#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> vec;

bool isPlanar(int vertices, int edges);
void erase(int vertices, int edges, vec graph);
int main()
{

  vec graph = {
      {0, 0, 0, 1, 1, 1},
      {0, 0, 0, 1, 1, 1},
      {0, 0, 0, 1, 1, 1},
      {1, 1, 1, 0, 0, 0},
      {1, 1, 1, 0, 0, 0},
      {1, 1, 1, 0, 0, 0}};
  int vertices;
  int edges;
  for (int i = 0; i < graph.size(); i++)
    vertices++;
  for (int i = 0; i < graph.size(); i++)
  {
    for (int j = 0; j < graph.size(); i++)
    {
      if (graph[i][j])
        edges++;
    }
  }
  edges /= 2;

  return 0;
}

bool isPlanar(int v, int e)
{
  return (e <= 3 * v - 6);
}

void erase(int vertices, int edges, vec graph)
{
}