#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> mpp;

public:
    LRUCache(int cap1) {
        cap = cap1;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        auto node = mpp[key];
        int val = node->second;

      
        cacheList.erase(node);
        cacheList.push_front({key, val});
        mpp[key] = cacheList.begin();

        return val;
    }

    void put(int key, int val) {
        
        if (mpp.find(key) != mpp.end()) {
            cacheList.erase(mpp[key]);
        }
       
        else if (cacheList.size() == cap) {
            auto last = cacheList.back();
            mpp.erase(last.first);
            cacheList.pop_back();
        }

        
        cacheList.push_front({key, val});
        mpp[key] = cacheList.begin();
    }
};

int main() {
    int cap;
    cout << "Enter the cache capacity you want: ";
    cin >> cap;

    LRUCache cache(cap);

    int n;
    cout << "Enter total number of operations you want to do: ";
    cin >> n;

    while (n--) {
        cout <<" enter the operation type : "<<endl;
        string op;
        cin >> op;

        if (op == "put") {
            int key, val;
            cout<< "enter key and value "<<endl;
            cin >> key >> val;
            cache.put(key, val);
        } 
        else if (op == "get") {
            int key;
            cout<<"  enter the key u want to get "<<endl;
            cin >> key;
            cout << cache.get(key) << endl;
        }
    }

    return 0;
}