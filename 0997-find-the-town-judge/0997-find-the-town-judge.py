class Solution:
    def findJudge(self, n: int, trust: list[list[int]]) -> int:
        trust_count = [0]*(n+1)
        trust_by_count = [0]*(n+1)

        for t in trust:
            trust_count[t[0]] += 1
            trust_by_count[t[1]] += 1
        
        for i in range(1, n+1):
            if trust_count[i] == 0 and trust_by_count[i] == n-1:
                return i
        return -1