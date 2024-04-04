class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if type(x) <> int :
            return 0
        
        if x > 2**31 or x < -2**31:
            return 0
        
        x2 = str(x)
        ls = ''
        
        if x2[0] == '-':
            ls='-'
            for i in range(len(x2) -1, 0, -1):
                ls = ls + x2[i]
        else:
            for i in range(len(x2) -1, -1, -1):
                ls = ls + x2[i]
        
        while ls[0] == 0:
            ls = ls[1:]
        
        if int(ls) > 2**31 or int(ls) < -2**31:
            return 0
        
        return int(ls)