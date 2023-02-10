import random
print ('Apostas da megasena:\n')
for i in range(6):
    for i in range(0,5):
        n1 = random.randint(1,60)
        n2 = random.randint(1,60)
        while n1 == n2:
            n2 = random.randint(1,60)
        n3 = random.randint(1,60)
        while n3 == n1 or n3 == n2:
            n3 = random.randint(1,60)
        n4 = random.randint(1,60)
        while n4 == n1 or n4 == n2 or n4 == n3:
            n4 = random.randint(1,60)
        n5 = random.randint(1,60)
        while n5 == n1 or n5 == n2 or n5 == n3 or n5 == n4:
            n5 = random.randint(1,60)
        n6 = random.randint(1,60)
        while n6 == n1 or n6 == n2 or n6 == n3 or n6 == n4 or n6 == n5:
            n6 = random.randint(1,60)

    print(n1, n2, n3, n4, n5, n6)