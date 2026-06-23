class LRUCache {
   public:
    class Node {
       public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    void addnode(Node* k) {
        Node* check = head->next;
        head->next = k;
        k->prev = head;
        k->next = check;
        check->prev = k;
    }
    void deletenode(Node* k) {
        k->prev->next = k->next;
        k->next->prev = k->prev;
    }
    int cap;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
         cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* copy = mp[key];
        deletenode(copy);
        addnode(copy);
        return copy->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* copy = mp[key];
            copy->val = value;
            deletenode(copy);
            addnode(copy);
        } else {
            if (mp.size() == cap) {
                mp.erase(tail->prev->key);
                deletenode(tail->prev);
               
            }

            Node* copy = new Node(key,value);
            mp[key] = copy;
            addnode(copy);
        }
    }
};
