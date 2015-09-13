#include<string.h>
#include<ctype.h>

#include "../../include/tools.h"

/** @brief 删除表达式中的空格及不可见字符
 *
 * @param expPtr 原表达式字符串
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int tools_delete_spaces(char * expPtr) {
    int res = 1;
    char tmp[100] = { '\0' };
    strcpy(tmp, expPtr);
    int i = 0;
    int j = 0;
    int len = strlen(tmp);

    for (i = 0; i < len; i++) {
        char ch = tmp[i];

        //忽略不可见字符
        if (!isspace(ch)) {
            expPtr[j] = ch;
            j++;
        }
    }

    expPtr[j] = '\0';

    res = 0;

    return res;
}

/** @brief 表达式的正负号前加0
 *
 * @param expPtr 表达式
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int tools_add_zero(char * expPtr) {
    int res = 1;
    char tmp[100] = { '\0' };
    strcpy(tmp, expPtr);
    int len = strlen(tmp);
    int i = 0;
    int j = 0;

    //如果第一个符号是正负号，则在其前加0
    if ('+' == tmp[0] || '-' == tmp[0]) {
        expPtr[0] = '0';
        expPtr[1] = tmp[0];
        j = 2;
    }else{
        //如果不是，则直接复制
        expPtr[j] = tmp[0];
        j++;
    }

    for (i = 1; i < len; i++) {

        char ch = tmp[i];


        expPtr[j] = tmp[i];
        j++;

        //如果当前字符是 ( 且其后面是 + 或 - ，则在 ( 之后加 0
        if ('(' == ch) {
            if ('+' == tmp[i + 1] || '-' == tmp[i + 1]) {
                expPtr[j] = '0';
                j++;
            }

        }
    }
    expPtr[j] = '\0';

    return res;
}

/** @brief 判断当前字符是否为+ - * / 这四个运算符之一
 *
 * @param ch 要判断的符号
 *
 * @retval 0 是
 * @retval 1 否
 */
int tools_is_char_operator(char ch) {
    int res = 1;

    switch (ch) {
    case '+':
    case '-':
    case '*':
    case '/': {
        res = 0;
        break;
    }
    }

    return res;
}

/** @brief 判断字符 ch 是否为括号
 *
 * @param ch 要判断的字符
 *
 * @retval 0 是
 * @retval 1 否
 */
int toolls_is_char_paren(char ch) {
    int res = 1;

    switch (ch) {
    case '(':
    case ')': {
        res = 0;
        break;
    }
    }

    return res;
}

/** @brief 字符串末尾添加 #
 *
 * @param expPtr 字符串
 *
 * @retval 0 执行成功
 * @retval 1 执行失败
 */
int tools_add_sharp(char * expPtr) {
    int res = 1;
    int len = strlen(expPtr);
    expPtr[len] = '#';
    expPtr[len + 1] = '\0';

    res = 0;
    return res;
}

/** @brief 比较运算符优先级
 *
 * @param ch1 当前运算符
 * @param ch2 与之比较的运算符，也就是临时栈栈顶元素的值
 *
 * @retval 1    当前运算符大于与之比较的运算符
 * @retval 0    当前运算符等于与之比较的运算符
 * @retval -1   当前运算符小于于与之比较的运算符
 */
int tools_operator_compare(char ch1, char ch2) {
    int res = 0;
    if ('+' == ch1 || '-' == ch1) {
        if ('#' == ch2) {
            res = 1;
        } else if ('+' == ch2 || '-' == ch2) {
            res = 0;
        } else if ('*' == ch2 || '/' == ch2) {
            res = -1;
        } else if ('(' == ch2) {
            res = 1;
        }
    } else if ('*' == ch1 || '/' == ch1) {
        if ('#' == ch2) {
            res = 1;
        } else if ('+' == ch2 || '-' == ch2) {
            res = 1;
        } else if ('*' == ch2 || '/' == ch2) {
            res = 0;
        } else if ('(' == ch2) {
            res = 1;
        }
    }
    return res;
}

/** @brief 在字符串str中查找字符ch第一次出现的位置
 *
 * @param str 要搜索字符串
 * @param ch 要查找的字符
 * @return 查找到的位置
 */
int tools_str_ch_index_first( char * str, char ch ){
    int i = 0;
    int index;
    int str_len = strlen(str);

    for( i = 0; i < str_len; i++ ){
        if( ch == str[i]){
            break;
        }
    }

    index = i--;

    return index;
}

/** @brief 处理表达式中的0
 * 如果小数点后面全为0，则将小数点及之后的字符去除
 * 如果小数点之后有数字，则将最后一个非0字符后面的0去除
 * @param exp 要处理的字符串
 * @retval 0 操作成功
 * @retval 1 操作失败
 */
int tools_exp_handle_zero(char * exp){
    int res = 0;
    //小数点的位置
    int dot_index = tools_str_ch_index_first(exp,'.');
    int i = 0;


    //结果字符串的长度
    int exp_len = strlen(exp);

    //小数点之后最后一个数字出现的位置
    int last_num = 0;
    for( i = exp_len - 1; i > dot_index  ; i-- ){
        if( '0' != exp[i]){
            last_num = i;
            break;
        }
    }

    if( 0 == last_num ){
        exp[dot_index] = '\0';
    }else{
        exp[i+1] = '\0';
    }

    res = 1;

    return res;
}
