class Node{
public: 
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value, Node* next, Node* prev){
        this->key = key;
        this->value  = value;
        this->next = next;
        this->prev = prev;
    }
};

class LRUCache {    
public:
    unordered_map<int, Node*> cache;
    int capacity;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1, NULL, NULL);
        tail = new Node(-1, -1, NULL, NULL);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            // move this node to the start of the queue. 
            Node* n = cache[key];
            removeNode(n); // removes from current position
            addNode(n); // adds to first position
            return n->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()) { // key not found
            Node* n = new Node(key, value, NULL, NULL);
            if(cache.size() >= capacity) {

                Node* fullyDeleteMe = tail->prev;
                cache.erase(fullyDeleteMe->key); // 1. Erase from map
                removeNode(fullyDeleteMe);        // 2. Unhook from list
                delete fullyDeleteMe;  // remove the lastNode
            } 
            addNode(n); // add to the front
            cache[key] = n;
        } else {
            
            Node* n = cache[key];
            

            cache[key]->value = value;
            removeNode(n); // removes from current position
            addNode(n); 
        }
    }


    void removeNode(Node* node) {
        Node* before = node->prev;
        Node* after = node-> next;

        before->next = after;
        after->prev = before;
    }

    void addNode(Node* node){
        Node* first = head->next;

        head->next = node;
        node->prev = head;

        node->next = first;
        first->prev = node;
    }
};
