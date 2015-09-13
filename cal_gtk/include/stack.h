/** @file stack.h
 * 栈的操作的声明
 *
 */

#include"node.h"

#ifndef STACK_H_
#define STACK_H_


/** @brief 栈结构体
 *
 */
struct __stack{
    /** @brief node 数组头指针  */
    nodePtr node_arr;

    /** @brief 栈有效长度 */
    int size;

    /** @brief 栈实际长度  */
    int length;

};


typedef struct __stack _stack;
typedef struct __stack * stackPtr;


/** @brief 创建栈
 *
 * @param length 栈的实际长度
 * 如果length 指定为0，则默认的length值为40
 *
 * @return 创建好的栈
 *
 * @retval NULL 创建失败
 */
stackPtr stack_create( int length );

/** @brief 入栈
 *
 * @param stack 栈
 * @param node 要入栈的node
 *
 * @retval 0 入栈成功
 * @retval 1 入栈失败
 */
int stack_push( stackPtr stack, nodePtr node);

/** @brief 判断栈是否已满
 *
 * @param stack 栈
 *
 * @retval 0 已满
 * @retval 1 未满
 */
int stack_is_full( stackPtr stack );


/** @brief 栈扩容
 *
 * @param stack 栈
 *
 * @retval 0 扩容成功
 * @retval 1 扩容失败
 */
int stack_node_array_extends( stackPtr stack );

/** @brief 出栈
 *
 * @param stack 栈
 * @param node 保存出栈的元素
 *
 * @retval 0 出栈成功
 * @retval 1 出栈失败
 */
int stack_pop( stackPtr stack, nodePtr node);

/** @brief 取出栈顶元素的值
 *
 * @param stack 栈
 * @param node 保存栈顶元素的值
 *
 * @retval 0 取出成功
 * @retval 1 取出失败
 */
int stack_top( stackPtr stack, nodePtr node );

/** @brief 输出栈
 *
 * @param stack 栈
 *
 * @retval 0 输出成功
 * @retval 1 输出失败
 */
int stack_print( stackPtr stack );
#endif /* STACK_H_ */
