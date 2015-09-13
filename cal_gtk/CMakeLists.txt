# 顶层CMakeLists.txt

cmake_minimum_required(VERSION 3.3)
 
# 定义工程名称
project(CAL_GTK2)
  
# 定义子目录src，用以递归的调用src中的MakeLists.txt
add_subdirectory(src)