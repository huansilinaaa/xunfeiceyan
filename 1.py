import numpy as np

n=input()
a=np.array([n,n])
a=input()

print(np.linalg.inv(a))
A = np.matrix(a)
print(A.I)