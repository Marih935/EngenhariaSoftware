sinal = 1
S = 0
print('S= ', end = '')
for i in range(1,51):
    if sinal == 1 or sinal == 2:
        S = S - i
        sinal = sinal + 1
        print('-', i, end = '')
    elif sinal == 3:
        S = S + i
        sinal = sinal + 1
        print('+', i, end = '')
    else:
        S = S + i
        sinal = 1
        print('+', i, end = '')
print('\n\nS -', S)