for _ in range(int(input())):
    n = int(input())
    s = input()
    ans1 = s.count("mapie") 
    ans2 = s.count("map")
    ans3 = s.count("pie")
    ans2 -= ans1
    ans3 -= ans1
    print(ans1 + ans2 + ans3)
