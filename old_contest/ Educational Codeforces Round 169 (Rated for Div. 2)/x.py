from random import randint
sz = 10000

file = open("input.txt", 'w')

try:
    file.write(str(sz)+"\n")
    for _ in range(sz):
        file.write("1 70\n")
        file.write("1 100\n")        
except:
    print("error")

file.close()