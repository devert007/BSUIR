#include <iostream>
#include <vector>

using namespace std;

bool isPlanar(vector<vector<int>> &adjacencyMatrix)
{
  int n = adjacencyMatrix.size();
  vector<int> degrees(n, 0);

  // Вычисляем степени вершин
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      degrees[i] += adjacencyMatrix[i][j];
    }
  }

  // Проверяем условие планарности
  for (int i = 0; i < n; i++)
  {
    if (degrees[i] > 3)
    {
      return false;
    }
  }

  // Проверяем теорему Куратовского
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (adjacencyMatrix[i][j] == 1)
      {
        // Удаляем ребро (i, j)
        adjacencyMatrix[i][j] = 0;
        adjacencyMatrix[j][i] = 0;

        // Проверяем, остается ли граф планарным
        if (!isPlanar(adjacencyMatrix))
        {
          // Восстанавливаем ребро (i, j)
          adjacencyMatrix[i][j] = 1;
          adjacencyMatrix[j][i] = 1;
          return false;
        }

        // Восстанавливаем ребро (i, j)
        adjacencyMatrix[i][j] = 1;
        adjacencyMatrix[j][i] = 1;
      }
    }
  }

  return true;
}

int main()
{
  // Пример графа смежности
  vector<vector<int>> adjacencyMatrix = {
      {0, 1, 1, 1, 1},
      {1, 0, 1, 1, 1},
      {1, 1, 0, 1, 1},
      {1, 1, 1, 0, 1},
      {1, 1, 1, 1, 0}};

  int n = adjacencyMatrix.size();
  int minVerticesToRemove = n;

  // Перебираем все возможные подмножества вершин
  for (int i = 1; i < (1 << n); i++)
  {
    vector<vector<int>> subgraph(n, vector<int>(n, 0));

    // Создаем подграф, содержащий только выбранные вершины
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        for (int k = 0; k < n; k++)
        {
          subgraph[j][k] = adjacencyMatrix[j][k];
        }
      }
    }

    // Проверяем, является ли подграф планарным
    if (isPlanar(subgraph))
    {
      int verticesToRemove = n - __builtin_popcount(i);
      minVerticesToRemove = min(minVerticesToRemove, verticesToRemove);
    }
  }

  cout << "Минимальное количество вершин, которые необходимо удалить: " << minVerticesToRemove << endl;

  return 0;
}