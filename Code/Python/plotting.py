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


n,iterations,time_temp = get_data()
time = [x/max(time_temp) for x  in time_temp]
n,ordered,time_ord_temp = get_data('BubbleSortOrdered.csv')
n,rev,time_rev = get_data('BubbleSortReversed.csv')
time_ord = [x/max(time_ord_temp) for x in time_ord_temp]

Ave_noFlag = [(x*x/2)+x/2 for x in n]
nLogn = [x*math.log(x) for x in n]
plt.figure(1)
plt.plot(n,Ave_noFlag,linestyle='--',label="BubbleSort without SFlag")
plt.plot(n,iterations,label="BBS Measured Efficiency")
plt.legend(loc=2)
plt.title('BubbleSort Operation Comparison')
plt.ylabel('Computation Steps')
plt.xlabel('Array Size (n)')
plt.savefig("../../Report/Random.png")

plt.figure(2)
plt.plot(n,nLogn,linestyle='--',label="N log(N)")
plt.plot(n,ordered,label = "BBS ordered array")
plt.legend(loc=2)
plt.title('BubbleSort Operation Comparison')
plt.ylabel('Computation Steps')
plt.xlabel('Array Size (n)')
plt.savefig("../../Report/Ordered.png")


plt.figure(3)
plt.plot(n,rev,label = "BBS Reversed array")
plt.plot(n,Ave_noFlag,'r',linestyle='--',label="Without Flag")
plt.legend(loc=2)
plt.title('BubbleSort Operation Comparison')
plt.ylabel('Computation Steps')
plt.xlabel('Array Size (n)')
plt.savefig("../../Report/Reversed.png")

n_time = [x/float(max(n)) for x in n]
plt.figure(4)
plt.plot(n_time,time,'o',label = "BBS with randomized array")
plt.legend(loc=2)
plt.title('BubbleSort Time Analysis')
plt.ylabel('Time taken (s) / (max s)')
plt.xlabel('Array Size (n) / (max n)')
plt.savefig("../../Report/RandomTime.png")

plt.figure(5)
plt.plot(n_time,time_ord,'o',label = "BBS with ordered array")
plt.legend(loc=2)
plt.title('BubbleSort Time Analysis')
plt.ylabel('Time taken (s)/(max s)')
plt.xlabel('Array Size (n)/ (max n)')
plt.savefig("../../Report/OrderedTime.png")

plt.figure(6)
plt.plot(n_time,time_rev,label = "BBS with reversed array")
plt.legend(loc=2)
plt.title('BubbleSort Time Analysis')
plt.ylabel('Time taken (s)')
plt.xlabel('Array Size (n)')
plt.savefig("../../Report/ReversedTime.png")
plt.show()
