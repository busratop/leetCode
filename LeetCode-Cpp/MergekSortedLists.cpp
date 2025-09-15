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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap: küçük değeri en önde tutar
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Her listenin ilk elemanını heap'e ekle
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        // Dummy head ile yeni listeyi oluştur
        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;

    }
};
