class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node *tail;
    Node *head;

    void removeFromTail(Node *node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode; 
    }
    void insertToHead(Node *node){
        Node *prevNode = head;
        Node *nextNode = head->next;
        prevNode->next = nextNode->prev = node;
        node->prev = prevNode;
        node->next = nextNode;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node *curr = cache[key];
            removeFromTail(curr);
            insertToHead(curr);
            return curr->val; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node *node = cache[key];
            node->val = value;
            removeFromTail(node);
            insertToHead(node);
            return;
        }
        if(cache.size() == cap){
            Node *lru = tail->prev;
            removeFromTail(lru);
            cache.erase(lru->key);
            delete lru;
        }
        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        insertToHead(newNode);
    }

    ~LRUCache() {
        Node *curr = head;
        while(curr != nullptr){
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */