#
# TODO: factor most of this boilerplate into a library for convenience
#

# Include stuff from the OS environment; TERM is needed for scons to leave
# color codes in tool output where applicable
import os
env = Environment(ENV = {'PATH' : os.environ['PATH'],
                         'TERM' : os.environ['TERM'],
                         'HOME' : os.environ['HOME']})

Export('env')

env.SConscript('src/SConscript', variant_dir='build', duplicate=False)
