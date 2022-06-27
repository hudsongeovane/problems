import sys
test_cases = int(input())
while test_cases > 0:
    test_cases -= 1
    m, n = map(int, input().split())
    a = []
    max_value = -sys.maxsize -1

    max_i = 0
    max_j = 0
    for i in range(m):
        tmp = [int(item) for item in input().split()]
        a.append(tmp)

    for i in range(m):
        for j in range(n):
            if a[i][j] > max_value:
                max_i = i
                max_j = j
                max_value = a[i][j]

    max_i += 1
    max_j += 1

    area = max_i * max_j
    area = max(area, max_j * (m - max_i + 1))
    area = max(area, (n - max_j + 1) * (m - max_i + 1))
    area = max(area, (n - max_j + 1) * max_i)
    print(area)