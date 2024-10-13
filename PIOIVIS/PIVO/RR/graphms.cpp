#include <iostream>
#include <algorithm>
using namespace std;
class Graph
{
private:
  bool **adj_matrix;
  int vertex;

public:
  Graph(int vertex)
  {
    this->vertex = vertex;
    adj_matrix = new bool *[vertex];
    for (int i = 0; i < vertex; i++)
    {
      adj_matrix[i] = new bool[vertex];
      for (int j = 0; j < vertex; j++)
        adj_matrix[i][j] = false; // заполняем матрицу смежности нулями
    }
  }

  void add_rebra(int u, int v)
  {
    adj_matrix[u][v] = true;
    adj_matrix[v][u] = true;
  }

  void print()
  {
    for (int i = 0; i < vertex; i++)
    {
      cout << i << ": ";
      for (int j = 0; j < vertex; j++)
        cout << adj_matrix[i][j] << ' ';
      cout << '\n';
    }
  }
  ~Graph()
  {
    for (int i = 0; i < vertex; i++)
      delete[] adj_matrix[i];
    delete[] adj_matrix;
  }
};

int main()
{
  Graph h(5);
  h.add_rebra(0, 1);
  h.add_rebra(1, 2);
  h.add_rebra(1, 3);
  h.add_rebra(3, 4);
  h.print();

  return 0;
}