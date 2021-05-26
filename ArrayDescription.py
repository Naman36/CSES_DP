def getWays(arr, n, v, m):
    if n == 1 or v < 0 or v > m:
        return 1
    if arr[n - 1] - arr[n - 2] != 1 and arr[n - 1] != 0:
        return 0
    else:
        if arr[n - 1] != 0:
            return getWays(arr, n - 1, arr[n - 1], m) + 1
        else:
            for i in range(m):
                if abs(arr[n - 2] - i) <= 1:
                    return 1 + getWays(arr, n - 1, i, m)
print(getWays([2, 0, 2], 3, 0, 5))

