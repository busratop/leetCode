# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Sahte bir baş düğüm oluştur
        dummy = ListNode(0)
        dummy.next = head
        # İki pointer kullanarak ilerle
        prev = dummy  # Önceki düğüm
        current = head  # Şu anki düğüm

        while current:
            # Aynı değerdeki düğümleri bul
            if current.next and current.val == current.next.val:
                while current.next and current.val == current.next.val:
                    current = current.next
                # Önceki düğümün next'ini, tekrar eden son düğümden sonraki düğüme bağla
                prev.next = current.next
            else:
                # Tekrar eden düğüm yoksa, prev'i ilerlet
                prev = prev.next
            # Current'i ilerlet
            current = current.next

        # Sahte baş düğümün next'ini döndür
        return dummy.next
