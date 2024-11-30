/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
  
        if (!head || !head->next || k == 0) return head;

        // Listenin uzunluğunu hesapla
        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        // Bağlı listenin sonundaki düğümü listenin başına bağla (döngü oluştur)
        current->next = head;

        // Gerçek döndürme adım sayısını hesapla
        k = k % length;
        int stepsToNewHead = length - k;

        // Yeni baş düğüme ulaşmak için gereken adım sayısı kadar ilerle
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewHead - 1; i++) {
            newTail = newTail->next;
        }

        // Yeni baş ve kuyruk düğümleri belirle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
}
};
