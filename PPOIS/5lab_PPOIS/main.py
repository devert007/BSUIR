import pygame
import math
import sys

# Инициализация Pygame
pygame.init()

# Настройки экрана
WIDTH, HEIGHT = 500, 500
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Анимация гиперкуба")
clock = pygame.time.Clock()

# Цвета
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Вершины гиперкуба (16 точек в 4D-пространстве)
vertices_4d = [
    [-1, -1, -1, -1], [1, -1, -1, -1], [-1, 1, -1, -1], [1, 1, -1, -1],
    [-1, -1, 1, -1], [1, -1, 1, -1], [-1, 1, 1, -1], [1, 1, 1, -1],
    [-1, -1, -1, 1], [1, -1, -1, 1], [-1, 1, -1, 1], [1, 1, -1, 1],
    [-1, -1, 1, 1], [1, -1, 1, 1], [-1, 1, 1, 1], [1, 1, 1, 1],
]

# Ребра гиперкуба (соединения вершин)
edges = [
    [0, 1], [1, 3], [3, 2], [2, 0], [4, 5], [5, 7], [7, 6], [6, 4],
    [0, 4], [1, 5], [2, 6], [3, 7], [8, 9], [9, 11], [11, 10], [10, 8],
    [12, 13], [13, 15], [15, 14], [14, 12], [8, 12], [9, 13], [10, 14], [11, 15],
    [0, 8], [1, 9], [2, 10], [3, 11], [4, 12], [5, 13], [6, 14], [7, 15],
]

# Функция для проекции 4D -> 2D (через 3D)
def project_4d_to_2d(vertex, angle):
    # Угол для вращения
    cos_a = math.cos(angle)
    sin_a = math.sin(angle)

    # Ротация в 4D-пространстве (W-Z)
    x, y, z, w = vertex
    z3d = z * cos_a - w * sin_a
    w3d = z * sin_a + w * cos_a

    # Ротация в 3D-пространстве (X-Z)
    x2d = x * cos_a - z3d * sin_a
    z2d = x * sin_a + z3d * cos_a

    # Перспективная проекция
    perspective = 2 / (2 - w3d) if w3d < 2 else 1
    x2d *= perspective
    y2d = y * perspective

    # Преобразование в координаты экрана
    screen_x = int(WIDTH / 2 + x2d * WIDTH / 4)
    screen_y = int(HEIGHT / 2 - y2d * HEIGHT / 4)
    return screen_x, screen_y

# Главный цикл
def main():
    angle = 0  # Угол вращения

    while True:
        # Обработка событий
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        # Очистка экрана
        screen.fill(BLACK)

        # Проекция вершин гиперкуба
        projected_vertices = [project_4d_to_2d(v, angle) for v in vertices_4d]

        # Отрисовка рёбер
        for edge in edges:
            start, end = edge
            pygame.draw.line(screen, WHITE, projected_vertices[start], projected_vertices[end], 1)

        # Обновление угла для вращения
        angle += 0.02

        # Обновление экрана
        pygame.display.flip()

        # Ограничение FPS
        clock.tick(60)

# Запуск программы
if __name__ == "__main__":
    main()