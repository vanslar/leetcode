#coding=utf-8
#给定一个字符串，找出不含有重复字符的最长子串的长度。
#
#示例 1:
#
#输入: "abcabcbb"
#输出: 3 
#解释: 无重复字符的最长子串是 "abc"，其长度为 3。
#示例 2:
#
#输入: "bbbbb"
#输出: 1
#解释: 无重复字符的最长子串是 "b"，其长度为 1。
#示例 3:
#
#输入: "pwwkew"
#输出: 3
#解释: 无重复字符的最长子串是 "wke"，其长度为 3。
#     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。

## Final Tips:
## 子串的查找可以用hashset来加速
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_len = len(s)
        if s_len == 0:
            return 0

        cur_substr_start_pos = 0 
        max_substr_start_pos = 0 
        max_substr_end_pos = 0 
        max_substr_len = 1
        for i in range(1, s_len):
            if s[i] in s[cur_substr_start_pos:i]:
                sub_len = i - cur_substr_start_pos
                if sub_len > max_substr_len:
                    max_substr_start_pos = cur_substr_start_pos
                    max_substr_end_pos = i-1
                    max_substr_len = sub_len

                cur_substr_start_pos = cur_substr_start_pos + s[cur_substr_start_pos:i].find(s[i]) + 1

        sub_len = s_len - cur_substr_start_pos
        if sub_len > max_substr_len:
            max_substr_start_pos = cur_substr_start_pos
            max_substr_end_pos = s_len-1
            max_substr_len = sub_len
        return max_substr_len

if __name__ == '__main__':
    string = "abcabcbb"
    s = Solution()
    print(s.lengthOfLongestSubstring(string))

    string = " "
    print(s.lengthOfLongestSubstring(string))

    string = "au"
    print(s.lengthOfLongestSubstring(string))
