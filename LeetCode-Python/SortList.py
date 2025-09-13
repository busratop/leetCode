# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Temel durum: boş veya tek elemanlı liste
        if not head or not head.next:
            return head

        # Ortayı bul (slow-fast pointer tekniği)
        mid = self.getMid(head)
        right = mid.next
        mid.next = None  # Listeyi ikiye ayır

        # Her iki yarıyı sıralayıp birleştir
        left = self.sortList(head)
        right = self.sortList(right)

        return self.merge(left, right)

    def getMid(self, head: ListNode) -> ListNode:
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def merge(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        tail = dummy

        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next

        tail.next = l1 if l1 else l2
        return dummy.next
