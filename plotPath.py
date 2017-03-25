import matplotlib.pyplot as plt
import pylab

import sys
datalist = [ ( pylab.loadtxt(filename), label ) for filename,label in [((str(sys.argv[1])),'label1')] ]


for data, label in datalist:
    
    y1=[(y-6) * -1 for y in data[:,0]];
    #print data[:,1];
    #print y1;
    pylab.plot( data[:,1], y1, label=label )

pylab.title("Path taken by agent ")

plt.grid()
#x1,x2,y1,y2 = plt.axis()
plt.axis((-1,10,-1,7))
plt.show()
