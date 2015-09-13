#include<stdlib.h>
#include<stdio.h>

#include"../../include/stack.h"
#include"../../include/node.h"

/** @brief 创建栈
 *
 * @param length 栈的实际长度
 * 如果length 指定为0，则默认的length值为40
 *
 * @return 创建好的栈
 *
 * @retval NULL 创建失败
 */
stackPtr stack_create(int length) {
    stackPtr stack = (stackPtr) malloc(sizeof(_stack));

    if ( NULL == stack) {
        puts("创建栈失败...NULL == stack ");
        exit(0);
    }

    if (0 == length) {
        stack->length = 40;
    } else {
        stack->length = length;
    }

    stack->node_arr = (nodePtr) malloc(sizeof(_node) * stack->length);

    if ( NULL == stack->node_arr) {
        puts("创建栈失败...NULL == stack->node_arr ");
        exit(0);
    }

    stack->size = 0;
//  stack->length = 40;

    return stack;
}

/** @brief 入栈
 *
 * @param stack 栈
 * @param node 要入栈的node
 *
 * @retval 0 入栈成功
 * @retval 1 入栈失败
 */
int stack_push(stackPtr stack, nodePtr node) {
    int res = 1;

    if (!stack_is_full(stack)) {
        stack_node_array_extends(stack);
    }

    //数据后移
    int i = stack->size - 1;
    for (i = stack->size - 1; i >= 0; i--) {
        stack->node_arr[i + 1] = stack->node_arr[i];
    }
    //数据入栈
    stack->node_arr[0] = *node;
    //栈有效长度加1
    stack->size++;

    res = 0;
    return res;
}

/** @brief 判断栈是否已满
 *
 * @param stack 栈
 *
 * @retval 0 已满
 * @retval 1 未满
 */
int stack_is_full(stackPtr stack) {
    int res = 0;
    if (stack->size < stack->length) {
        res = 1;
    }

    return res;
}

/** @brief 栈扩容
 *
 * @param stack 栈
 *
 * @retval 0 扩容成功
 * @retval 1 扩容失败
 */
int stack_node_array_extends(stackPtr stack) {
    int res = 1;

    if ( NULL != stack) {
        stack->length = stack->length * 1.75;
        stack->node_arr = (nodePtr) realloc(stack->node_arr, stack->length);

        res = 0;
    }

    return res;
}

/** @brief 出栈
 *
 * @param stack 栈
 * @param node 保存出栈的元素
 *
 * @retval 0 出栈成功
 * @retval 1 出栈失败
 */
int stack_pop(stackPtr stack, nodePtr node) {
    int res = 1;

    if ( NULL != stack && stack->size > 0) {
        //保存栈顶元素
        *node = stack->node_arr[0];
        int i = 0;
        for (i = 0; i <= stack->size - 2; i++) {
            stack->node_arr[i] = stack->node_arr[i + 1];
        }
        stack->size--;
    }

    res = 0;
    return res;
}

/** @brief 取出栈顶元素的值
 *
 * @param stack 栈
 * @param node 保存栈顶元素的值
 *
 * @retval 0 取出成功
 * @retval 1 取出失败
 */
int stack_top(stackPtr stack, nodePtr node) {
    int res = 1;

    if ( NULL != stack && stack->size > 0) {
        *node = stack->node_arr[0];
        res = 0;
    }

    res = 0;
    return res;

}

/** @brief 输出栈
 *
 * @param stack 栈
 *
 * @retval 0 输出成功
 * @retval 1 输出失败
 */
int stack_print(stackPtr stack) {
    int res = 1;

    if ( NULL != stack && stack->size > 0) {
        int i = 0;
        for (i = 0; i < stack->size; i++) {
            nodePtr tmp = &stack->node_arr[i];
            node_print(tmp);
        }

    }
    res = 0;
    return res;
}
