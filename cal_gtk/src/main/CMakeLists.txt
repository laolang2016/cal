# main CMakeLists.txt

INCLUDE(UsePkgConfig)
 
FIND_PACKAGE(GTK)
 
IF (GTK_FOUND)
     INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIR})
      ADD_DEFINITIONS(-DHAVE_GTK)
     MESSAGE("GTK 1.x found and used as GUI\n")
ELSE (GTK_FOUND)
     PKGCONFIG(gtk+-2.0 GTK2_INCLUDE_DIR GTK2_LINK_DIR GTK2_LINK_FLAGS GTK2_CFLAGS)
     PKGCONFIG(gthread-2.0 GTHREAD_INCLUDE_DIR GTHREAD_LINK_DIR GTHREAD_LINK_FLAGS+- GTHREAD_CFLAGS)
      IF (GTK2_INCLUDE_DIR)
          SET(CMAKE_C_FLAGS "${GTK2_CFLAGS} ${GTHREAD_CFLAGS}")
          STRING(REGEX REPLACE "-l" "" GTK_LIBRARIES "${GTK2_LINK_FLAGS}                                          ${GTHREAD_LINK_FLAGS}")
          SEPARATE_ARGUMENTS(GTK_LIBRARIES)
          ADD_DEFINITIONS(-DHAVE_GTK2)
          MESSAGE("GTK 2.x found and used as GUI\n")
      ELSE (GTK2_INCLUDE_DIR)
          MESSAGE(FATAL_ERROR "GTK or GTK2 is required to build this project.")
      ENDIF (GTK2_INCLUDE_DIR)
ENDIF (GTK_FOUND)
 
# 源文件列表
set(SRC_LIST main.c)
  
# 头文件列表
include_directories(${CAL_GTK2_SOURCE_DIR}/include
/usr/include/glib-2.0
/usr/lib/x86_64-linux-gnu/glib-2.0/include
)


  
# 设置生成的可执行文件的路径
set(EXECUTABLE_OUTPUT_PATH ${CAL_GTK2_SOURCE_DIR}/bin)
  
# 生成的可执行文件
add_executable(cal_gtk2 ${SRC_LIST})
  
# 所需要的库文件的目录
link_directories(${CAL_GTK2_SOURCE_DIR}/lib
         /lib 
         /usr/lib 
)


  
# 需要链接的库文件
target_link_libraries(cal_gtk2 
${GTK2_LINK_FLAGS}
frame
 )