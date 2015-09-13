#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


#include"../../include/frame.h"
#include"../../include/tools.h"
#include"../../include/node.h"
#include"../../include/stack.h"
#include"../../include/bolan.h"
#include"../../include/gloab.h"



/** @brief 创建数字区
 *
 * @return
 */
GtkWidget * create_table(GtkWidget * entry) {
    //表格容器
    GtkWidget * table;

    //数字
    GtkWidget * button_0;
    GtkWidget * button_1;
    GtkWidget * button_2;
    GtkWidget * button_3;
    GtkWidget * button_4;
    GtkWidget * button_5;
    GtkWidget * button_6;
    GtkWidget * button_7;
    GtkWidget * button_8;
    GtkWidget * button_9;

    //小数点
    GtkWidget * button_dot;
    //等于号
    GtkWidget * button_eq;

    //运算符
    GtkWidget * button_sum;
    GtkWidget * button_minus;
    GtkWidget * button_ride;
    GtkWidget * button_divide;

    //创建各个组件并与相关事件处理函数连接起来
    button_0 = gtk_button_new_with_label("0");
    g_signal_connect(G_OBJECT(button_0), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_1 = gtk_button_new_with_label("1");
    g_signal_connect(G_OBJECT(button_1), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_2 = gtk_button_new_with_label("2");
    g_signal_connect(G_OBJECT(button_2), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_3 = gtk_button_new_with_label("3");
    g_signal_connect(G_OBJECT(button_3), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_4 = gtk_button_new_with_label("4");
    g_signal_connect(G_OBJECT(button_4), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_5 = gtk_button_new_with_label("5");
    g_signal_connect(G_OBJECT(button_5), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_6 = gtk_button_new_with_label("6");
    g_signal_connect(G_OBJECT(button_6), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_7 = gtk_button_new_with_label("7");
    g_signal_connect(G_OBJECT(button_7), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_8 = gtk_button_new_with_label("8");
    g_signal_connect(G_OBJECT(button_8), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_9 = gtk_button_new_with_label("9");
    g_signal_connect(G_OBJECT(button_9), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);

    button_dot = gtk_button_new_with_label(".");
    g_signal_connect(G_OBJECT(button_dot), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_eq = gtk_button_new_with_label("=");
    g_signal_connect(G_OBJECT(button_eq), "clicked",
            G_CALLBACK(on_button_eq_clicked), (gpointer )entry);

    button_sum = gtk_button_new_with_label("+");
    g_signal_connect(G_OBJECT(button_sum), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_minus = gtk_button_new_with_label("-");
    g_signal_connect(G_OBJECT(button_minus), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_ride = gtk_button_new_with_label("*");
    g_signal_connect(G_OBJECT(button_ride), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_divide = gtk_button_new_with_label("/");
    g_signal_connect(G_OBJECT(button_divide), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);

    //创建表格容器
    table = gtk_table_new(4, 4, TRUE);
//  gtk_table_set_row_spacing(GTK_TABLE(table), 4, 5);
//  gtk_table_set_col_spacing(GTK_TABLE(table), 4, 5);

//将各个组件添加到表格窗口
    gtk_table_attach_defaults(GTK_TABLE(table), button_7, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), button_8, 1, 2, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), button_9, 2, 3, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), button_sum, 3, 4, 0, 1);

    gtk_table_attach_defaults(GTK_TABLE(table), button_4, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), button_5, 1, 2, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), button_6, 2, 3, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), button_minus, 3, 4, 1, 2);

    gtk_table_attach_defaults(GTK_TABLE(table), button_1, 0, 1, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), button_2, 1, 2, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), button_3, 2, 3, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), button_ride, 3, 4, 2, 3);

    gtk_table_attach_defaults(GTK_TABLE(table), button_0, 0, 1, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), button_dot, 1, 2, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), button_eq, 2, 3, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), button_divide, 3, 4, 3, 4);

    return table;
}

/** @brief 创建平方开方三角函数等扩展功能
 *
 * @param entry 文本框
 * @return 创建好的表格容器
 */
GtkWidget * create_extends(GtkWidget * entry) {

    //表格容器
    GtkWidget * table;

    //三角函数
    GtkWidget * button_sin;
    GtkWidget * button_cos;
    GtkWidget * button_tan;
    GtkWidget * button_asin;
    GtkWidget * button_acos;
    GtkWidget * button_atan;

    //平方开方
    GtkWidget * button_square; //平方
    GtkWidget * button_cube; //三次方
    GtkWidget * button_sqrt; //开方
    GtkWidget * button_reciprocal; //倒数

    //左右括号
    GtkWidget * button_paren_left;
    GtkWidget * button_paren_right;

    //创建各个组件
    button_sin = gtk_button_new_with_label("sin");
    g_signal_connect(G_OBJECT(button_sin), "clicked", G_CALLBACK(on_button_sin),
            (gpointer )entry);
    button_cos = gtk_button_new_with_label("cos");
    g_signal_connect(G_OBJECT(button_cos), "clicked", G_CALLBACK(on_button_cos),
            (gpointer )entry);
    button_tan = gtk_button_new_with_label("tan");
    g_signal_connect(G_OBJECT(button_tan), "clicked", G_CALLBACK(on_button_tan),
            (gpointer )entry);
    button_asin = gtk_button_new_with_label("asin");
    g_signal_connect(G_OBJECT(button_asin), "clicked",
            G_CALLBACK(on_button_asin), (gpointer )entry);
    button_acos = gtk_button_new_with_label("acos");
    g_signal_connect(G_OBJECT(button_acos), "clicked",
            G_CALLBACK(on_button_acos), (gpointer )entry);
    button_atan = gtk_button_new_with_label("atan");
    g_signal_connect(G_OBJECT(button_atan), "clicked",
                G_CALLBACK(on_button_atan), (gpointer )entry);

    button_reciprocal = gtk_button_new_with_label("1/x");
    g_signal_connect(G_OBJECT(button_reciprocal), "clicked",
            G_CALLBACK(on_button_reciprocal), (gpointer )entry);
    button_square = gtk_button_new_with_label("x^2");
    g_signal_connect(G_OBJECT(button_square), "clicked",
            G_CALLBACK(on_button_square), (gpointer )entry);
    button_cube = gtk_button_new_with_label("x^3");
    g_signal_connect(G_OBJECT(button_cube), "clicked",
            G_CALLBACK(on_button_cube), (gpointer )entry);
    button_sqrt = gtk_button_new_with_label("sqrt(x)");
    g_signal_connect(G_OBJECT(button_sqrt), "clicked",
            G_CALLBACK(on_button_sqrt), (gpointer )entry);

    button_paren_left = gtk_button_new_with_label("(");
    g_signal_connect(G_OBJECT(button_paren_left), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);
    button_paren_right = gtk_button_new_with_label(")");
    g_signal_connect(G_OBJECT(button_paren_right), "clicked",
            G_CALLBACK(on_button_clicked), (gpointer )entry);

    //创建表格容器
    table = gtk_table_new(4, 3, TRUE);

    gtk_table_attach_defaults(GTK_TABLE(table), button_reciprocal, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), button_paren_left, 1, 2, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), button_paren_right, 2, 3, 0, 1);

    gtk_table_attach_defaults(GTK_TABLE(table), button_square, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), button_sin, 1, 2, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), button_asin, 2, 3, 1, 2);

    gtk_table_attach_defaults(GTK_TABLE(table), button_cube, 0, 1, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), button_cos, 1, 2, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), button_acos, 2, 3, 2, 3);

    gtk_table_attach_defaults(GTK_TABLE(table), button_sqrt, 0, 1, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), button_tan, 1, 2, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), button_atan, 2, 3, 3, 4);

    return table;

    return NULL;
}

