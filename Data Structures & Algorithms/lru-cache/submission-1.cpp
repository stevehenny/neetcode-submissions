class Node{
public:
    int node_key;
    int node_val;
    Node* prev;
    Node* next;

    Node(int key, int value){
        node_key = key;
        node_val = value;
        prev = nullptr;
        next = nullptr;
    }
};


class LRUCache {
private:
    std::unordered_map<int, Node*> kvMap;
    Node* front;
    Node* back;
    int _capacity;
    int _size;
 void move_to_front(Node* node) {
        if (node == front) return;

        // Unlink node
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        // If node was back, update back
        if (node == back)
            back = node->next;

        // Insert at front
        node->next = nullptr;
        node->prev = front;
        front->next = node;
        front = node;
    }
   void insert_front(Node* node) {
        if (!front) {
            // First node
            front = back = node;
            return;
        }
        node->prev = front;
        node->next = nullptr;
        front->next = node;
        front = node;
    }

    void evict_if_needed() {
        if (_size < _capacity) return;

        // Remove LRU (back)
        Node* victim = back;

        if (back->next) {
            back = back->next;
            back->prev = nullptr;
        } else {
            // Only one node existed
            front = nullptr;
            back = nullptr;
        }

        kvMap.erase(victim->node_key);
        delete victim;
        _size--;
    }

public:
    LRUCache(int capacity) : front(nullptr), back(nullptr), _capacity(capacity), _size(0) {}

    int get(int key) {
        if (!kvMap.count(key)) return -1;
        Node* node = kvMap[key];
        move_to_front(node);
        return node->node_val;
    }

    void put(int key, int value) {
        if (kvMap.count(key)) {
            // Update value + reorder
            Node* node = kvMap[key];
            node->node_val = value;
            move_to_front(node);
            return;
        }

        // Evict if full
        evict_if_needed();

        // Insert new
        Node* node = new Node(key, value);
        insert_front(node);
        kvMap[key] = node;
        _size++;
    }
};