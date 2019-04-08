class Solution:
	def generate(self, numRows: int) -> List[List[int]]:
		if numRows <= 0:
			return []
		elif numRows == 1:
			return [[1]]
		elif numRows == 2:
			return [[1], [1, 1]]
		else:
			res = [[1], [1, 1]]
			for i in range(3, numRows+1):
				pre_level_len = i - 1
				current_level = [1]
				for j in range(1, pre_level_len):
					current_level.append(res[-1][j-1]+res[-1][j])
				current_level.append(1)

#利用对称性效果不佳
#			current_level = [1, 1]
#			if pre_level_len % 2 == 0:
#				for j in range(1, pre_level_len/2):
#					current_level.insert(j, res[-1][j-1]+res[-1][j])
#					current_level.insert(j, res[-1][j-1]+res[-1][j])
#				j = pre_level_len/2
#				current_level.insert(j, res[-1][j-1]+res[-1][j])
#			else:
#				for j in range(1, pre_level_len/2+1):
#					current_level.insert(j, res[-1][j-1]+res[-1][j])
#					current_level.insert(j, res[-1][j-1]+res[-1][j])

				res.append(current_level)
			return res

if __name__ == '__main__':
	s = Solution()
	print s.generate(5)
