#include <iostream>
#include "Graph.h"
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> matrix;

  ifstream input_file("graph4.txt");

  // Читаем размерность массива
  int rows1, e;
  input_file >> rows1 >> e;

  // Заполняем вектор
  for (int i = 0; i < rows1; i++)
  {
    vector<int> row(rows1);
    for (int j = 0; j < rows1; j++)
    {
      input_file >> row[j];
    }
    matrix.push_back(row);
  }
  // Закрываем файл
  input_file.close();
  ////////////////////////////////////////////////////////////////////////////////////////
  Graph graph;
  graph.setVertex(rows1);
  graph.setEdges(e);
  graph.setADJmatrix(matrix);
  graph.getADJmatrix();
  cout << "planarnost' " << graph.Planar_testing();

  return 0;
}