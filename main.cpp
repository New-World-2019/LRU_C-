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
            //�ѵ�ǰ���ʵĽڵ��Ƶ�����ͷ��,���Ҹ���map�иýڵ�ĵ�ַ
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
            return cacheMap[key]->value;
        }

    }

    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()) {
            if((int)cacheList.size() == _size) {
                //ɾ������β���ڵ㣨���ٷ��ʵĽڵ㣩
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            //�����½ڵ㵽����ͷ��,���Ҹ���map�����Ӹýڵ�
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else {
            //���½ڵ��ֵ���ѵ�ǰ���ʵĽڵ��Ƶ�����ͷ��,���Ҹ���map�иýڵ�ĵ�ַ
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
