project('slides', 'cpp',
        version: '1.0.0',
        default_options: 'default_library=static')

sdl2_dep = dependency('sdl2')
sdl2_ttf_dep = dependency('SDL2_ttf')
curses_dep = dependency('ncurses')

executable('main', 'main.cpp', win_subsystem: 'windows', dependencies: [sdl2_dep, curses_dep, sdl2_ttf_dep])