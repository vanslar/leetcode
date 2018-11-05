#coding=utf-8
#����һ���ַ������ҳ��������ظ��ַ�����Ӵ��ĳ��ȡ�
#
#ʾ�� 1:
#
#����: "abcabcbb"
#���: 3 
#����: ���ظ��ַ�����Ӵ��� "abc"���䳤��Ϊ 3��
#ʾ�� 2:
#
#����: "bbbbb"
#���: 1
#����: ���ظ��ַ�����Ӵ��� "b"���䳤��Ϊ 1��
#ʾ�� 3:
#
#����: "pwwkew"
#���: 3
#����: ���ظ��ַ�����Ӵ��� "wke"���䳤��Ϊ 3��
#     ��ע�⣬�𰸱�����һ���Ӵ���"pwke" ��һ�������� �������Ӵ���

## Final Tips:
## �Ӵ��Ĳ��ҿ�����hashset������
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
