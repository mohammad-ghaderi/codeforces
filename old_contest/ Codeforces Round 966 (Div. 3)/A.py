
def solve():
    s = input()
    if len(s) < 3: return False
    if s[:2] != "10": 
        return False

    exp = s[2:]
    fnd = False

    if exp[0] == '0': return False
    if len(exp) == 1 and exp[0] == '1': return False
    return True
    


for _ in range(int(input())):
    if solve(): print("YES")
    else: print("NO")