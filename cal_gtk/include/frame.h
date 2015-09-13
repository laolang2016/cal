/** @file frame.h
 * 界面
 *
 */

#ifndef INCLUDE_FRAME_H_
#define INCLUDE_FRAME_H_

/** @brief 创建数字，运算符和等于号部分
 *
 * @return 创建的表格容器
 */
GtkWidget * create_table(GtkWidget * entry);

/** @brief 创建平方开方三角函数等扩展功能
 *
 * @param entry 文本框
 * @return 创建好的表格容器
 */
GtkWidget * create_extends(GtkWidget * entry);

/** @brief 等于单击
 *
 *
 * @param button
 * @param data 表达式处理器
 */
void on_button_eq_clicked(GtkWidget * button, gpointer data);

/** @brief 清除按钮，清除本次数字输入，以便重新输入
 *
 * @param button
 * @param data 表达式处理器
 */
void on_button_clear_clicked(GtkWidget * button, gpointer data);



/** @brief 数字区数字区除 = 之外的按钮单击
 *
 * @param button
 * @param data 文本框
 */
void on_button_clicked(GtkWidget * button, gpointer data);

/** @brief 求倒数
 *
 * @param button
 * @param data
 */
void on_button_reciprocal(GtkWidget * button, gpointer data);

/** @brief x^2
 *
 * @param button
 * @param data
 */
void on_button_square(GtkWidget * button, gpointer data);

/** @brief x^3
 *
 * @param button
 * @param data
 */
void on_button_cube(GtkWidget * button, gpointer data);

/** @brief sqrt(x)
 *
 * @param button
 * @param data
 */
void on_button_sqrt(GtkWidget * button, gpointer data);

/** @brief sin
 *
 * @param button
 * @param data
 */
void on_button_sin(GtkWidget * button, gpointer data);

/** @brief cos
 *
 * @param button
 * @param data
 */
void on_button_cos(GtkWidget * button, gpointer data);

/** @brief tan
 *
 * @param button
 * @param data
 */
void on_button_tan(GtkWidget * button, gpointer data);

/** @brief asin
 *
 * @param button
 * @param data
 */
void on_button_asin(GtkWidget * button, gpointer data);

/** @brief acos
 *
 * @param button
 * @param data
 */
void on_button_acos(GtkWidget * button, gpointer data);

/** @brief atan
 *
 * @param button
 * @param data
 */
void on_button_atan(GtkWidget * button, gpointer data);


#endif /* INCLUDE_FRAME_H_ */
