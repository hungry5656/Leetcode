class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        
        mapping = {"}":"{", ")":"(", "]":"["}
        
        for txt1 in s:
            if txt1 in mapping:
                top_element = stack.pop() if stack else '#'
                if mapping[txt1] != top_element:
                    return False
            else:
                stack.append(txt1)
        return not stack