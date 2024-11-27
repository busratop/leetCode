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
    ListNode* partition(ListNode* head, int x) {

        // Yeni bağlı listeler için sahte başlıklar (dummy nodes)
        ListNode lessDummy(0);
        ListNode greaterDummy(0);
        
        // İlgili işaretçiler (pointers)
        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;
        
        // Orijinal listeyi dolaşarak düğümleri ilgili yeni listeye ekleyin
        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        // `greater` listesinin sonunu null ile işaretleyin
        greater->next = nullptr;
        // `less` listesinin sonunu `greater` listesine bağlayın
        less->next = greaterDummy.next;
        
        return lessDummy.next;
    }
};
