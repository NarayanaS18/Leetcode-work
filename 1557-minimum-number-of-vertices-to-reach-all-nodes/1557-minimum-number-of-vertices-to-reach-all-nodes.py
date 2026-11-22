class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: list[list[int]]) -> list[int]:
        indegree = [False]*n

        for i,j in edges:
            indegree[j] = True

        return [i for i in range(n) if not indegree[i]]