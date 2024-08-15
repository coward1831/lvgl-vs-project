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
    // #include "lvgl/demos/lv_demos.h"
    // #include "lvgl/examples/lv_examples.h"

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
    static void lv_obj_demo2(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* my_gui.h */
