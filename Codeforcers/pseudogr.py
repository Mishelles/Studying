#!/usr/bin/python3

sLen=int(input())
s=str(input())
countSpaces=0
for i in range(sLen-1):
    if (s[i]=='[')and(s[i+1]==']'):
        countSpaces+=1
print (countSpaces)
