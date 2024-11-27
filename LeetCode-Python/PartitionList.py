# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        # Yeni bağlı listeler için sahte başlıklar (dummy nodes)
        less_dummy = ListNode(0)
        greater_dummy = ListNode(0)
        
        # İlgili işaretçiler (pointers)
        less = less_dummy
        greater = greater_dummy
        
        # Orijinal listeyi dolaşarak düğümleri ilgili yeni listeye ekleyin
        while head:
            if head.val < x:
                less.next = head
                less = less.next
            else:
                greater.next = head
                greater = greater.next
            head = head.next
        
        # `greater` listesinin sonunu null ile işaretleyin
        greater.next = None
        # `less` listesinin sonunu `greater` listesine bağlayın
        less.next = greater_dummy.next
        
        return less_dummy.next
