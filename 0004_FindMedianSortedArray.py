#coding=utf-8
#给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
#
#请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
#
#你可以假设 nums1 和 nums2 不同时为空。
#
#示例 1:
#
#nums1 = [1, 3]
#nums2 = [2]
#
#中位数是 2.0
#示例 2:
#
#nums1 = [1, 2]
#nums2 = [3, 4]
#
#中位数是 (2 + 3)/2 = 2.5

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        count1 = len(nums1)
        count2 = len(nums2)
        odd_flag = 0
        if count1+count2 % 2 == 1:
            odd_flag = 1


        nums1_check_pos = -1
        nums2_check_pos = -1
        set_len = (count1+count2) // 2



        half_half_len = (count1+count2) // 4
        nums1_pos = 0
        nums2_pos = 0
        if count1 < half_half_len:
            nums1_pos = count1 - 1
            nums2_pos = half_half_len*2 - count1 - 1
        elif count2 < half_half_len:
            nums1_pos = half_half_len*2 - count2 - 1
            nums2_pos = count2 - 1
        else:
            nums1_pos = half_half_len - 1
            nums2_pos = half_half_len - 1
        
        if nums1[nums1_pos] > nums2[nums2_pos]:
        else:

        nums1_check_pos, nums2_check_pos = findPos(nums1, nums2, nums1_check_pos, nums2_check_pos, set_len)

    def findPos(self, nums1, nums2, check_pos1, check_pos2, need_len, set_len):
        if check_pos1 + check_pos2 + 2 == set_len:
            return check_pos1 , check_pos2
        else:


if __name__ == '__main__':
    print('Hello')
