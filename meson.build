project(
    'TwitchXX',
    'cpp',
    default_options: ['default_library=static', 'cpp_std=c++17'],
)



deps = []
src_files = []
inc_dirs = []

deps += dependency(
    'boost',
    version: '>=1.55.0',
    modules: ['system', 'regex', 'date_time'],
)
deps += dependency('threads')
deps += dependency('openssl')
deps += dependency('zlib')
deps += dependency('cpprest')

add_project_arguments('-D_TURN_OFF_PLATFORM_STRING', language: 'cpp')



subdir('TwitchXX')

lib_TwitchXX = library(
    'TwitchXX',
    src_files,
    dependencies: deps,
    include_directories: inc_dirs,
)


TwitchXX_dep = declare_dependency(
    include_directories: inc_dirs,
    link_with: lib_TwitchXX,
)




if get_option('tests')
    subdir('TwitchXX-Tests')
endif
