num=int(raw_input())
arr1=[]

num1 = num
while num1 != 0:
    arr1.append(num1 % 10)
    num1 /= 10

num2=0
for i in arr1:
    num2 = num2 * 10 + i

print num + num2

# input
# 100
# output:
# 101
