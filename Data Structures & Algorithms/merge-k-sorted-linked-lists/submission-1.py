import heapq

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = []
        unique_id = 0

        for head in lists:
            if head is not None:
                heapq.heappush(min_heap, (head.val, unique_id, head))
                unique_id += 1

        dummy = ListNode(0)
        curr = dummy

        while min_heap:
            value, _, smallest = heapq.heappop(min_heap)

            curr.next = smallest
            curr = curr.next

            if smallest.next is not None:
                heapq.heappush(
                    min_heap,
                    (smallest.next.val, unique_id, smallest.next)
                )
                unique_id += 1

        return dummy.next



        

