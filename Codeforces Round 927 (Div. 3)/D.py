

for  _ in range(int(input())):
    n = int(input())
    trump = input()
    other = []
    cards = list(input().split())
    
    first = {'C':[], 'D':[], 'H':[], 'S':[], other: []}
    second = {'C':[], 'D':[], 'H':[], 'S':[], other: []}


    for c in ['C', 'D', 'H', 'S']:
        if c == trump: continue
        first[c].sort()
        second[c].sort()
        