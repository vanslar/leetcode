#coding=UTF-8
#���������ǿ���������ʾ�����Ǹ�������λ����������ʽ�洢�����ǵ�ÿ���ڵ�ֻ�洢�������֡���������ӷ���һ���µ�����
#
#����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
#
#ʾ����
#
#���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
#�����7 -> 0 -> 8
#ԭ��342 + 465 = 807

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def showNodes(self):
        node = self
        while node != None:
            print(node.val)
            node = node.next

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        val = (l1.val + l2.val)%10
        res = (l1.val + l2.val) // 10
        result_l = ListNode(val)
        result_node = result_l

        l1_node = l1.next
        l2_node = l2.next
        while l1_node != None:
            if l2_node != None:
                val = l1_node.val + l2_node.val + res
                res = val // 10
                result_node.next = ListNode(val%10)
                l1_node = l1_node.next
                l2_node = l2_node.next
            else:
                val = l1_node.val +  res
                res = val // 10
                result_node.next = ListNode(val%10)
                l1_node = l1_node.next
            result_node = result_node.next
        
        while l2_node != None:
            val = l2_node.val +  res
            res = val // 10
            result_node.next = ListNode(val%10)
            l2_node = l2_node.next

            result_node = result_node.next
        
        if res != 0:
            result_node.next = ListNode(res)

        return result_l

if __name__ == '__main__':
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    s = Solution()
    print(s.addTwoNumbers(l1, l2).showNodes())
    
    l1 = ListNode(5)
    l2 = ListNode(5)
    print(s.addTwoNumbers(l1, l2).showNodes())
