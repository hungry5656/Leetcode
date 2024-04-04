class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        Roman_List = {'I':1,'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M': 1000}
        sum_n = 0
        ls = []
        current_c = 0
        current_l = s[0]
        
        if len(s) == 1:
            return Roman_List[s]
        
        for i in range(len(s) - 1):
            if s[i] == s[i+1]:
                current_c += 1
            else:
                current_c += 1
                ls.append(str(current_c)+current_l)
                current_c = 0
                current_l = s[i+1]

        if s[-1] == s[-2]:
            current_c += 1
            ls.append(str(current_c)+current_l)
        else:
            current_c = 1
            ls.append(str(current_c)+current_l)
        
        for j in range(len(ls) - 1):
            if Roman_List[ls[j][1]] < Roman_List[ls[j+1][1]]:
                sum_n = sum_n - int(ls[j][0])*Roman_List[ls[j][1]]
            else:
                sum_n = sum_n + int(ls[j][0])*Roman_List[ls[j][1]]
        
        sum_n = sum_n + int(ls[len(ls) - 1][0])*Roman_List[ls[len(ls) - 1][1]]
        
        return sum_n
        