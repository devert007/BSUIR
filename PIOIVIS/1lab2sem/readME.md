# Лабораторная работа №1 

## Задача:
Реализовать декартово дерево("Treap") как динамическую структуру данных. Вставка. Поиск. Удаление. Построение дерева из массива значений. Объединение двух деревьев. Пересечение двух деревьев.
## Цель:
Исследовать свойства структур данных и разработать
библиотеку алгоритмов обработки структур данных.

## Список ключевых понятий:

`Декартово дерево`- это структура данных, объединяющая в себе бинарное дерево поиска и бинарную кучу (отсюда и второе её название: treap (tree+heap) и `дерамида`(дерево+пирамида).

Более строго, это структура данных, которая хранит пары (X,Y) в виде бинарного дерева таким образом, что она является бинарным деревом поиска по x и бинарной пирамидой по y. Предполагая, что все X и все Y являются различными, получаем, что если некоторый элемент дерева содержит (X0,Y0), то у всех элементов в левом поддереве X < X0, у всех элементов в правом поддереве X > X0, а также и в левом, и в правом поддереве имеем: Y < Y0.
Дерамиды были предложены Сиделем (Siedel) и Арагоном (Aragon) в 1996 г.

**Преимущества такой организации данных**
В том применении, которое мы рассматриваем (мы будем рассматривать дерамиды, поскольку декартово дерево - это фактически более общая структура данных), X'ы являются ключами (и одновременно значениями, хранящимися в структуре данных), а Y'и - называются **приоритетами**. Если бы приоритетов не было, то было бы обычное бинарное дерево поиска по X, и заданному набору X'ов могло бы соответствовать много деревьев, некоторые из которых являются вырожденными (например, в виде цепочки), а потому чрезвычайно медленными (основные операции выполнялись бы за O (N)).

В то же время, **приоритеты** позволяют **однозначно** указать дерево, которое будет построено (разумеется, не зависящее от порядка добавления элементов) (это доказывается соответствующей теоремой). Теперь очевидно, что если **выбирать приоритеты случайно**, то этим мы добьёмся построения **невырожденных** деревьев в среднем случае, что обеспечит асимптотику O (log N) в среднем. Отсюда и понятно ещё одно название этой структуры данных - **рандомизированное бинарное дерево поиска**

**СВОЙСТВА:**
1. Для каждого узла все ключи в левом поддереве меньше ключа узла,а все ключи в правом поддереве больше ключа узла.
2. Для каждого узла приоритет в узле больше приоритетов его потомков.


В данном примере из массива ключей {3,2,1,5,4,7} и случайного приоритета каждого ключа получим дерамиду:
![[Pasted image 20240127190720.png]]

## Алгоритм 

**Основные операции `Дерамиды`:**
- *merge*- функция объединения деревьев
- *split* - функция "разрезания" дерева
- *insert* - функция вставки нового узла
- *remove* - функция удаления узла
- *search* - функция поиска узла по узлу(возвращается адрес в памяти)
- *intersection* - функция пересечения двух деревьев

Алгоритм создания декартового дерева состоит в том что, зная ключ, создается уникальных приоритет "этого" ключа.Поэтому наше декартовое дерево единственно в своем роде.


### Функция объединения:
Находим узел с максимальным приоритетом в первом дереве.
Удаляем найденный узел из первого дерева.
Вставляем найденный узел во второе дерево.

Функция объединения двух деревьев сводится к рекурсивной, так как за счет приоритета каждый ключ занимает свою уникальную позицию.

```c++

Node *merge(Node *left, Node *right)
{
  if (left == nullptr)
    return right;
  if (right == nullptr)
    return left;

  if (left->priority > right->priority)
  {
    left->right = merge(left->right, right);
    return left;
  }
  else
  {
    right->left = merge(left, right->left);
    return right;
  }
}

```

### Функция пересечения 
Для каждого узла в первом дереве:
       если ключ узла присутствует во втором дереве, то добавляем его в результирующее дерево.

```c++
Node *intersection(Node *left, Node *right)
{
  if (left == nullptr || right == nullptr)
    return nullptr;

  if (left->key == right->key)
  {
    Node *newtree = new Node(left->key);
    insert(newtree, left->key);
    newtree->left = intersection(left->left, right->left);
    newtree->right = intersection(left->right, right->right);
    return newtree;
  }
  else
  {
    if (left->key < right->key)

      return intersection(left->right, right);

    else

        if (left->key > right->key)

      return intersection(left, right->right);
  }
}
```

### Функция "разрезания" по ключу
Идем по всему дереву и сравниваем ключ каждого узла с параметрически заданным ключом:
       если меньше то
         рекурсивно вызываем функцию с аргументoм на правый узел 
иначе  
    на левый узел
```c++
void split(Node *root, int key, Node *&left, Node *&right)
{
  if (root == nullptr)
  {
    left = nullptr;
    right = nullptr;
  }
  else if (root->key <= key)
  {
    split(root->right, key, root->right, right);
    left = root;
  }
  else
  {
    split(root->left, key, left, root->left);
    right = root;
  }
}
```

### Функция вставки элемента
Создаем новый узел
разрезаем дерево на левую(меньшую) и правую(большую) часть
объединяем новый узел и левую часть получаем новую левую часть
снова объединяем новую левую часть и правую часть
```c++
void insert(Node *&root, int key)
{
  Node *newNode = new Node(key);
  Node *left;
  Node *right;
  split(root, key, left, right);
  root = merge(merge(left, newNode), right);
}
```

### Функция удаления 
Идем по дереву и сравниваем ключи узла с параметрически заданным ключом:
        если находим:
             то объединяем следующие правые(большие) и левые(меньшие) узлы и удаляем узел 
         иначе
            идем дальше по дереву вызывая функция удаление рекурсивно
```c++
void remove(Node *&root, int key)
{
  if (root == nullptr)
    return;

  if (root->key == key)
  {
    Node *temp = root;
    root = merge(root->left, root->right);
    delete temp;
  }
  else if (key < root->key)
  {
    remove(root->left, key);
  }
  else
  {
    remove(root->right, key);
  }
}
```

## Пример выполнения:
Возьмем нашу дерамиду из примера в ключевых понятиях:
Ключи: {1,2,3,4,5,7}
Так как выдачу случайных приоритетов контролирует программа то изначально мы не можем предположить какие приоритеты будут.

В результате получаем такое дерево:
![[Pasted image 20240127193023.png]]
Также выведем результат поиска по ключу и операцию удаления ключа 7


При задании двух деревьев с ключами {3, 2, 5} и {4, 3, 5} получим результат пересечения и объединения 
![[Pasted image 20240127193405.png]]


К примеру еще один массив ключей{5 2 8 13 34 73 91 32 44 56 74 7388 292}
будем искать по ключу число 7388 и его же удалим.Вывод программы:
![[Pasted image 20240127195141.png]]
Все работает как следует.

## Вывод
Реализовал структуру данных декартово  дерево (дерамида).

## Источники
[youtubchik](https://youtu.be/68mMGJl5F8s?si=EASqeh28jxrc3E0S)
[algoritmichka](https://algorithmica.org/ru/treap)