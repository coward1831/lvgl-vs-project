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
    lv_obj_demo2();
}

/**********************
 *     静态函数
 **********************/
static lv_obj_t *bar1;
static lv_obj_t *label1;
static int charge_value = 0;
static lv_timer_t *charge_timer = NULL;

// 定义一个函数来处理定时器事件
static void charge_timer_cb(lv_timer_t *timer)
{
    if (charge_value < 100)
    {
        charge_value++;
        lv_bar_set_value(bar1, charge_value, LV_ANIM_OFF);
        lv_label_set_text_fmt(label1, "%d", charge_value);

        // 根据进度条的值计算指示器颜色
        uint8_t red = (uint8_t)(charge_value * 2.55);           // 从 0 到 255
        uint8_t green = (uint8_t)((100 - charge_value) * 2.55); // 从 255 到 0
        uint8_t blue = 0;                                       // 固定为 0
        lv_color_t indicator_color = LV_COLOR_MAKE(red, green, blue);
        lv_obj_set_style_bg_color(bar1, indicator_color, LV_PART_INDICATOR);
    }
    else
    {
        lv_timer_del(timer);
        charge_timer = NULL;
    }
}

// 定义一个函数来处理按钮事件
static void btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_PRESSED)
    {
        // 按下按钮时，启动定时器
        if (charge_timer == NULL)
        {
            charge_timer = lv_timer_create(charge_timer_cb, 100, NULL);
        }
    }
    else if (code == LV_EVENT_RELEASED)
    {
        // 松开按钮时，停止定时器
        if (charge_timer != NULL)
        {
            lv_timer_del(charge_timer);
            charge_timer = NULL;
        }
    }
}

static void lv_obj_demo2(void)
{
    // 创建一个覆盖整个屏幕的基础对象 screen1
    lv_obj_t *screen1 = lv_obj_create(lv_scr_act());
    // 设置 screen1 的大小为屏幕大小
    lv_obj_set_size(screen1, LV_HOR_RES, LV_VER_RES);

    // 创建一个进度条对象 bar1，并将其添加到 screen1 上
    bar1 = lv_bar_create(screen1);
    // 设置 bar1 的大小为 200x20 像素
    lv_obj_set_size(bar1, 200, 20);
    // 将 bar1 对齐到 screen1 的中心
    lv_obj_set_align(bar1, LV_ALIGN_CENTER);
    // 设置 bar1 的初始值为 0
    lv_bar_set_value(bar1, charge_value, LV_ANIM_OFF);

    // 设置 bar1 的样式
    lv_obj_set_style_bg_color(bar1, lv_color_hex(0xCCCCCC), LV_PART_MAIN);      // 设置背景颜色
    lv_obj_set_style_bg_color(bar1, lv_color_hex(0x007ACC), LV_PART_INDICATOR); // 设置指示器颜色

    // 创建一个标签对象 label1，并将其添加到 screen1 上
    label1 = lv_label_create(screen1);
    // 设置 label1 的文本为当前充电值
    lv_label_set_text_fmt(label1, "%d", charge_value);
    // 将 label1 对齐到 bar1 的右边，并偏移 20 像素
    lv_obj_align(label1, LV_ALIGN_CENTER, 120, 0);

    // 创建一个按钮对象 btn1，并将其添加到 screen1 上
    lv_obj_t *btn1 = lv_btn_create(screen1);
    // 设置 btn1 的大小为 100x50 像素
    lv_obj_set_size(btn1, 100, 50);
    // 将 btn1 对齐到 screen1 的中心，并偏移 0, 40 像素
    lv_obj_set_align(btn1, LV_ALIGN_CENTER);
    lv_obj_set_y(btn1, 40);

    // 为 btn1 添加事件回调函数
    lv_obj_add_event_cb(btn1, btn_event_cb, LV_EVENT_ALL, NULL);
}
