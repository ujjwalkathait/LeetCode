class Node {
public:
    int key, val, cnt;
    Node *prev;
    Node *next;
    Node(int key, int val) : key(key), val(val), cnt(1), prev(nullptr), next(nullptr) {}
};

class List {
public:
    int size;
    Node *head;
    Node *tail;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node){
        Node *temp = head->next;
        head->next = node;
        temp->prev = node;
        node->next = temp;
        node->prev = head;
        size++;
    }
    void removeNode(Node *node){
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};
class LFUCache {
private:
    map<int, List*> freqList;
    map<int, Node*> keyNode;
    int maxSize;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqList(Node *node){
        // keyNode.erase(node->key);
        freqList[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqList[node->cnt]->size == 0){
            minFreq++;
        }
        List *nextHigherFreqList = new List();
        if(freqList.find(node->cnt + 1) != freqList.end()){
            nextHigherFreqList = freqList[node->cnt+1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqList[node->cnt] = nextHigherFreqList;
        // keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key];
            int val = node->val;
            updateFreqList(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key];
            node->val = value;
            updateFreqList(node);
        }else{
            if(curSize == maxSize){
                List *list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listFreq = new List();
            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */