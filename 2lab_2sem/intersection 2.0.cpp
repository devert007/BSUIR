#include <iostream>
#include <vector>
#include <fstream>
#include "library.h"
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    Sets a;
    std::vector<Sets>all=a.create();
    cout << "Your result of intersection:\n";
    set<int>result = a.getTheIntersection();
   
    a.intersection(all);
    }