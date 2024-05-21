N = int(input())
test = list(range(1, N + 1))

num = 0
for x in test:
    num = num + x
print(num)

#N = int(input())
#test = list(range(1, N + 1))
#num = 0
#for x in test:
#    num = N + x
#print(num)

#The difference is in the iteration. Let 9 be N. The outputs will be 45
#and 18 respectively. In the first program, var num is redefined every
#cycle. In the second, the external num is useless. Num is not redefined.
