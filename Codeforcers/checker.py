#!/usr/bin/python3

def SumNumber(x):
    sum=0
    while x:
        sum+=x%10
        x=int(x/10)
    return sum

def FirstMax (x):
    first_max=0
    count=-1
    while x:
        x=int(x/10)
        count+=1
    first_max=10**count-1
    return first_max

x=int(input())
Max=FirstMax(x)
step=(Max+1)

if (x>=1) and (x<=9):
    print (x)
    exit(0)
while x>=Max:
    Max+=step
Max-=step
if (SumNumber(x)==SumNumber(Max)) and (x>=Max):
    print (x)
else:
    if (SumNumber()==SumNumber(Max)):
        print (Max+90)
    else:
        print (Max)
