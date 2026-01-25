#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
    int capacity;
    list<pair<int, int>>cacheList;
    unordered_map<int, list<pair<int, int>>::iterator>mpp;

public:
    LRUCache(int cap) {
           capacity = cap;
    }


    int get(int key) {
    
       if (mpp.find(key) == mpp.end()) {
           return -1;
       }
       auto node = mpp[key];
       int value = node->second;
       cacheList.erase(node);
       cacheList.push_front({key, value});
       mpp[key] = cacheList.begin();
       return value;
    }

    void put(int key, int value) {

          if (mpp.find(key) != mpp.end()) {
        
                 cacheList.erase(mpp[key]);
          }
          else if (cacheList.size() == capacity) {
        
                 auto last = cacheList.back();
                 mpp.erase(last.first);
                 cacheList.pop_back();
          }
          cacheList.push_front({key, value});
          mpp[key] = cacheList.begin();
    }
};


int main() {
    int capacity;
    cout << "Enter cache capacity: ";
    cin >> capacity;

    LRUCache cache(capacity);

    int n;
    cout << "Enter number of operations:";
    cin >> n;

    while (n--) {
        string strs;
        cin >> strs;

        if (strs == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
        else if (strs == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        }
    }

    return 0;
}

