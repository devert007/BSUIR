#include <iostream>
#include <map>
#include <vector>

using namespace std;
template <typename T>
class EdgeIterator
{
private:
  using VectorIterator = typename vector<pair<int, int>>::iterator;
  VectorIterator current;
  VectorIterator end;

public:
  EdgeIterator(MapIterator it, MapIterator end_it) : current(it), end(end_it) {}

  EdgeIterator &operator++()
  {
    if (current != end)
    {
      ++current;
    }
    return *this;
  }

  EdgeIterator &operator--()
  {
    if (current != end)
    {
      --current;
    }
    return *this;
  }
  bool operator==(const EdgeIterator &other) const
  {
    return current == other.current;
  }

  bool operator!=(const EdgeIterator &other) const
  {
    return current != other.current;
  }
};
