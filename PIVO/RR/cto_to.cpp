 std::vector<std::vector<int>> delete_last_row_and_column2(const std::vector<std::vector<int>> &matrix)
  {
    // Создаем новый двумерный вектор, в который будем записывать результат.
    std::vector<std::vector<int>> result(matrix.size() - 2);

    // Перебираем строки матрицы.
    for (int row_index = 0; row_index < matrix.size() - 2; row_index++)
    {
      // Создаем новую строку для результата.
      result[row_index].resize(matrix[row_index].size() - 2);

      // Копируем строку из матрицы в новый вектор.
      for (int column_index = 0; column_index < matrix[row_index].size() - 2; column_index++)
      {
        result[row_index][column_index] = matrix[row_index][column_index];
      }
    }
    return result;
  }
  std::vector<std::vector<int>> delete_last_row_and_column3(const std::vector<std::vector<int>> &matrix)
  {
    // Создаем новый двумерный вектор, в который будем записывать результат.
    std::vector<std::vector<int>> result(matrix.size() - 2);

    // Перебираем строки матрицы.
    for (int row_index = 0; row_index < matrix.size() - 2; row_index++)
    {
      // Создаем новую строку для результата.
      result[row_index].resize(matrix[row_index].size() - 2);

      // Копируем строку из матрицы в новый вектор.
      for (int column_index = 0; column_index < matrix[row_index].size() - 2; column_index++)
      {
        result[row_index][column_index] = matrix[row_index][column_index];
      }
    }
    return result;
  }
  /*else
      {

        std::vector<std::vector<int>> matrix2 = delete_last_row_and_column2(adj);
        int edges = countEdges(matrix2);
        if (is_planar(matrix2, edges, matrix2.size()))
          return 2;
        else
        {
          std::vector<std::vector<int>> matrix3 = delete_last_row_and_column3(adj);
          int edges = countEdges(matrix3);
          if (is_planar(matrix3, edges, matrix3.size()))
            return 3;
        }
      }*/