t = int(input())
for test in range (0,t):
    n = int(input())
    ans = 5
    cnt = 0
    while (n//ans)>=1:
        cnt+=(n//ans)
        ans*=5
    print(cnt)
