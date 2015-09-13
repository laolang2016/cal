#include <gtk/gtk.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"../../include/frame.h"
#include"../../include/frame.h"


//处理中文乱码
char *_(char * c) {
    return g_convert(c, -1, "UTF-8", "GB2312", NULL, NULL, NULL);
}





int main(int argc, char *argv[]) {
    //主窗体
    GtkWidget *window;
    //主容器
    GtkWidget * vbox_contain;
    //清除按钮和标签容器
    GtkWidget * hbox_top;
    //标签
    GtkWidget * label;
    //清除按钮
    GtkWidget * button_clear;
    //显示输入和结果
    GtkWidget * entry;
    //主功能区容器
    GtkWidget * hbox_buttom;
    //数字区表格容器
    GtkWidget * table;
    //扩展功能表格容器
    GtkWidget * table_extends;


    gtk_init(&argc, &argv);

    //主窗体
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "cal gtk 003");
    gtk_window_set_default_size(GTK_WINDOW(window), 370, 220);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //主容器
    vbox_contain = gtk_vbox_new( FALSE, 0);
    gtk_container_set_border_width(GTK_CONTAINER(vbox_contain), 3);
    gtk_container_add(GTK_CONTAINER(window), vbox_contain);

    //上半部窗口
    hbox_top = gtk_hbox_new( FALSE, 0);
    label = gtk_label_new("计算器--gtk003");
    button_clear = gtk_button_new_with_label("清除");

    gtk_box_pack_start(GTK_BOX(hbox_top), label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox_top), button_clear, FALSE, FALSE, 10);

    gtk_box_pack_start(GTK_BOX(vbox_contain), hbox_top, FALSE, FALSE, 3);

    //显示框
    entry = gtk_entry_new();
    //设置显示框从右向左显示
    gtk_box_pack_start(GTK_BOX(vbox_contain), entry, FALSE, FALSE, 3);

    g_signal_connect(G_OBJECT(button_clear), "clicked",
            G_CALLBACK(on_button_clear_clicked), (gpointer )entry);

    //下半部分主功能区
    hbox_buttom = gtk_hbox_new( FALSE, 0);
    table = create_table(entry);
    table_extends = create_extends(entry);
    gtk_box_pack_start(GTK_BOX(hbox_buttom), table_extends, FALSE, FALSE, 3);
    gtk_box_pack_start(GTK_BOX(hbox_buttom), table, TRUE, TRUE, 3);

    gtk_box_pack_start(GTK_BOX(vbox_contain), hbox_buttom, FALSE, FALSE, 3);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

