import timeit
import os

data = 'x' * 10**9  

start = timeit.default_timer()
with open('file.txt', 'w') as file:
    file.write(data)
end = timeit.default_timer()
print(f"Time for I/O: {end - start} seconds")

os.remove('file.txt')

fac_list = [0] * 1000
def fac(n):
    if n == 0:
        fac_list[n] = 1
        return 0
    if n == 1:
        fac_list[n] = 1
        return 1
    fac_list[n] = n*fac(n-1)
    return fac_list[n]

start = timeit.default_timer()
fac(300)
end = timeit.default_timer()
print(f"Time for CPU: {end - start} seconds")
