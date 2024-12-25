import pygame # используется для создания графики.
import math #для работы с тригонометрическими функциями.
import os #для управления окружением, например, настройки окна.
from matrix import matrix_multiplication #функция для умножения матриц, реализованная отдельно.
from bresenham import bresenham #реализация алгоритма Брезенхэма для отрисовки линий.
from numpy import interp #Функция из NumPy для интерполяции значений.
 

 ##создание окна приложения
os.environ['SDL_VIDEO_CENTERED'] = '1'
background, bright = (13,13,13), (60,180,120)
width, height = 800, 800 
 
 ##создаётся экран заданного размера и частота обновления окна
pygame.init()
pygame.display.set_caption('HYPERCUBE/TESSERACT')
screen = pygame.display.set_mode((width, height))
clock = pygame.time.Clock()
fps = 60
 
#ASCII шрифты
lineFont = pygame.font.SysFont('scheherazade', 20, bold=False)
cornerFont = pygame.font.SysFont('nachlieliclm', 24, bold=True)
 
#Tesseract information 
angle = 0 
cube_position = [width//2, height//2]
scale = 2800 
speed = 0.01
points = [n for n in range(16)]
 

 #описываются координаты 16 вершин четырёхмерного гиперкуба. Каждая вершина — это четырёхмерный вектор 
# [𝑥, 𝑦, 𝑧, 𝑤] где w — четвёртая координата.
points[0] = [[-1], [-1], [1], [1]]
points[1] = [[1], [-1], [1], [1]]
points[2] = [[1], [1], [1], [1]]
points[3] = [[-1], [1], [1], [1]]
points[4] = [[-1], [-1], [-1], [1]]
points[5] = [[1], [-1], [-1], [1]]
points[6] = [[1], [1], [-1], [1]]
points[7] = [[-1], [1], [-1], [1]]
points[8] = [[-1], [-1], [1], [-1]]
points[9] = [[1], [-1], [1], [-1]]
points[10] = [[1], [1], [1], [-1]]
points[11] = [[-1], [1], [1], [-1]]
points[12] = [[-1], [-1], [-1], [-1]]
points[13] = [[1], [-1], [-1], [-1]]
points[14] = [[1], [1], [-1], [-1]]
points[15] = [[-1], [1], [-1], [-1]]
 
 ##соединяет две вершины линией с помощью алгоритма Брезенхэма:
def connect_point(i, j, k, offset, lineChar = ':', skip = 7):
    a = k[i + offset]
    b = k[j + offset]
    line = bresenham(a[0], a[1], b[0], b[1])
 
    s = skip 
    for point in line: 
        s -= 1
        if s == 0:
            # отображение ASCII символа
            text_display(lineChar, point[0], point[1])
        if s < 0:
            s = skip
 
def text_display(letter, x_pos, y_pos):##    рисует текст на экране:
    text = lineFont.render(str(letter), True, bright)
    screen.blit(text, (x_pos, y_pos))


 ##отображает точки вершин, используя интерполяцию для изменения яркости и размера:
def corner_display(x, y, z, w, interpolateColor = True, fontSizeInterpolate = True):
    if interpolateColor:
        interpolatedColor = (interp(z, [0.1, 0.27], [background[0], bright[0]]), interp(z, [0.1, 0.27], [background[1], bright[1]]), interp(z, [0.1, 0.27], [background[2], bright[2]]))
    else: 
        interpolatedColor = bright
    if fontSizeInterpolate:
        fontSize = round(int(interp(w, [0.1, 0.27], [50, 76])))
        cornerFont = pygame.font.SysFont('nachlieliclm', fontSize, bold=True)
 
    text = cornerFont.render('.', True, interpolatedColor)
    screen.blit(text, (x, y-fontSize / 2))
 
run = True
while run: 
    clock.tick(fps)
    screen.fill(background)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_ESCAPE:
                run = False
    
    index = 0
    projected_points = [j for j in range(len(points))]
 #Гиперкуб вращается в четырёх измерениях с помощью матриц вращения.

    rotation_x = [[1, 0, 0],
                  [0, math.cos(angle), -math.sin(angle)],
                  [0, math.sin(angle), math.cos(angle)]]
 
    rotation_y = [[math.cos(angle), 0, -math.sin(angle)],
                  [0, 1, 0],
                  [math.sin(angle), 0, math.cos(angle)]]
 
    rotation_z = [[math.cos(angle), -math.sin(angle), 0],
                  [math.sin(angle), math.cos(angle), 0],
                  [0, 0 ,1]]             
 
    tesseract_rotation = [[1, 0, 0],
                          [0, math.cos(-math.pi/2), -math.sin(-math.pi/2)],
                          [0, math.sin(-math.pi/2), math.cos(-math.pi/2)]]
 
    rotation4d_xy= [[math.cos(angle), -math.sin(angle), 0, 0],
                  [math.sin(angle), math.cos(angle), 0, 0],
                  [0, 0, 1, 0],
                  [0, 0, 0, 1]]
    rotation4d_xz = [[math.cos(angle), 0, -math.sin(angle), 0],
                     [0, 1, 0, 0],
                     [math.sin(angle), 0, math.cos(angle), 0],
                     [0, 0, 0, 1]]
    rotation4d_xw = [[math.cos(angle), 0, 0, -math.sin(angle)],
                     [0, 1, 0, 0],
                     [0, 0, 1, 0],
                     [math.sin(angle), 0, 0, math.cos(angle)]]
    rotation4d_yz = [[1, 0, 0, 0],
                     [0, math.cos(angle), -math.sin(angle), 0],
                     [0, math.sin(angle), math.cos(angle), 0],
                     [0, 0, 0, 1]]
    rotation4d_yw = [[1, 0, 0, 0],
                     [0, math.cos(angle), 0, -math.sin(angle)],
                     [0, 0, 1, 0],
                     [0, math.sin(angle), 0, math.cos(angle)]]
    rotation4d_zw = [[1, 0, 0, 0],
                     [0, 1, 0, 0],
                     [0, 0, math.cos(angle), -math.sin(angle)],
                     [0, 0, math.sin(angle), math.cos(angle)]]
 
    for point in points: 
 
        rotated_3d = matrix_multiplication(rotation4d_xy, point)
        rotated_3d = matrix_multiplication(rotation4d_zw, rotated_3d)
 
        distance = 5
        w = 1/(distance - rotated_3d[3][0])
        projection_matrix4 = [
                            [w, 0, 0, 0],
                            [0, w, 0, 0],
                            [0, 0, w, 0],]
 
        projected_3d = matrix_multiplication(projection_matrix4, rotated_3d)
        rotated_2d = matrix_multiplication(tesseract_rotation, projected_3d)
 
        z = 1/(distance - (rotated_2d[2][0] + rotated_3d[3][0]))
        projection_matrix = [[z, 0, 0],
                             [0, z, 0]]
 
        rotated_2d = matrix_multiplication(rotation_x, projected_3d)
        projected_2d = matrix_multiplication(projection_matrix, rotated_2d)
 
        x = int(projected_2d[0][0] * scale) + cube_position[0]
        y = int(projected_2d[1][0] * scale) + cube_position[1]
 
        projected_points[index] = [x, y, z, w]
        corner_display(x, y, z, w)
 
        index += 1
 
    for m in range(4):
        connect_point(m, (m+1)%4, projected_points, 8)
        connect_point(m+4, (m+1)%4 + 4, projected_points, 8)
        connect_point(m, m+4, projected_points, 8)
 
    for m in range(4):
        connect_point(m, (m+1)%4, projected_points, 0)
        connect_point(m+4, (m+1)%4 + 4, projected_points, 0)
        connect_point(m, m+4, projected_points, 0)
 
    for m in range(8):
        connect_point(m, m+8, projected_points, 0)
 
    angle +=speed
    pygame.display.update()
 
pygame.quit()