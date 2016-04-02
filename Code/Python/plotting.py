import matplotlib.pyplot as plt
import math
import csv

iterations = []
n = []
time = []
with open('BubbleSort.csv', 'rb') as f:
    reader = csv.reader(f)
    for row in reader:
        n.append(int(row[0]))
        iterations.append(int(row[1]))
        time.append(float(row[2]))
print type(n[0])
Ave_noFlag = [x*x/2 for x in n]
plt.plot(n,Ave_noFlag,n,iterations)
plt.ylabel('Number of iterations')
plt.xlabel('Array Size (n)')
plt.show()
