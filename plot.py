import pylab
import sys

#datalist = [ ( pylab.loadtxt(filename), label ) for filename,label in [("/home/ankith/learning/ReinforcementLearning/assignments/assignment4/DATA/baseline.txt",'label1')] ]
datalist = [ ( pylab.loadtxt(filename), label ) for filename,label in [(str(sys.argv[1]),'label1')] ]

for data, label in datalist:
    pylab.plot( data[:,1], data[:,0], label=label )

pylab.legend()
pylab.title("Iterations vs Epsiode count")
pylab.xlabel("Iterations")
pylab.ylabel("Epsiode Count")
pylab.show();