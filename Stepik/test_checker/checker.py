#!/usr/bin/python3
import random
import string

def generate():

    test_cases = []

    #first two hand-made tests for example
    test_cases.append("<html>\n<head>\n<title>HTML Document</title>\n</head>\n<body>\n<p><b>Этот текст будет полужирным,<br>\n<i>а этот — ещё и курсивным</i></b></p>\n</body>\n</html>")
    test_cases.append("<html>\n<head>\n<title>HTML Page</title>\n</head>\n<body>\n<p><b>Страница выглядит правильной,<br><i>но где-то тут мы потеряли закрывающий тег</b></p>\n</body>\n</html>")

    #auto tests
    for x in range (3, 50):
        tags_list=[]
        for i in range (random.randint(2, 30)):
            #generating tags list
            tag="<"
            for j in range (random.randint(1, 10)):
                token = random.choice(string.ascii_uppercase + string.ascii_lowercase)
                tag+=token
            tag+='>'
            tags_list.append(tag)
            case=""

        for i in range (len(tags_list)):
            text=""
            case+=tags_list[i]
            for j in range (random.randint(1, 30)):
                token = random.choice(string.ascii_uppercase + string.ascii_lowercase)
                text+=token
                if (random.randint(0,100)==1):
                    text+="<br>"
            case+=text

        tags_list.reverse()
        for i in range (len(tags_list)):
            for j in range (random.randint(1, 30)):
                token = random.choice(string.ascii_uppercase + string.ascii_lowercase + string.digits)
                text+=token
                if (random.randint(0,40)==1):
                    text+="<hr>"
            case+=text
            if (random.randint(0,1)==1):
                tags_list[i]='</'+tags_list[i][1:]
                case+=tags_list[i]
        test_cases.append(case)

    return test_cases


def solve(dataset):
    string=dataset
    solution="correct"
    tags_list=[]
    flag=0
    tag=""
    stack=[]
    for i in range (len(dataset)):
    	if (flag==0) and (dataset[i])=='<':
    		flag=1
    	elif (flag==1) and (dataset[i]!='>'):
    		tag+=dataset[i]
    		
    	else:
    		flag=0
    		if (tag!="") and (tag!="br") and (tag!="hr"):	
    			tags_list.append(tag)
    		tag=""
    for x in range (len(tags_list)):
	    if (tags_list[x][0]!='/'):
		    stack.append(tags_list[x])
	    else:
		    if stack[len(stack)-1]==tags_list[x][1:]:
			    stack.pop()
    return "wrong" if len(stack) else "correct"				

    
tests=generate()
print (solve(tests[4]))
