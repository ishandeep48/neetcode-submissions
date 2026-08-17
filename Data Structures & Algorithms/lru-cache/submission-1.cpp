
struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int num1, int num2) {
        key = num1;
        value = num2;
        next = prev = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int count;
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        head = tail = nullptr;
    }

    int get(int key) {
        if (mp.count(key)) {
            Node* temp = mp[key];
            if (temp == head)
                return temp->value;
            if (temp->prev) {
                temp->prev->next = temp->next;

                if (!temp->next) {
                    tail = temp->prev;
                }
            }
            if (temp->next)
                temp->next->prev = temp->prev;
            
                temp->prev = nullptr;

            temp->next = head;

            head->prev = temp;
            head = temp;
            return head->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* temp = mp[key];
            temp->value = value;
            if (temp == head) {
                return;
            }
            temp->prev->next = temp->next;
            if (!temp->next)
                tail = temp->prev;
            if (temp->next)
                temp->next->prev = temp->prev;
            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }
        if (cap == 0)
            return;
        if (count == cap) {
            if (count == 1) {
                mp.erase(head->key);

                head->key = key;
                head->value = value;

                mp[key] = head;

                return;
            }
            Node* oldTail = tail;

            tail = tail->prev;
            if(tail)tail->next = nullptr;

            mp.erase(oldTail->key);

            oldTail->key = key;
            oldTail->value = value;

            oldTail->prev = nullptr;
            oldTail->next = head;

            head->prev = oldTail;
            head = oldTail;

            mp[key] = oldTail;
            return;
        }
        if (count == 0) {
            Node* temp = new Node(key, value);
            head = tail = temp;
            mp[key] = head;
            count++;
            return;
        }
        Node* temp = new Node(key, value);
        temp->next = head;
        head->prev = temp;
        head = temp;
        count++;
        mp[key] = head;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */