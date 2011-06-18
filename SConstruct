#
# TODO: factor most of this boilerplate into a library for convenience
#

cxx = 'g++-4.5'
flags = '-std=c++0x -Wall -O0 -fno-inline -ggdb'

# Include stuff from the OS environment; TERM is needed for scons to leave
# color codes in tool output where applicable
import os
env = Environment(ENV = {'PATH' : os.environ['PATH'],
                         'TERM' : os.environ['TERM'],
                         'HOME' : os.environ['HOME']})

env.Replace(CXX = cxx)
env.Replace(CPPFLAGS = flags)

Export('env')
env.SConscript('src/SConscript', variant_dir='build', duplicate=False)
