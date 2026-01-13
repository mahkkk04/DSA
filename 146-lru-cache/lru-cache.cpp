class LRUCache {
    int cap;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (!mp.count(key)) return -1;
        dll.splice(dll.begin(), dll, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            dll.splice(dll.begin(), dll, mp[key]);
            mp[key]->second = value;
            return;
        }
        if (dll.size() == cap) {
            mp.erase(dll.back().first);
            dll.pop_back();
        }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
