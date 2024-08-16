/**
 * @file my_gui.h
 *
 */

#ifndef MY_GUI_H
#define MY_GUI_H

#ifdef __cplusplus
extern "C"
{
#endif
/*********************
 *      include
 *********************/
#include <stdio.h>
#include "lvgl/lvgl.h"
    /*********************
     *      define
     *********************/

    /**********************
     *      宏定义
     **********************/

    /**********************
     *      类型定义
     **********************/

    /**********************
     *     全局函数
     **********************/
    void my_gui_run(void);

    /**********************
     *     静态函数
     **********************/
    static void demo_label(void);
    static void lv_obj_demo2(void);
    static void lv_obj_demo1(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* my_gui.h */