/** @brief 等于单击
 *
 *
 * @param button
 * @param data 表达式处理器
 */
void on_button_eq_clicked(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    tools_delete_spaces(expression);
    tools_add_zero(expression);
    tools_add_sharp(expression);

    stackPtr stack = stack_create(0);
    bolan_from_exp(expression, stack);

    bolan_inverted(stack);

    double res = bolan_cal(stack);
    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);

}

/** @brief 清除按钮，清除本次数字输入，以便重新输入
 *
 * @param button
 * @param data 表达式处理器
 */
void on_button_clear_clicked(GtkWidget * button, gpointer data) {

    GtkEntry * entry = (GtkEntry*) data;
    gtk_entry_set_text(entry, "");
    for (i = 0; i < 100; i++) {
        expression[i] = '\0';
    }
    i = 0;

}

/** @brief 数字区数字区除 = 之外的按钮单击
 *
 * @param button
 * @param data 文本框
 */
void on_button_clicked(GtkWidget * button, gpointer data) {
    const gchar * num = gtk_button_get_label((GtkButton*) button);
    GtkWidget * entry = (GtkWidget*) data;
    expression[i] = *num;
    i++;
    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief 求倒数
 *
 * @param button
 * @param data
 */
void on_button_reciprocal(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = 1 / res;

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);

}

/** @brief x^2
 *
 * @param button
 * @param data
 */
void on_button_square(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = res * res;

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief x^3
 *
 * @param button
 * @param data
 */
void on_button_cube(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = res * res * res;

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief sqrt(x)
 *
 * @param button
 * @param data
 */
void on_button_sqrt(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = sqrt(res);

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief sin
 *
 * @param button
 * @param data
 */
void on_button_sin(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = sin(3.1415926 * res / 180.0);

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief tan
 *
 * @param button
 * @param data
 */
void on_button_cos(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = cos(3.1415926 * res / 180.0);

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief tan
 *
 * @param button
 * @param data
 */
void on_button_tan(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = tan(3.1415926 * res / 180.0);

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief asin
 *
 * @param button
 * @param data
 */
void on_button_asin(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = asin(res)*180.0/3.141592;

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief acos
 *
 * @param button
 * @param data
 */
void on_button_acos(GtkWidget * button, gpointer data) {
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = acos(res)*180.0/3.141592;

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

/** @brief atan
 *
 * @param button
 * @param data
 */
void on_button_atan(GtkWidget * button, gpointer data){
    GtkWidget * entry = (GtkWidget*) data;
    double res = atof(expression);
    res = atan(res)*180.0/3.141592;

    sprintf(expression, "%lf", res);
    tools_exp_handle_zero(expression);

    gtk_entry_set_text((GtkEntry*) entry, expression);
}

