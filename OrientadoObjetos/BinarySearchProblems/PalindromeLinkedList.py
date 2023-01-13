class LLNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class Solution:
    def solve(self, node):
        if node != None:
            lista =  [node.val]
            sig = node.next
            while sig != None:
                lista.append(sig.val)
                sig = sig.next
            return lista == lista[::-1]
        else:
            return True


