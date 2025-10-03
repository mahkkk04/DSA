class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int v): val(v), next(nullptr), prev(nullptr) {}
    };

    Node* head;  // dummy head
    Node* tail;  // dummy tail
    int size;

public:
    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* cur;
        // Decide direction: start from head or tail
        if (index < size / 2) {
            cur = head->next;
            for (int i = 0; i < index; i++) cur = cur->next;
        } else {
            cur = tail->prev;
            for (int i = size - 1; i > index; i--) cur = cur->prev;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node* prev;
        Node* next;
        if (index < size / 2) {
            prev = head;
            for (int i = 0; i < index; i++) prev = prev->next;
            next = prev->next;
        } else {
            next = tail;
            for (int i = size; i > index; i--) next = next->prev;
            prev = next->prev;
        }
        Node* node = new Node(val);
        node->prev = prev;
        node->next = next;
        prev->next = node;
        next->prev = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* cur;
        if (index < size / 2) {
            cur = head->next;
            for (int i = 0; i < index; i++) cur = cur->next;
        } else {
            cur = tail->prev;
            for (int i = size - 1; i > index; i--) cur = cur->prev;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        size--;
    }
};
