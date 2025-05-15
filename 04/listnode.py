# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
#         res = []
#         n1 = [l1.val]
#         n2 = [l2.val]

#         next_n = l1.next
#         while next_n is not None:
#             n1.append(next_n.val)
#             next_n = next_n.next

#         next_n = l2.next
#         while next_n is not None:
#             n2.append(next_n.val)
#             next_n = next_n.next

#         diff = len(n1) - len(n2)
#         if diff > 0:
#             for i in range(abs(diff)):
#                 n1.append(0)
#         else:
#             for i in range(abs(diff)):
#                 n2.append(0)

#         for n, i in enumerate(n1):
#             res.append(i+n2[n])

#         for n, i in enumerate(res):
#             if i >= 10:
#                 if n+1 < len(res)-1:
#                     res.append(i//10)
#                 else:
#                     res[n+1] += i//10
#                 res[n] -= 10

#         output = [ListNode for _ in range(len(res))]
#         for n, LN in enumerate(output):
#             LN.val = res[n]
#             if n < len(output)-1:
#                 LN.next = output[n+1]
#         return ListNode(output[0].val, output[0].next)

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def getNexts(Node):
    if Node.next is None:
        list_emp = [Node]
        print("returning none")
        return list_emp
    else:
        retList = getNexts(Node.next)
        print(retList)
        retList.insert(0, Node)
        return retList

for obj in getNexts(ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))):
    print(obj.val)