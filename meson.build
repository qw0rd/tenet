
project('Tenet', 
    'c', 
    version: '0.1',
    default_options: ['c_std=c11', 'warning_level=3'])

if not meson.is_cross_build() 
    error('Project can only be cross compiled')
endif

cc = meson.get_compiler('c')

if cc.get_id() != 'clang'
    error('Can only be compiled with clang for now')
endif

req_freestanding_headers = [
    'stdint.h',
    'stdatomic.h',
    'stdarg.h',
    'stdbool.h',
    'stdnoreturn.h'
]

foreach header: req_freestanding_headers
    cc.has_header(header, required: true)
endforeach

c_flags = [
    '-ffreestanding',
    '-nostdlib',
    '-mcmodel=kernel',
    '-fno-pic',
    '-fno-pie',

    '-mno-mmx',
    '-mno-sse',
    '-mno-sse2',
    '-mno-3dnow',
]

link_flags = [
    '-nostdlib',
    '-static',
    '-z',
    'max-page-size=0x1000',
]

foreach flag: c_flags
    cc.has_argument(flag)
endforeach

if not cc.compiles(files('./tests/compiler/should_compile.c'), args: c_flags, name: 'Basic compiler test')
    error('huh')
endif

supported_archs = [
    'x86_64'
]

arch = host_machine.cpu_family()

if not supported_archs.contains(arch)
    error('unknown arch: ' + arch)
endif

if cc.get_id() == 'clang'
    c_flags += '--target=x86_64-elf'
endif

add_project_arguments([c_flags, '-fuse-ld=lld'], language: ['c'])
add_project_link_arguments(link_flags, language: ['c'])

subdir('lib')
subdir('kernel')

