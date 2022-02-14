

inc_dir = include_directories('../include')
inc_dir_lib = include_directories('../include/lib')

kernel_src = files(
    'kmain.c'
)

linker_script = meson.source_root() + '/ldscripts/x86_64.ld'

executable('tenet', kernel_src, 
    include_directories: [inc_dir, inc_dir_lib],
    link_args: ['-T' + linker_script],
    link_with: [libcore])

