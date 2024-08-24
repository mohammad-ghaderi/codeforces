alfa = "abcdefghijklmnopqrstuvwxyz"

for _ in range(int(input())):
    s = input()
    ans = -1
    for x in alfa:
        word = x+x
        try:
            i = s.index(word)
            ans = i
            break
        except:
            pass
    
    if (ans == -1):
        if s[0] == "a":
            print("b",end='')
        else: print("a",end='')
        print(s)
    else:
        print(s[:ans+1],end='')
        if s[ans] == "a":
            print("b",end='')
        else: print("a",end='')
        print(s[ans+1:])