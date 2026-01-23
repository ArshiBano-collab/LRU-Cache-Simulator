#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
    int capacity;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
    
       if (mp.find(key) == mp.end()) {
           return -1;
       }
       auto it = mp[key];
       int value = it->second;
       dll.erase(it);
       dll.push_front({key, value});
       mp[key] = dll.begin();
       return value;
    }

    void put(int key, int value) {

          if (mp.find(key) != mp.end()) {
        
                 dll.erase(mp[key]);
          }
          else if (dll.size() == capacity) {
        
                 auto last = dll.back();
                 mp.erase(last.first);
                 dll.pop_back();
          }
          dll.push_front({key, value});
          mp[key] = dll.begin();
    }
};


int main() {
    int capacity;
    cout << "Enter cache capacity: ";
    cin >> capacity;

    LRUCache cache(capacity);

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
        else if (op == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        }
    }

    return 0;
}

