#pragma once

#ifndef set_h
#define set_h 

#include <set>
#include <vector>
#include <iostream>
#include <fstream>

    struct Sets {
    public:
        std::set<int>set;
        void insert(int element);
        void printSet(Sets a) {
            {

                for (const auto& el : a.set) {
                    std::cout << el << ' ';
                }
            }
        }
        
        std::vector<Sets>create() {
            std::ifstream file("file.txt");
            int count;
            file >> count;
          std::  vector<Sets>all;
            all.resize(count);
            for (int i = 0; i < count; i++) {
            //   std:: cout << "enter a size of your " << i << " set\n";
                int size;
               file >> size;
                Sets a;
               // std::cout << "enter elements: \n";
                for (int i = 0; i < size; i++) {

                    int el;
                 file >> el;
                    a.set.insert(el);
                }
                all.push_back(a);
            }   
            return all;
        }
        std::set<int>getTheIntersection() {
            std::ifstream file("file.txt");
            int count;
            file >> count;
            std::vector<Sets>all;
            all.resize(count);
            for (int i = 0; i < count; i++) {
                //   std:: cout << "enter a size of your " << i << " set\n";
                int size;
                file >> size;
                Sets a;
                // std::cout << "enter elements: \n";
                for (int i = 0; i < size; i++) {

                    int el;
                    file >> el;
                    a.set.insert(el);
                }
                all.push_back(a);
            }
            std::set<int>result;
            while (!file.eof()) {
                int i;
                file >> i;
                std::cout << i;
                result.insert(i);
            }
            return result;
        }

        std::set<int> intersection(std::vector<Sets>all) {
            std::set<int> result;
            result.insert(all[all.size() / 2].set.begin(), all[all.size() / 2].set.end());
            for (int i = all.size() / 2 + 1; i < all.size(); ++i) {
                std::set<int> temp;
                for (int num : all[i].set) {
                    if (result.count(num) > 0) {
                        temp.insert(num);
                    }
                }
                result = temp;
            }

            std::cout << "Intersection of all sets:" << '\n';
            for (int num : result) {
                std::cout << num << " ";
            }
            std::cout << '\n';
            return result;
            
        }


        
    };
    
#endif