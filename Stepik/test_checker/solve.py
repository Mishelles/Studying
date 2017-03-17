dataset=str(input())
solution=""
line_count=1
tags_list=[]
line=1
flag=0
tag=""
stack=[]
for i in range (len(dataset)):
    pair=[]
    if dataset[i]=='\n':
        line_count+=1
    if (flag==0) and (dataset[i])=='<':
        flag=1
    elif (flag==1) and (dataset[i]!='>'):
        tag+=dataset[i]

    else:
        flag=0
        if (tag!="") and (tag!="br") and (tag!="hr"):
            pair.append(tag)
            pair.append(line_count)
            tags_list.append(pair)
        tag=""
for x in range (len(tags_list)):
    if (tags_list[x][0][0]!='/'):
        stack.append(tags_list[x])
    else:
        if stack[len(stack)-1][0]==tags_list[x][0][1:]:
            stack.pop()
        else:
            line=stack[len(stack)-1][1]
            break
solution = "correct" if len(stack)==0 else "wrong {}".format(line)
print (solution)
