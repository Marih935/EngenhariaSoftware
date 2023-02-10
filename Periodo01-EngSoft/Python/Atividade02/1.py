import random
a = random.randint (1,20)
print('Jesse Quick:', a * 300000, 'km/s')

b = random.randint (1,20)
print('Barry Allen:', b * 300000, 'km/s')

c = random.randint (1,20)
print('Wally West:', c * 300000, 'km/s')

d = random.randint (1,20)
print('Dr. Wells (Flash Reverso):', d * 300000, 'km/s')

e = random.randint (1,20)
print('Jay Garrick:', e * 300000, 'km/s')

f = random.randint (1,20)
print('Max Mercury:', f * 300000, 'km/s')

if (a > b) and (a > c) and (a > d) and (a > e) and (a > f):
   print('Jesse Quick ganhou a corrida')

if (b > a) and (b > c) and (b > d) and (b > e) and (b > f):
   print('Barry Allen ganhou a corrida')

if (c > a) and (c > b) and (c > d) and (c > e) and (c > f):
   print('Wally West ganhou a corrida')

if (d > a) and (d > b) and (d > c) and (d > e) and (d > f):
   print('Dr. Wells (Flash Reverso) ganhou a corrida')

if (e > a) and (e > b) and (e > c) and (e > d) and (e > f):
   print('Jay Garrick ganhou a corrida')

if (f > a) and (f > b) and (f > c) and (f > d) and (f > e):
   print('Max Mercury ganhou a corrida')