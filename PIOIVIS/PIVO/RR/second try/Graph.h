#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

using namespace std;
class Graph
{
private:
  int vertex;
  int edges;
  vector<vector<int>> adj_matrix;

public:
  void setEdges(int edges) { this->edges = edges; }
  void setVertex(int vertex) { this->vertex = vertex; }
  int getEdges() { return edges; }
  int getVertex() { return vertex; }
  void setADJmatrix(vector<vector<int>> adj)
  {
    for (int i = 0; i < vertex; i++)
      for (int j = 0; j < vertex; j++)
        this->adj_matrix = adj;
  }
  int getADJmatrix()
  {

    for (int i = 0; i < vertex; i++)
    {
      cout << i << ": ";
      for (int j = 0; j < vertex; j++)
        cout << adj_matrix[i][j] << ' ';
      cout << '\n';
    }
  }
  int Planar_testing()
  {
  }
};
#endif