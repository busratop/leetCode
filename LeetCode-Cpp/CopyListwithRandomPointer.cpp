/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (!head) return nullptr;

        // Orijinal düğümler ve kopya düğümler arasındaki haritayı oluştur
        unordered_map<Node*, Node*> map;

        // İlk geçiş: Her düğüm için kopya oluştur ve haritaya ekle
        Node* node = head;
        while (node) {
            map[node] = new Node(node->val);
            node = node->next;
        }

        // İkinci geçiş: next ve random işaretçilerini ayarla
        node = head;
        while (node) {
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
            node = node->next;
        }

        // Kopyalanan listenin başını döndür
        return map[head];
    }
};
