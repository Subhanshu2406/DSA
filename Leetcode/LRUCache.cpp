class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int,Node*> map;
    int size;
    int capacity;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
        right = new Node(0,0);
        left = new Node(0,0);
        right -> prev = left;
        left -> next = right;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            Node* tail = map[key];
            Node* before = tail -> prev;
            tail -> next -> prev = before;
            before -> next = tail -> next;
            Node* end = right -> prev;
            tail -> prev = end;
            end -> next = tail;
            right -> prev = tail;
            tail -> next = right;
            return map[key] -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()){
            Node* tail = map[key];
            Node* before = tail -> prev;
            tail -> next -> prev = before;
            before -> next = tail -> next;
            Node* end = right -> prev;
            tail -> prev = end;
            end -> next = tail;
            right -> prev = tail;
            tail -> next = right;
            tail -> val = value;
        }

        else{
            map[key] = new Node(key,value);
            Node* tail = map[key];
            Node* end = right -> prev;
            tail -> prev = end;
            end -> next = tail;
            right -> prev = tail;
            tail -> next = right;
            size++;
        }

        if (size > capacity) {
            Node* lru = left->next;         // first real node
            int headKey = lru->key;

            left->next = lru->next;
            lru->next->prev = left;

            map.erase(headKey);
            delete lru;
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */