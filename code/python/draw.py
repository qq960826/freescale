__author__ = 'wzq'
#!/usr/bin/env python

import pylab as pl
import numpy as np

filename1 = 'NUMBERCUTOUT0'
filename2 = 'NUMBERCUTOUT1'
filename3 = 'NUMBERCUTOUT2'

file1 = open(filename1,'r')
file2 = open(filename2,'r')
file3 = open(filename3,'r')

value1 = []
value2 = []
value3 = []

for word in file1:
    value1.append(word[:-1])

for word in file2:
    value2.append(word[:-1])

for word in file3:
    value3.append(word[:-1])

length = len(value1)

X = np.linspace(0,length,length,endpoint=True)

fig = pl.figure(1)


pl.plot(X,value1, color ='blue', linewidth = 1.0, linestyle =':',label='Straight-forward Structure')
pl.plot(X,value2, color ='green',linewidth=1.0, linestyle='-', label='Single-branch Structure')
pl.plot(X,value3, color ='red', linewidth=1.0, linestyle='--',label='Double-branch Structure')
pl.legend(loc='upper right')

pl.title('SingleBranch(Blue) DoubleBranch(Green) TribleBranch(Red)')

pl.show()