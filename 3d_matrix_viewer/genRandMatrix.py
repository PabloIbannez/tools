import sys
import numpy as np
from datetime import datetime

np.random.seed(datetime.now().microsecond)

dimX = int(sys.argv[1])
dimY = int(sys.argv[2])
dimZ = int(sys.argv[3])

A = np.random.rand(dimX,dimY,dimZ)

for i in range(dimX):
    for j in range(dimY):
        for k in range(dimZ):
            print i,j,k,A[i,j,k]
