import sys
import os
from modeller import *
from modeller.scripts import complete_pdb

env = environ()
env.libs.topology.read('${LIB}/top_heav.lib')
env.libs.parameters.read('${LIB}/par.lib')

filename, file_extension = os.path.splitext(sys.argv[1])

