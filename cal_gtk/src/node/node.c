#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"../../include/node.h"
#include "../../include/tools.h"

/** @brief 创建数字node
 *
 * @param num 数字
 * @return 创建的node
 */
nodePtr node_create_num(double num) {
    nodePtr node = (nodePtr) malloc(sizeof(_node));
    if ( NULL == node) {
        puts("创建数字node失败...NULL == node ");
        exit(0);
    }

    node->num = num;
    node->flag = '0';

    node->operator = '\0';
    node->paren = '\0';
    node->sharp = '\0';

    return node;
}

/** @brief 创建运算符node
 *
 * @param operator 运算符
 * @return 创建的node
 */
nodePtr node_create_operator(char operator) {
    nodePtr node = (nodePtr) malloc(sizeof(_node));
    if ( NULL == node) {
        puts("创建数字node失败...NULL == node ");
        exit(0);
    }

    node->operator = operator;
    node->flag = operator;

    node->num = 0;
    node->paren = '\0';
    node->sharp = '\0';

    return node;

}

/** @brief 创建括号node
 *
 * @param paren 括号
 * @return 创建的node
 */
nodePtr node_create_paren(char paren) {
    nodePtr node = (nodePtr) malloc(sizeof(_node));
    if ( NULL == node) {
        puts("创建数字node失败...NULL == node ");
        exit(0);
    }

    node->paren = paren;
    node->flag = paren;

    node->operator = '\0';
    node->num = 0;
    node->sharp = '\0';

    return node;
}

/** @brief 创建结符
 *
 * @param sharp #
 *
 * @return 创建的node
 */
nodePtr node_create_sharp(char sharp) {
    nodePtr node = (nodePtr) malloc(sizeof(_node));
    if ( NULL == node) {
        puts("创建数字node失败...NULL == node ");
        exit(0);
    }

    node->sharp = sharp;
    node->flag = sharp;

    node->operator = '\0';
    node->num = 0;
    node->paren = '\0';

    return node;
}

/** @brief 根据指定的符号创建node
 *
 * @param ch 指定的node
 *
 * @retval 0 创建成功
 * @retval 1 创建失败
 */
nodePtr node_create_from_char(char ch) {
    nodePtr node = NULL;

    if (!tools_is_char_operator(ch)) {
        node = node_create_operator(ch);
    } else if (!toolls_is_char_paren(ch)) {
        node = node_create_paren(ch);
    } else if ('#' == ch) {
        node = node_create_sharp(ch);
    }

    return node;
}

/** @brief 打印此node的内容
 * 若是数字开型，则只打印数字，其它类似
 *
 * @param node 要打印的node
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int node_print(nodePtr node) {
    int res = 1;

    //运算符
    if (!tools_is_char_operator(node->flag)) {
        printf("%c\n", node->operator);
    } else if (!toolls_is_char_paren(node->flag)) {
        printf("%c\n", node->paren);
    } else if ('0' == node->flag) {
        printf("%.2lf\n", node->num);
    } else if ('#' == node->flag) {
        printf("%c\n", node->sharp);
    }

    res = 0;
    return res;

}

/** @brief 计算一个表达式应当用多少个node保存
 *
 * @param expPtr 表达式
 *
 * @return 就使用的node数
 */
int node_exp_num(char * expPtr) {
    //需要的node数
    int count = 0;
    int len = strlen(expPtr);
    int i = 0;
//  int j = 0;

    for (i = 0; i < len; i++) {
        char ch = expPtr[i];

        if ('#' == ch) {
            count++;
            break;
        }

        //如果是运算符，count直接加1
        if (!tools_is_char_operator(ch) || !toolls_is_char_paren(ch)) {
            count++;
        } else {
            //如果是数字，则遍历至当前数字的最后一个字符，count加1
            while (('0' <= ch && ch <= '9') || '.' == ch ) {
                i++;
                ch = expPtr[i];
            }

            count++;
            i--;

        }
    }

    return count;
}

/** @brief 把表达式字符串转换为node数组
 *
 * @param expPtr 表达式字符串
 *
 * @return 转换后的node数组
 */
nodePtr node_create_array(char * expPtr) {
    //得到转换后的数组的长度
    int array_len = node_exp_num(expPtr);
    int len = strlen(expPtr);
    int i = 0;
    int j = 0;
    int k = 0;
    nodePtr tmp = NULL;
    //创建数组
    nodePtr node_array = (nodePtr) malloc(sizeof(_node) * array_len);

    if ( NULL == node_array) {
        puts("创建node数组失败...NULL == node_array");
        exit(0);
    }

    for (i = 0; i < len; i++) {
        char ch = expPtr[i];

        //运算符
        if (!tools_is_char_operator(ch)) {

            tmp = node_create_operator(ch);
            node_array[j] = *tmp;
            j++;

        } else if (!toolls_is_char_paren(ch)) {

            //括号
            tmp = node_create_paren(ch);
            node_array[j] = *tmp;
            j++;

        } else if ('#' == ch) {

            //结束符
            tmp = node_create_sharp(ch);
            node_array[j] = *tmp;
            j++;

        } else {

            //数字
            char numArr[20] = { '\0' };
            while (('0' <= ch && ch <= '9') || '.' == ch ) {
                numArr[k++] = ch;
                i++;
                ch = expPtr[i];
            }
            double num = atof(numArr);
            tmp = node_create_num(num);
            node_array[j] = *tmp;
            j++;

            i--;
            k = 0;

        }
    }

    return node_array;
}
