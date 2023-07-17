class Node {
    public:
    int key, val;
    Node* next;
    Node* prev;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map <int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* x) {
        Node* prevNode = x->prev;
        Node* nextNode = x->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node* x) {
        Node* temp = head->next;
        head->next = x;
        x->next = temp;
        temp->prev = x;
        x->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* req = mp[key];
            mp.erase(key);
            deleteNode(req);
            addNode(req);
            mp[key] = head->next;

            return req->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* req = mp[key];
            mp.erase(key);
            deleteNode(req);
        }

        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */