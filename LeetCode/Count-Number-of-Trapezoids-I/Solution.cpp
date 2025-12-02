class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        C = Counter(p[1] for p in points)
        X = [v * (v - 1) // 2 for v in C.values()]

        return (sum(X)**2 - sum(x**2 for x in X)) // 2 % 1_000_000_007