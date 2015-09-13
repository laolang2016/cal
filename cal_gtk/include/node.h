/** @file node.h
 * 保存由字符串转换后的数据
 *
 */

#ifndef NODE_H_
#define NODE_H_

/** @struct __node
 * 栈中的每个元素的类型
 *
 * flag 的值所代表的意义
 * 0
 *  数字 保存在num中
 * + - / *
 *  运算符 保存在operator中
 * ( )
 *  括号 保存在paren中
 * #
 *  结束符 保存在sharpt中
 */
struct __node{
    /** @brief 保存数字  */
    double num;

    /** @brief 保存运算符  */
    char operator;

    /** @brief 保存括号  */
    char paren;

    /** @brief 保存 #  */
    char sharp;

    /** @brief 标志，表达本 node所保存的数据的类型   */
    char flag;
};

typedef struct __node _node;
typedef struct __node * nodePtr;


/** @brief 创建数字node
 *
 * @param num 数字
 * @return 创建的node
 */
nodePtr node_create_num( double num );

/** @brief 创建运算符node
 *
 * @param operator 运算符
 * @return 创建的node
 */
nodePtr node_create_operator( char operator );

/** @brief 创建括号node
 *
 * @param paren 括号
 * @return 创建的node
 */
nodePtr node_create_paren( char paren );

/** @brief 创建结符
 *
 * @param sharp #
 *
 * @return 创建的node
 */
nodePtr node_create_sharp( char sharp );

/** @brief 根据指定的符号创建node
 *
 * @param ch 指定的node
 *
 * @retval 0 创建成功
 * @retval 1 创建失败
 */
nodePtr node_create_from_char( char ch );

/** @brief 打印此node的内容
 * 若是数字开型，则只打印数字，其它类似
 *
 * @param node 要打印的node
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int node_print( nodePtr node );

/** @brief 计算一个表达式应当用多少个node保存
 *
 * @param expPtr 表达式
 *
 * @return 就使用的node数
 */
int node_exp_num( char * expPtr );

/** @brief 把表达式字符串转换为node数组
 *
 * @param expPtr 表达式字符串
 *
 * @return 转换后的node数组
 */
nodePtr node_create_array( char * expPtr );


#endif /* NODE_H_ */
