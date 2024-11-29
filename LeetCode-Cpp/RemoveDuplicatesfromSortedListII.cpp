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
    ListNode* deleteDuplicates(ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *current = head;

    while (current) {
        // Aynı değerdeki düğümleri bul
        if (current->next && current->val == current->next->val) {
            while (current->next && current->val == current->next->val) {
                current = current->next;
            }
            // Önceki düğümün next'ini, tekrar eden son düğümden sonraki düğüme bağla
            prev->next = current->next;
        } else {
            // Tekrar eden düğüm yoksa, prev'i ilerlet
            prev = prev->next;
        }
        // Current'i ilerlet
        current = current->next;
    }

    return dummy.next;

    }
};
