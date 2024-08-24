for _ in range(int(input())):
    n = int(input())
    s = input()
    x = s.count("_(_)")
    s.replace("_(_)","")
    print(x*4+s.count("_)")+s.count("_("))