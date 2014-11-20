APPNAME = 'ns'
AR = '/usr/bin/ar'
ARFLAGS = 'rcs'
BINDIR = '/usr/local/bin'
BRITE = True
BUILD_PROFILE = 'optimized'
BUILD_SUFFIX = '-optimized'
CC = ['/usr/bin/gcc']
CCDEFINES = []
CCFLAGS = ['-O3', '-g', '-Wall', '-Werror', '-O3', '-g', '-Wall', '-Werror', '-march=native', '-fstrict-overflow', '-Wstrict-overflow=5', '-Wno-error=deprecated-declarations', '-fstrict-aliasing', '-Wstrict-aliasing']
CCFLAGS_PTHREAD = '-pthread'
CCFLAGS_PYEXT = ['-fvisibility=hidden']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '8', '2')
CFLAGS_GTK2 = ['-pthread']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_MPI = ['-fstack-protector']
CFLAGS_PYEMBED = ['-fno-strict-aliasing', '-fwrapv', '-fstack-protector', '-fno-strict-aliasing']
CFLAGS_PYEXT = ['-pthread', '-fno-strict-aliasing', '-fwrapv', '-fstack-protector', '-fno-strict-aliasing', '-fwrapv', '-fstack-protector', '-fno-strict-aliasing']
CFLAGS_cshlib = ['-fPIC']
COMPILER_CC = 'gcc'
COMPILER_CXX = 'g++'
CPPPATH = ['/home/shimizu/ns-allinone-3.21/BRITE', '/home/shimizu/ns-allinone-3.21/BRITE/Models', '/home/shimizu/ns-allinone-3.21/BRITE', '/home/shimizu/ns-allinone-3.21/BRITE/Models']
CPPPATH_BRITE = ['/home/shimizu/ns-allinone-3.21/BRITE', '/home/shimizu/ns-allinone-3.21/BRITE/Models']
CPPPATH_ST = '-I%s'
CXX = ['/usr/bin/g++']
CXXDEFINES = ['NS3_BRITE', 'NS3_BRITE']
CXXFLAGS = ['-O3', '-g', '-Wall', '-Werror', '-march=native', '-fstrict-overflow', '-Wstrict-overflow=5', '-Wno-error=deprecated-declarations', '-fstrict-aliasing', '-Wstrict-aliasing']
CXXFLAGS_GTK2 = ['-pthread']
CXXFLAGS_MACBUNDLE = ['-fPIC']
CXXFLAGS_MPI = ['-fstack-protector']
CXXFLAGS_PTHREAD = '-pthread'
CXXFLAGS_PYEMBED = ['-fno-strict-aliasing', '-fwrapv', '-fstack-protector', '-fno-strict-aliasing']
CXXFLAGS_PYEXT = ['-pthread', '-fno-strict-aliasing', '-fwrapv', '-fstack-protector', '-fno-strict-aliasing', '-fwrapv', '-fstack-protector', '-fno-strict-aliasing', '-fvisibility=hidden', '-Wno-array-bounds']
CXXFLAGS_cxxshlib = ['-fPIC']
CXXLNK_SRC_F = []
CXXLNK_TGT_F = ['-o']
CXX_NAME = 'gcc'
CXX_SRC_F = []
CXX_TGT_F = ['-c', '-o']
DATADIR = '/usr/local/share'
DATAROOTDIR = '/usr/local/share'
DEFINES = ['HAVE_SYS_IOCTL_H=1', 'HAVE_IF_NETS_H=1', 'HAVE_NET_ETHERNET_H=1', 'HAVE_PACKET_H=1', 'HAVE_MPI=1', 'HAVE_IF_TUN_H=1', 'HAVE_GSL=1']
DEFINES_MPI = ['NS3_MPICH', 'NS3_MPI']
DEFINES_NSCLICK = ['NS3_CLICK']
DEFINES_PYEMBED = ['NDEBUG', '_FORTIFY_SOURCE=2']
DEFINES_PYEXT = ['NDEBUG', '_FORTIFY_SOURCE=2', 'NDEBUG', '_FORTIFY_SOURCE=2']
DEFINES_ST = '-D%s'
DEST_BINFMT = 'elf'
DEST_CPU = 'x86_64'
DEST_OS = 'linux'
DL = True
DOCDIR = '/usr/local/share/doc/ns'
DOXYGEN = '/usr/bin/doxygen'
DVIDIR = '/usr/local/share/doc/ns'
ENABLE_BRITE = True
ENABLE_EMU = True
ENABLE_EXAMPLES = True
ENABLE_FDNETDEV = True
ENABLE_GSL = ' -lgsl -lgslcblas -lm  \n'
ENABLE_GTK2 = '-pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/freetype2 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/libpng12 -I/usr/include/harfbuzz  -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo -lpango-1.0 -lfontconfig -lgobject-2.0 -lglib-2.0 -lfreetype  \n'
ENABLE_LIBXML2 = '-I/usr/include/libxml2  -lxml2  \n'
ENABLE_MPI = True
ENABLE_NSC = False
ENABLE_PYTHON_BINDINGS = True
ENABLE_PYTHON_SCANNING = True
ENABLE_PYVIZ = True
ENABLE_REAL_TIME = True
ENABLE_STATIC_NS3 = False
ENABLE_SUDO = True
ENABLE_TAP = True
ENABLE_TESTS = True
ENABLE_THREADING = True
EXAMPLE_DIRECTORIES = ['routing', 'matrix-topology', 'udp', 'ipv6', 'tutorial', 'tcp', 'wireless', 'energy', 'realtime', 'udp-client-server', 'stats', 'socket', 'naming', 'error-model']
EXEC_PREFIX = '/usr/local'
GCCXML = '/usr/bin/gccxml'
GCC_RTTI_ABI_COMPLETE = 'True'
HTMLDIR = '/usr/local/share/doc/ns'
INCLUDEDIR = '/usr/local/include'
INCLUDES_BRITE = '/home/shimizu/ns-allinone-3.21/BRITE'
INCLUDES_GTK2 = ['/usr/include/gtk-2.0', '/usr/lib/x86_64-linux-gnu/gtk-2.0/include', '/usr/include/atk-1.0', '/usr/include/cairo', '/usr/include/gdk-pixbuf-2.0', '/usr/include/pango-1.0', '/usr/include/gio-unix-2.0/', '/usr/include/freetype2', '/usr/include/glib-2.0', '/usr/lib/x86_64-linux-gnu/glib-2.0/include', '/usr/include/pixman-1', '/usr/include/libpng12', '/usr/include/harfbuzz']
INCLUDES_LIBXML2 = ['/usr/include/libxml2']
INCLUDES_MPI = ['/usr/include/mpich']
INCLUDES_NSCLICK = ['/home/shimizu/ns-allinone-3.21/click/include']
INCLUDES_PYEMBED = ['/usr/include/python2.7', '/usr/include/x86_64-linux-gnu/python2.7']
INCLUDES_PYEXT = ['/usr/include/python2.7', '/usr/include/x86_64-linux-gnu/python2.7']
INFODIR = '/usr/local/share/info'
INT64X64_USE_128 = 1
LIBDIR = '/usr/local/lib'
LIBEXECDIR = '/usr/local/libexec'
LIBPATH_BRITE = ['/home/shimizu/ns-allinone-3.21/BRITE']
LIBPATH_MPI = ['/usr/lib/x86_64-linux-gnu']
LIBPATH_NSCLICK = ['/home/shimizu/ns-allinone-3.21/click/ns']
LIBPATH_PYEMBED = ['/usr/lib']
LIBPATH_PYEXT = ['/usr/lib']
LIBPATH_PYTHON2.7 = ['/usr/lib']
LIBPATH_ST = '-L%s'
LIB_BOOST = []
LIB_BRITE = ['brite']
LIB_DL = ['dl']
LIB_GSL = ['gsl', 'gslcblas', 'm']
LIB_GTK2 = ['gtk-x11-2.0', 'gdk-x11-2.0', 'atk-1.0', 'gio-2.0', 'pangoft2-1.0', 'pangocairo-1.0', 'gdk_pixbuf-2.0', 'cairo', 'pango-1.0', 'fontconfig', 'gobject-2.0', 'glib-2.0', 'freetype']
LIB_LIBXML2 = ['xml2']
LIB_MPI = ['mpichcxx', 'mpich', 'opa', 'mpl', 'rt', 'cr', 'pthread']
LIB_NSCLICK = ['nsclick']
LIB_PYEMBED = ['python2.7']
LIB_PYEXT = ['python2.7']
LIB_PYTHON2.7 = ['python2.7']
LIB_RT = ['rt']
LIB_ST = '-l%s'
LINKFLAGS_GTK2 = ['-pthread']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_MPI = ['-Wl,-Bsymbolic-functions', '-Wl,-z,relro']
LINKFLAGS_PTHREAD = '-pthread'
LINKFLAGS_PYEMBED = ['-Wl,-Bsymbolic-functions', '-Wl,-z,relro']
LINKFLAGS_PYEXT = ['-Wl,-Bsymbolic-functions', '-Wl,-z,relro', '-pthread', '-Wl,-O1', '-Wl,-Bsymbolic-functions', '-Wl,-Bsymbolic-functions', '-Wl,-z,relro']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINKFLAGS_cxxshlib = ['-shared']
LINKFLAGS_cxxstlib = ['-Wl,-Bstatic']
LINK_CC = ['/usr/bin/gcc']
LINK_CXX = ['/usr/bin/g++']
LOCALEDIR = '/usr/local/share/locale'
LOCALSTATEDIR = '/usr/local/var'
MANDIR = '/usr/local/share/man'
MODULES_NOT_BUILT = ['openflow']
NS3_ENABLED_MODULES = ['ns3-antenna', 'ns3-aodv', 'ns3-applications', 'ns3-bridge', 'ns3-brite', 'ns3-buildings', 'ns3-click', 'ns3-config-store', 'ns3-core', 'ns3-csma', 'ns3-csma-layout', 'ns3-dsdv', 'ns3-dsr', 'ns3-emu', 'ns3-energy', 'ns3-fd-net-device', 'ns3-flow-monitor', 'ns3-internet', 'ns3-lr-wpan', 'ns3-lte', 'ns3-mesh', 'ns3-mobility', 'ns3-mpi', 'ns3-netanim', 'ns3-network', 'ns3-nix-vector-routing', 'ns3-olsr', 'ns3-point-to-point', 'ns3-point-to-point-layout', 'ns3-propagation', 'ns3-sixlowpan', 'ns3-spectrum', 'ns3-stats', 'ns3-tap-bridge', 'ns3-test', 'ns3-topology-read', 'ns3-uan', 'ns3-virtual-net-device', 'ns3-visualizer', 'ns3-wave', 'ns3-wifi', 'ns3-wimax']
NS3_EXECUTABLE_PATH = ['/home/shimizu/ns-allinone-3.21/ns-3.21/build/src/emu', '/home/shimizu/ns-allinone-3.21/ns-3.21/build/src/fd-net-device', '/home/shimizu/ns-allinone-3.21/ns-3.21/build/src/tap-bridge']
NS3_MODULES = ['ns3-antenna', 'ns3-aodv', 'ns3-applications', 'ns3-bridge', 'ns3-brite', 'ns3-buildings', 'ns3-click', 'ns3-config-store', 'ns3-core', 'ns3-csma', 'ns3-csma-layout', 'ns3-dsdv', 'ns3-dsr', 'ns3-emu', 'ns3-energy', 'ns3-fd-net-device', 'ns3-flow-monitor', 'ns3-internet', 'ns3-lr-wpan', 'ns3-lte', 'ns3-mesh', 'ns3-mobility', 'ns3-mpi', 'ns3-netanim', 'ns3-network', 'ns3-nix-vector-routing', 'ns3-olsr', 'ns3-point-to-point', 'ns3-point-to-point-layout', 'ns3-propagation', 'ns3-sixlowpan', 'ns3-spectrum', 'ns3-stats', 'ns3-tap-bridge', 'ns3-test', 'ns3-topology-read', 'ns3-uan', 'ns3-virtual-net-device', 'ns3-visualizer', 'ns3-wave', 'ns3-wifi', 'ns3-wimax']
NS3_MODULE_PATH = ['/usr/lib/gcc/x86_64-linux-gnu/4.8', '/home/shimizu/ns-allinone-3.21/ns-3.21/build', '/home/shimizu/ns-allinone-3.21/BRITE', '/home/shimizu/ns-allinone-3.21/click/lib', '/home/shimizu/ns-allinone-3.21/click/ns']
NS3_OPTIONAL_FEATURES = [('python', 'Python Bindings', True, None), ('pygccxml', 'Python API Scanning Support', True, None), ('brite', 'BRITE Integration', True, 'BRITE library not found'), ('nsclick', 'NS-3 Click Integration', True, 'nsclick library not found'), ('GtkConfigStore', 'GtkConfigStore', '-pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/freetype2 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/libpng12 -I/usr/include/harfbuzz  -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo -lpango-1.0 -lfontconfig -lgobject-2.0 -lglib-2.0 -lfreetype  \n', "library 'gtk+-2.0 >= 2.12' not found"), ('XmlIo', 'XmlIo', '-I/usr/include/libxml2  -lxml2  \n', "library 'libxml-2.0 >= 2.7' not found"), ('Threading', 'Threading Primitives', True, '<pthread.h> include not detected'), ('RealTime', 'Real Time Simulator', True, 'threading not enabled'), ('EmuNetDevice', 'Emulated Net Device', True, '<netpacket/packet.h> include not detected'), ('FdNetDevice', 'File descriptor NetDevice', True, 'FdNetDevice module enabled'), ('TapFdNetDevice', 'Tap FdNetDevice', True, 'Tap support enabled'), ('EmuFdNetDevice', 'Emulation FdNetDevice', True, 'Emulation support enabled'), ('PlanetLabFdNetDevice', 'PlanetLab FdNetDevice', False, 'PlanetLab operating system not detected (see option --force-planetlab)'), ('nsc', 'Network Simulation Cradle', False, 'NSC not found (see option --with-nsc)'), ('mpi', 'MPI Support', True, ''), ('openflow', 'NS-3 OpenFlow Integration', False, 'Required boost libraries not found'), ('SqliteDataOutput', 'SQlite stats data output', [], "library 'sqlite3' not found"), ('TapBridge', 'Tap Bridge', True, '<linux/if_tun.h> include not detected'), ('PyViz', 'PyViz visualizer', True, None), ('ENABLE_SUDO', 'Use sudo to set suid bit', True, 'because we like it'), ('ENABLE_TESTS', 'Build tests', True, 'option --enable-tests selected'), ('ENABLE_EXAMPLES', 'Build examples', True, 'option --enable-examples selected'), ('GSL', 'GNU Scientific Library (GSL)', ' -lgsl -lgslcblas -lm  \n', 'GSL not found')]
NSCLICK = True
OLDINCLUDEDIR = '/usr/include'
PACKAGE = 'ns'
PDFDIR = '/usr/local/share/doc/ns'
PKGCONFIG = '/usr/bin/pkg-config'
PLATFORM = 'linux2'
PREFIX = '/usr/local'
PRINT_BUILT_MODULES_AT_END = False
PSDIR = '/usr/local/share/doc/ns'
PYC = 1
PYCMD = '"import sys, py_compile;py_compile.compile(sys.argv[1], sys.argv[2])"'
PYFLAGS = ''
PYFLAGS_OPT = '-O'
PYO = 1
PYTHON = ['/usr/bin/python']
PYTHONARCHDIR = '/usr/local/lib/python2.7/dist-packages'
PYTHONDIR = '/usr/local/lib/python2.7/dist-packages'
PYTHON_BINDINGS_APIDEFS = 'gcc-LP64'
PYTHON_CONFIG = '/usr/bin/python-config'
PYTHON_VERSION = '2.7'
REQUIRED_BOOST_LIBS = ['system', 'signals', 'filesystem']
RPATH_ST = '-Wl,-rpath,%s'
SBINDIR = '/usr/local/sbin'
SHAREDSTATEDIR = '/usr/local/com'
SHLIB_MARKER = '-Wl,-Bdynamic'
SONAME_ST = '-Wl,-h,%s'
SQLITE_STATS = None
STLIBPATH_ST = '-L%s'
STLIB_MARKER = '-Wl,-Bstatic'
STLIB_ST = '-l%s'
SUDO = '/usr/bin/sudo'
SYSCONFDIR = '/usr/local/etc'
VALGRIND = '/usr/bin/valgrind'
VALGRIND_FOUND = True
VERSION = '3.21'
WITH_BRITE = '/home/shimizu/ns-allinone-3.21/BRITE'
WITH_NSCLICK = '/home/shimizu/ns-allinone-3.21/click'
WITH_PYBINDGEN = '/home/shimizu/ns-allinone-3.21/pybindgen-0.17.0.876'
WL_SONAME_SUPPORTED = True
cfg_files = ['/home/shimizu/ns-allinone-3.21/ns-3.21/build/ns3/config-store-config.h', '/home/shimizu/ns-allinone-3.21/ns-3.21/build/ns3/core-config.h']
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
cxxprogram_PATTERN = '%s'
cxxshlib_PATTERN = 'lib%s.so'
cxxstlib_PATTERN = 'lib%s.a'
define_key = ['HAVE_PACKET_H', 'HAVE_SYS_IOCTL_H', 'HAVE_IF_NETS_H', 'HAVE_NET_ETHERNET_H', 'HAVE_IF_TUN_H', 'HAVE_MPI', 'HAVE_GSL']
macbundle_PATTERN = '%s.bundle'
pyext_PATTERN = '%s.so'
