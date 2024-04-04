class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x2 = str(x)
        if x2 == x2[::-1]:
            return True
        else:
            return False
        