# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head

        # Listenin uzunluğunu hesapla
        current = head
        length = 1
        while current.next:
            current = current.next
            length += 1

        # Bağlı listenin sonundaki düğümü listenin başına bağla (döngü oluştur)
        current.next = head

        # Gerçek döndürme adım sayısını hesapla
        k = k % length
        steps_to_new_head = length - k

        # Yeni baş düğüme ulaşmak için gereken adım sayısı kadar ilerle
        new_tail = head
        for _ in range(steps_to_new_head - 1):
            new_tail = new_tail.next

        # Yeni baş ve kuyruk düğümleri belirle
        new_head = new_tail.next
        new_tail.next = None

        return new_head
