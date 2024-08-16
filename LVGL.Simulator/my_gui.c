/**
 * @file my_gui.c
 *
 */

/*********************
 *      include
 *********************/
#include "my_gui.h"

/*********************
 *      define
 *********************/

/**********************
 *  定义类型（枚举、结构体）
 **********************/

/**********************
 *     静态函数（内部可调用，外部不可调用）
 **********************/

/**********************
 *     静态变量
 **********************/

/**********************
 *      宏定义
 **********************/

/**********************
 *     全局函数
 **********************/
void my_gui_run(void)
{
    demo_label();
}

/**********************
 *     静态函数
 **********************/

static void slider_event_cb(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target(e);
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *screen1 = lv_obj_get_parent(slider);
    lv_obj_t *slider_label = lv_obj_get_child(screen1, 1);
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        lv_label_set_text_fmt(slider_label, "#ff0000 value:# #000000 %d#", lv_slider_get_value(slider));
    }
}

static void demo_label(void)
{
    /*   屏幕   */
    lv_obj_t *screen1 = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_size(screen1, 600, 400);

    /*   滑动条  */
    lv_obj_t *slider = lv_slider_create(screen1, NULL);
    lv_obj_align(slider, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_size(slider, 100, 20);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    /*   标签  */
    lv_obj_t *slider_label = lv_label_create(screen1, NULL);
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 20, 0); // 右对齐
    lv_label_set_recolor(slider_label, true);                             // 标签颜色变化
    // 设置标签的背景颜色和文本颜色
    lv_obj_set_style_bg_color(slider_label, lv_color_hex(0xffffff), LV_STATE_DEFAULT);   // 白色背景
    lv_obj_set_style_text_color(slider_label, lv_color_hex(0x000000), LV_STATE_DEFAULT); // 黑色文本
    lv_obj_set_style_bg_opa(slider_label, LV_OPA_COVER, LV_STATE_DEFAULT);               // 如果没有该语句，则会没有显示背景颜色
    lv_label_set_text_fmt(slider_label, "#ff0000 value:# #000000 %d#", lv_slider_get_value(slider));

    /* 标签案例学习 */
    lv_obj_t *label1 = lv_label_create(screen1, NULL);
    lv_obj_align(label1, LV_ALIGN_TOP_MID, 0, 50);
    lv_obj_set_size(label1, 80, 20);
    lv_label_set_recolor(label1, true);
    lv_obj_set_style_text_color(label1, lv_color_hex(0xff0000), LV_STATE_DEFAULT);
    lv_label_set_text(label1, "hello lvgl, this is a label.");
    lv_label_set_long_mode(label1, LV_LABEL_LONG_SCROLL_CIRCULAR); // 循环滚动
}

static - void lv_obj_demo1(void)
{
}