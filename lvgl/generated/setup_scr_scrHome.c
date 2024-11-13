/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
//#include "custom.h"



void setup_scr_scrHome(lv_ui *ui)
{
    //Write codes scrHome
    ui->scrHome = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrHome, 320, 240);
    lv_obj_set_scrollbar_mode(ui->scrHome, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrHome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_img_1
    ui->scrHome_img_1 = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_img_1, &_s07_bg_same_16bit_alpha_320x240);
    lv_img_set_pivot(ui->scrHome_img_1, 50,50);
    lv_img_set_angle(ui->scrHome_img_1, 0);
    lv_obj_set_pos(ui->scrHome_img_1, 0, 0);
    lv_obj_set_size(ui->scrHome_img_1, 320, 240);

    //Write style for scrHome_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrHome_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrHome_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrHome_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_wifi_label
    ui->scrHome_wifi_label = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_wifi_label, "" LV_SYMBOL_WIFI " ");
    lv_label_set_long_mode(ui->scrHome_wifi_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_wifi_label, 9, 11);
    lv_obj_set_size(ui->scrHome_wifi_label, 41, 23);

    //Write style for scrHome_wifi_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_wifi_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_wifi_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_wifi_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_wifi_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_wifi_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_timerNumbers
    ui->scrHome_timerNumbers = lv_spangroup_create(ui->scrHome);
    lv_spangroup_set_align(ui->scrHome_timerNumbers, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->scrHome_timerNumbers, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->scrHome_timerNumbers, LV_SPAN_MODE_BREAK);
    //create span
    ui->scrHome_timerNumbers_span = lv_spangroup_new_span(ui->scrHome_timerNumbers);
    lv_span_set_text(ui->scrHome_timerNumbers_span, "  12:20");
    lv_style_set_text_color(&ui->scrHome_timerNumbers_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->scrHome_timerNumbers_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->scrHome_timerNumbers_span->style, &lv_font_montserratMedium_18);
    lv_obj_set_pos(ui->scrHome_timerNumbers, 59, 189);
    lv_obj_set_size(ui->scrHome_timerNumbers, 65, 19);

    //Write style state: LV_STATE_DEFAULT for &style_scrHome_timerNumbers_main_main_default
    static lv_style_t style_scrHome_timerNumbers_main_main_default;
    ui_init_style(&style_scrHome_timerNumbers_main_main_default);

    lv_style_set_border_width(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_style_set_radius(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_style_set_bg_opa(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_style_set_pad_top(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_style_set_pad_right(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_style_set_pad_bottom(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_style_set_pad_left(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_style_set_shadow_width(&style_scrHome_timerNumbers_main_main_default, 0);
    lv_obj_add_style(ui->scrHome_timerNumbers, &style_scrHome_timerNumbers_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->scrHome_timerNumbers);

    //Write codes scrHome_humidityNumbers
    ui->scrHome_humidityNumbers = lv_spangroup_create(ui->scrHome);
    lv_spangroup_set_align(ui->scrHome_humidityNumbers, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->scrHome_humidityNumbers, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->scrHome_humidityNumbers, LV_SPAN_MODE_BREAK);
    //create span
    ui->scrHome_humidityNumbers_span = lv_spangroup_new_span(ui->scrHome_humidityNumbers);
    lv_span_set_text(ui->scrHome_humidityNumbers_span, "49");
    lv_style_set_text_color(&ui->scrHome_humidityNumbers_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->scrHome_humidityNumbers_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->scrHome_humidityNumbers_span->style, &lv_font_montserratMedium_42);
    lv_obj_set_pos(ui->scrHome_humidityNumbers, 209, 45);
    lv_obj_set_size(ui->scrHome_humidityNumbers, 58, 45);

    //Write style state: LV_STATE_DEFAULT for &style_scrHome_humidityNumbers_main_main_default
    static lv_style_t style_scrHome_humidityNumbers_main_main_default;
    ui_init_style(&style_scrHome_humidityNumbers_main_main_default);

    lv_style_set_border_width(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_style_set_radius(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_style_set_bg_opa(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_style_set_pad_top(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_style_set_pad_right(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_style_set_pad_bottom(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_style_set_pad_left(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_style_set_shadow_width(&style_scrHome_humidityNumbers_main_main_default, 0);
    lv_obj_add_style(ui->scrHome_humidityNumbers, &style_scrHome_humidityNumbers_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->scrHome_humidityNumbers);

    //Write codes scrHome_tempNumbers
    ui->scrHome_tempNumbers = lv_spangroup_create(ui->scrHome);
    lv_spangroup_set_align(ui->scrHome_tempNumbers, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->scrHome_tempNumbers, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->scrHome_tempNumbers, LV_SPAN_MODE_BREAK);
    //create span
    ui->scrHome_tempNumbers_span = lv_spangroup_new_span(ui->scrHome_tempNumbers);
    lv_span_set_text(ui->scrHome_tempNumbers_span, "35");
    lv_style_set_text_color(&ui->scrHome_tempNumbers_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->scrHome_tempNumbers_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->scrHome_tempNumbers_span->style, &lv_font_montserratMedium_42);
    lv_obj_set_pos(ui->scrHome_tempNumbers, 209, 154);
    lv_obj_set_size(ui->scrHome_tempNumbers, 53, 38);

    //Write style state: LV_STATE_DEFAULT for &style_scrHome_tempNumbers_main_main_default
    static lv_style_t style_scrHome_tempNumbers_main_main_default;
    ui_init_style(&style_scrHome_tempNumbers_main_main_default);

    lv_style_set_border_width(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_style_set_radius(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_style_set_bg_opa(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_style_set_pad_top(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_style_set_pad_right(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_style_set_pad_bottom(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_style_set_pad_left(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_style_set_shadow_width(&style_scrHome_tempNumbers_main_main_default, 0);
    lv_obj_add_style(ui->scrHome_tempNumbers, &style_scrHome_tempNumbers_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->scrHome_tempNumbers);

    //Write codes scrHome_dataNumbers
    ui->scrHome_dataNumbers = lv_spangroup_create(ui->scrHome);
    lv_spangroup_set_align(ui->scrHome_dataNumbers, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->scrHome_dataNumbers, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->scrHome_dataNumbers, LV_SPAN_MODE_BREAK);
    //create span
    ui->scrHome_dataNumbers_span = lv_spangroup_new_span(ui->scrHome_dataNumbers);
    lv_span_set_text(ui->scrHome_dataNumbers_span, "11月13日 星期三");
    lv_style_set_text_color(&ui->scrHome_dataNumbers_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->scrHome_dataNumbers_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->scrHome_dataNumbers_span->style, &lv_font_SourceHanSerifSC_Regular_14);
    lv_obj_set_pos(ui->scrHome_dataNumbers, 36, 116);
    lv_obj_set_size(ui->scrHome_dataNumbers, 110, 18);

    //Write style state: LV_STATE_DEFAULT for &style_scrHome_dataNumbers_main_main_default
    static lv_style_t style_scrHome_dataNumbers_main_main_default;
    ui_init_style(&style_scrHome_dataNumbers_main_main_default);

    lv_style_set_border_width(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_style_set_radius(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_style_set_bg_opa(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_style_set_pad_top(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_style_set_pad_right(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_style_set_pad_bottom(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_style_set_pad_left(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_style_set_shadow_width(&style_scrHome_dataNumbers_main_main_default, 0);
    lv_obj_add_style(ui->scrHome_dataNumbers, &style_scrHome_dataNumbers_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->scrHome_dataNumbers);

    //Write codes scrHome_hourNumbers
    ui->scrHome_hourNumbers = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_hourNumbers, "00");
    lv_label_set_long_mode(ui->scrHome_hourNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_hourNumbers, 9, 51);
    lv_obj_set_size(ui->scrHome_hourNumbers, 76, 46);

    //Write style for scrHome_hourNumbers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_hourNumbers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_hourNumbers, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_hourNumbers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_hourNumbers, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_hourNumbers, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_hourNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_timeColon
    ui->scrHome_timeColon = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_timeColon, ":");
    lv_label_set_long_mode(ui->scrHome_timeColon, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_timeColon, 75, 51);
    lv_obj_set_size(ui->scrHome_timeColon, 28, 40);

    //Write style for scrHome_timeColon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_timeColon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_timeColon, &lv_font_montserratMedium_42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_timeColon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_timeColon, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_timeColon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_timeColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_minuteNumbers
    ui->scrHome_minuteNumbers = lv_spangroup_create(ui->scrHome);
    lv_spangroup_set_align(ui->scrHome_minuteNumbers, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->scrHome_minuteNumbers, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->scrHome_minuteNumbers, LV_SPAN_MODE_BREAK);
    //create span
    ui->scrHome_minuteNumbers_span = lv_spangroup_new_span(ui->scrHome_minuteNumbers);
    lv_span_set_text(ui->scrHome_minuteNumbers_span, "00");
    lv_style_set_text_color(&ui->scrHome_minuteNumbers_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->scrHome_minuteNumbers_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->scrHome_minuteNumbers_span->style, &lv_font_montserratMedium_50);
    lv_obj_set_pos(ui->scrHome_minuteNumbers, 94, 51);
    lv_obj_set_size(ui->scrHome_minuteNumbers, 83, 44);

    //Write style state: LV_STATE_DEFAULT for &style_scrHome_minuteNumbers_main_main_default
    static lv_style_t style_scrHome_minuteNumbers_main_main_default;
    ui_init_style(&style_scrHome_minuteNumbers_main_main_default);

    lv_style_set_border_width(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_style_set_radius(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_style_set_bg_opa(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_style_set_pad_top(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_style_set_pad_right(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_style_set_pad_bottom(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_style_set_pad_left(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_style_set_shadow_width(&style_scrHome_minuteNumbers_main_main_default, 0);
    lv_obj_add_style(ui->scrHome_minuteNumbers, &style_scrHome_minuteNumbers_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->scrHome_minuteNumbers);

    //The custom code of scrHome.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrHome);

    //Init events for screen.
    events_init_scrHome(ui);
}
