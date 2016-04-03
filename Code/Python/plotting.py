import matplotlib.pyplot as plt
import math
import csv


def get_data(filename='BubbleSort.csv'):
    iterations = []
    n = []
    time = []
    with open(filename, 'rb') as f:
        reader = csv.reader(f)
        for row in reader:
            n.append(int(row[0]))
            iterations.append(int(row[1]))
            time.append(float(row[2]))
        return n,iterations,time

def ave_data(input_file,ave_file):
    n_in,iter_in,time_in = get_data(input_file)
    n_av,iter_ave,time_ave = get_data(ave_file)


n,iterations,time = get_data()
Ave_noFlag = [x*x/2 for x in n]
plt.plot(n,Ave_noFlag,linestyle='--',label="BubbleSort without SFlag")
plt.plot(n,iterations,label="BBS Measured Efficiency")
plt.legend()
plt.ylabel('Computation Steps')
plt.xlabel('Array Size (n)')
plt.savefig("plot.png")
#plt.show()
