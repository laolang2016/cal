/** @file tools.h
 * 工具函数
 */

#ifndef TOOLS_H_
#define TOOLS_H_

/** @brief 删除表达式中的空格及不可见字符
 *
 * @param expPtr 原表达式字符串
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int tools_delete_spaces( char * expPtr );


/** @brief 表达式的正负号前加0
 *
 * @param expPtr 表达式
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int tools_add_zero( char * expPtr );

/** @brief 判断当前字符是否为+ - * / 这四个运算符之一
 *
 * @param ch 要判断的符号
 *
 * @retval 0 是
 * @retval 1 否
 */
int tools_is_char_operator( char ch );

/** @brief 判断字符 ch 是否为括号
 *
 * @param ch 要判断的字符
 *
 * @retval 0 是
 * @retval 1 否
 */
int toolls_is_char_paren( char ch );

/** @brief 字符串末尾添加 #
 *
 * @param expPtr 字符串
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int tools_add_sharp( char * expPtr );

/** @brief 比较运算符优先级
 *
 * @param ch1 当前运算符
 * @param ch2 与之比较的运算符，也就是临时栈栈顶元素的值
 *
 * @retval 1    当前运算符大于与之比较的运算符
 * @retval 0    当前运算符等于与之比较的运算符
 * @retval -1   当前运算符小于于与之比较的运算符
 */
int tools_operator_compare(char ch1, char ch2);

/** @brief 在字符串str中查找字符ch第一次出现的位置
 *
 * @param str 要搜索字符串
 * @param ch 要查找的字符
 * @return 查找到的位置
 */
int tools_str_ch_index_first( char * str, char ch );

/** @brief 处理表达式中的0
 * 如果小数点后面全为0，则将小数点及之后的字符去除
 * 如果小数点之后有数字，则将最后一个非0字符后面的0去除
 * @param exp 要处理的字符串
 * @retval 0 操作成功
 * @retval 1 操作失败
 */
int tools_exp_handle_zero(char * exp);

#endif /* TOOLS_H_ */
