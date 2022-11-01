# 1290. Convert Binary Number in a Linked List to Integer
# 
# Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
# 
# Return the decimal value of the number in the linked list.
# 
# The most significant bit is at the head of the linked list.
# 
# Example 1:
# Input: head = [1,0,1]
# Output: 5
# Explanation: (101) in base 2 = (5) in base 10
# 
# Example 2:
# Input: head = [0]
# Output: 0
# 
# Constraints:
# The Linked List is not empty.
# Number of nodes will not exceed 30.
# Each node's value is either 0 or 1.
# 

# Definition for singly-linked list.
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Iterate through the linked list and create an array of the binary number
# length of the binary number to understand the power of 2 for MSB
# counter int to add up the binary number
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        element = head
        bool = []
        DecimalValue = 0
        while element:  # while(element != None)
            bool.append(element.val)
            element = element.next
        for bit in range(len(bool)):
            DecimalValue += bool[len(bool)-1-bit]*pow(2, bit)
        return DecimalValue

    # leet code find this a faster solution (less run time)
    # Dont think it is better in either space or time complexity
    # int(str,2) method is elegant but also needs to loop through the string
    def alternative_getDecimalValue(self, head: ListNode) -> int:
        element = head
        binary_string = ""
        while element:
            binary_string += str(element.val)
            element = element.next
        return int(binary_string, 2)


# Example 1:
head = [1, 0, 1]
third = ListNode(1)
second = ListNode(0, third)
head = ListNode(1, second)
s = Solution()

assert 5 == s.getDecimalValue(head)
assert 0 == s.getDecimalValue(ListNode(0))










