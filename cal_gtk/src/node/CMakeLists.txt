# node CMakeLists.txt
 
# 设置编译器
set(CMAKE_C_COMPILER gcc)
  
# 源文件列表
set(SRC_LIST node.c)
  
# 头文件目录
include_directories(${CAL_GTK2_SOURCE_DIR}/include)
  
# 设置生成的库文件的路径
set(LIBRARY_OUTPUT_PATH ${CAL_GTK2_SOURCE_DIR}/lib)
  
# 生成的库文件
add_library(node STATIC ${SRC_LIST})