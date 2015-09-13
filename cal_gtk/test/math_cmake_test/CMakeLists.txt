cmake_minimum_required(VERSION 3.3)
project(HELLO)
set(SRC_LIST main.c)

# 所需要的glibc(gtk)库文件的目录
include_directories(
        /usr/include/glib-2.0
        /usr/lib/x86_64-linux-gnu/glib-2.0/include
         /lib 
         /usr/lib 
)

add_executable(hello ${SRC_LIST})

# 需要链接的glibc(gtk)库文件
target_link_libraries(hello
        glib-2.0
        libm.so
)