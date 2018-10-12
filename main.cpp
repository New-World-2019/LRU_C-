#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v):key(k), value(v){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _size = capacity;
    }

    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end())
            return -1;
        else {
            //把当前访问的节点移到链表头部,并且更新map中该节点的地址
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
            return cacheMap[key]->value;
        }

    }

    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()) {
            if((int)cacheList.size() == _size) {
                //删除链表尾部节点（最少访问的节点）
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            //插入新节点到链表头部,并且更新map中增加该节点
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else {
            //更新节点的值，把当前访问的节点移到链表头部,并且更新map中该节点的地址
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }

    }
private:
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator>cacheMap;
    int _size;
};

int main() {

}
