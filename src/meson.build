deps = [
    interface99.dependency('interface99'),
    metalang99.dependency('metalang99'),
]
croquet_inc = include_directories('../include')
croquet = library('croquet', [
    'main.c'
], dependencies: deps, include_directories: croquet_inc, install: true)

croquet_dep = declare_dependency(link_with: croquet, dependencies: deps, include_directories: croquet_inc)