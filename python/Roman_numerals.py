# Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
#
# Symbol       Value
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000
# For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
#
# Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
#
# I can be placed before V (5) and X (10) to make 4 and 9.
# X can be placed before L (50) and C (100) to make 40 and 90.
# C can be placed before D (500) and M (1000) to make 400 and 900.
# Given a roman numeral, convert it to an integer.
#


class Solution_original:
    def romanToInt(self, s: str) -> int:
        answer = 0
        next_char = 'Q'
        i = 0
        while (i < len(s)):
            if (i+1 == len(s)):
                next_char = 'Q'
            else:
                next_char = s[i + 1]

            if (s[i] == 'I'):
                if (next_char == 'V'):
                    answer += 4
                    i += 2
                elif (next_char == 'X'):
                    answer += 9
                    i += 2
                else:
                    answer += 1
                    i += 1
            elif (s[i] == 'V'):
                answer += 5
                i += 1
            elif (s[i] == 'X'):
                if (next_char == 'C'):
                    answer += 90
                    i += 2
                elif (next_char == 'L'):
                    answer += 40
                    i += 2
                else:
                    answer += 10
                    i += 1
            elif (s[i] == 'L'):
                answer += 50
                i += 1
            elif (s[i] == 'C'):
                if (next_char == 'D'):
                    answer += 400
                    i += 2
                elif (next_char == 'M'):
                    answer += 900
                    i += 2
                else:
                    answer += 100
                    i += 1
            elif (s[i] == 'D'):
                answer += 500
                i += 1
            elif (s[i] == 'M'):
                answer += 1000
                i += 1
            
        return answer


class Solution:
    def romanToInt(self, s: str) -> int:
        romans = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total, prev = 0, 0
        for c in reversed(s):
            if romans[c] < prev:
                total -= romans[c]
            else:
                total += romans[c]
            prev = romans[c]
        return total


# roman = str("MCMXCIV")
roman = str("DCXXI")  # 621
s = Solution()
int = s.romanToInt(roman)
print(int)
