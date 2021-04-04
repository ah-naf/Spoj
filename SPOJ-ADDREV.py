t = int(input())
for i in range (0,t):
    n,m = map(str, input().split())
    n=n[::-1]
    m=m[::-1]
    sum=int(n)+int(m)
    sum=str(sum)
    sum=sum[::-1]
    print(int(sum), '\n')
