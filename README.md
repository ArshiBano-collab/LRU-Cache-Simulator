## LRU Cache Simulator

This project is a simple implementation of an LRU (Least Recently Used) Cache in C++ using STL.

## Why this project
I built this project to better understand how LRU caching works internally and how different data structures can be combined to achieve efficient performance.

## Features
- O(1) time complexity for get and put operations
- Implemented using unordered_map and doubly linked list (STL list)
- Automatically removes the least recently used element when cache capacity is exceeded
- Helps understand caching behavior used in real-world systems

## Technologies Used
- C++
- STL (unordered_map, list)
- Object Oriented Programming
- Data Structures & Algorithms

## How to Run
```bash
g++ main.cpp -o lru
./lru


## Explanation:
- Cache capacity is 2
- After accessing key 1, it becomes most recently used
- When key 3 is inserted, key 2 is evicted (least recently used)
