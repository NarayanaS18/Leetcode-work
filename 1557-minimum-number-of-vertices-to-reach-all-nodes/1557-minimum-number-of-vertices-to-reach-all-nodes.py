class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: list[list[int]]) -> list[int]:
        return list(set(range(n)) - set(j for i,j in edges))