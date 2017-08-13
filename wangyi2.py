# 输入长度为n的整数a_1, a_2,..., a_n，第i次将a_1到a_i逆序。a_i到a_n不变。
# 输出逆序n次逆序后的结果
#如，输入4, 1 2 3 4.
# 第一次逆序为 1 2 3 4,
# 第二次逆序为 2 1 3 4,
...
# 第四次逆序为4 2 1 3.,则输出4 2 1 3.

import sys


len=raw_input()
len = int(len)
c = map(int, sys.stdin.readline().split())
i=0


i=1
while i<=len:
    a = c[:i]
    b = c[i:]
    a.reverse()
    c = a+b
    i += 1

s = ''
for it in c:
    s += str(it)
    s += ' '
print s[:-1]

# input:
# 4
# 1 2 3 4
# output:
# 4 2 1 3
