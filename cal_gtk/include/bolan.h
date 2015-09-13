/** @file bolan.h
 * 实现 逆波兰算法
 *
 */

#include"stack.h"

#ifndef BOLAN_H_
#define BOLAN_H_

/** @brief 将一个中缀表达式转换为逆波兰表达式
 *
 * @param expPtr 表达式
 * @param stack 保存逆波兰表达式的栈
 *
 * @retval 0 转换成功
 * @retval 1 转换失败
 */
int bolan_from_exp( char * expPtr, stackPtr stack);

/** @brief 对逆波兰式作逆序处理，并去除#符号
 *
 * @param stack 后缀栈
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int bolan_inverted(stackPtr stack);

/** @brief 计算逆波兰表达式
 *
 * @param stack 保存逆波兰表达式的栈
 *
 * @return 计算结果
 */
double bolan_cal( stackPtr stack);

#endif /* BOLAN_H_ */
