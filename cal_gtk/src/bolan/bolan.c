#include<stdio.h>
#include<stdlib.h>

#include"../../include/bolan.h"
#include "../../include/tools.h"
#include"../../include/stack.h"
#include"../../include/node.h"

/** @brief 将一个中缀表达式转换为逆波兰表达式
 *
 * @param expPtr 表达式
 * @param stack 保存逆波兰表达式的栈
 *
 * @retval 0 转换成功
 * @retval 1 转换失败
 */
int bolan_from_exp(char * expPtr, stackPtr stack) {
    int res = 1;
    //临时保存运算符
    stackPtr tmp = stack_create(0);

    //向临时栈中压入#符号
    nodePtr node_sharp = node_create_sharp('#');
    stack_push(tmp, node_sharp);

    //将中缀表达式字符串转换为node数组
    nodePtr node_array = node_create_array(expPtr);
    //node数组长度
    int node_array_len = node_exp_num(expPtr);

    int i = 0;
    //遍历node数组
    for (i = 0; i < node_array_len; i++) {
        nodePtr node_now = &node_array[i];

        if ('0' == node_now->flag) {
            //如果是数字，直接入结果线

            stack_push(stack, node_now);

        } else if (!tools_is_char_operator(node_now->flag)) {
            //如果是运算符，则与运算符栈栈顶元素进行比较
            //取出临时栈栈顶元素的值
            nodePtr node_tt = &tmp->node_arr[0];
            char ch = node_tt->flag;
            nodePtr node_top = node_create_from_char(ch);
            stack_top(tmp, node_top);
            char node_now_ch = node_now->flag;
            char node_top_ch = node_top->flag;

            if (tools_operator_compare(node_now_ch, node_top_ch) > 0) {
                stack_push(tmp, node_now); //将当前运算符进临时栈
            } else {
                while (1) {
                    stack_top(tmp, node_top);
                    node_top_ch = node_top->flag;
                    if (tools_operator_compare(node_now_ch, node_top_ch) <= 0) {
                        stack_pop(tmp, node_top); //将临时栈顶元素弹出
                        stack_push(stack, node_top); //将弹出的元素入后缀栈
                    } else {
                        stack_push(tmp, node_now);
                        break;
                    }

                }
            }

        } else if ('(' == node_now->flag) {
            stack_push(tmp, node_now);

        } else if (')' == node_now->flag) {

            while (1) {
                //弹出临时栈栈顶元素
                nodePtr node_tt = &tmp->node_arr[0];
                char ch = node_tt->flag;
                nodePtr node_top = node_create_from_char(ch);
                stack_pop(tmp, node_top);
                char node_top_ch = node_top->flag;

                //如果是 ( ，则结束
                if ('(' == node_top_ch) {
                    break;
                } else {
                    //如果不是 ( ，则直接送入后缀栈
                    stack_push(stack, node_top);
                }

            }

        } else if ('#' == node_now->flag) {
            nodePtr node_tt = &tmp->node_arr[0];
            char ch = node_tt->flag;
            nodePtr node_top = node_create_from_char(ch);
            stack_top(tmp, node_top);
//          char node_top_ch = node_top->flag;

            while ('#' != node_top->flag) {
                stack_pop(tmp, node_top); //将临时栈顶元素弹出
                stack_push(stack, node_top);
            }
        }
    }

    res = 0;
    return res;
}

/** @brief 对逆波兰式作逆序处理，并去除#符号
 *
 * @param stack 后缀栈
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int bolan_inverted(stackPtr stack) {
    int res = 1;

    int i = 0;
    int j = 0;
    nodePtr node_arr_new = (nodePtr) malloc(sizeof(_node) * stack->size - 1);
    for (i = stack->size - 1; i > 0; i--) {
        node_arr_new[j] = stack->node_arr[i];
        j++;
    }

    stack->node_arr = node_arr_new;
    //去除 #
//  stack->size--;
    res = 0;

    return res;
}

/** @brief 计算逆波兰表达式
 *
 * @param stack 保存逆波兰表达式的栈
 *
 * @return 计算结果
 */
double bolan_cal(stackPtr stack) {
    //保存计算结果
    double res = 0;
    //保存结果的栈
    stackPtr stack_tmp = stack_create(0);
    int i = 0;
    nodePtr node_b = node_create_num(0);
    nodePtr node_a = node_create_num(0);
    double a = 0;
    double b = 0;

    for (i = 0; i < stack->size - 1; i++) {
        nodePtr node_t = &stack->node_arr[i];
        if ('0' == node_t->flag) {
            nodePtr node_num = node_create_num(node_t->num);
            stack_push(stack_tmp, node_num);
        } else {
            node_b = node_create_num(0);
            node_a = node_create_num(0);
            stack_pop(stack_tmp, node_b);
            stack_pop(stack_tmp, node_a);
            a = node_a->num;
            b = node_b->num;

            char ch = node_t->flag;
            switch (ch) {
            case '+': {
                a = a + b;
                break;
            }
            case '-': {
                a = a - b;
                break;
            }
            case '*': {
                a = a * b;
                break;
            }
            case '/': {
                a = a / b;
                break;
            }
            }

            node_a = node_create_num(a);
            stack_push(stack_tmp, node_a);

        }
    }

    stack_pop(stack_tmp, node_a);
    res = node_a->num;

    return res;
}
