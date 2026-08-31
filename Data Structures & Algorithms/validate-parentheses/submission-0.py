class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == "(" or c == "{" or c == "[":
                stack.append(c)

            else:
                if len(stack) == 0:
                    return False

                top = stack[-1]

                if (
                    top == "(" and c == ")" or
                    top == "{" and c == "}" or
                    top == "[" and c == "]"
                ):
                    stack.pop()
                else:
                    return False

        return len(stack) == 0