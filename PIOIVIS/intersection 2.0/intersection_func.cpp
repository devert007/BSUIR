#include "library.h"
#include <iostream>
#include <set>
#include <vector>
using namespace std;



  /*  set<int> intersection(vector<Sets>all) {

        set<int> result;
        result.insert(all[all.size() / 2].set.begin(), all[all.size() / 2].set.end());
        for (int i = all.size() / 2 + 1; i < all.size(); ++i) {
            set<int> temp;
            for (int num : all[i].set) {
                if (result.count(num) > 0) {
                    temp.insert(num);
                }
            }
            result = temp;
        }

        cout << "Intersection of all sets:" << endl;
        for (int num : result) {
            cout << num << " ";
        }
        return result;
        cout << endl;
    }



    */