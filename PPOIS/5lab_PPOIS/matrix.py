def matrix_multiplication(A, B):
    # Проверяем, что размеры матриц совместимы
    if len(A[0]) != len(B):
        raise ValueError("Matrices are not aligned for multiplication")
    # Создаём результирующую матрицу
    result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    # Выполняем умножение
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    return result
