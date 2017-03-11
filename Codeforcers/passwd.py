#!/usr/bin/python

n, k = map(int, raw_input().split(' '))
s='a'
for i in range(1,k):
        s=s+chr(ord(s[i-1])+1)
j=0
for i in range(k,n):
    if s[i-1]==s[k-1]:
        s+='a'
        j=0
    else:
        s+=s[j]
    j+=1
print s
