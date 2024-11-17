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

    //Write codes scrHome_backGround
    ui->scrHome_backGround = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_backGround, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_backGround, &_s07_bg_same_16bit_alpha_320x240);
    lv_img_set_pivot(ui->scrHome_backGround, 50,50);
    lv_img_set_angle(ui->scrHome_backGround, 0);
    lv_obj_set_pos(ui->scrHome_backGround, 0, 0);
    lv_obj_set_size(ui->scrHome_backGround, 320, 240);

    //Write style for scrHome_backGround, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrHome_backGround, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrHome_backGround, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_backGround, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrHome_backGround, true, LV_PART_MAIN|LV_STATE_DEFAULT);

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
    ui->scrHome_minuteNumbers = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_minuteNumbers, "00");
    lv_label_set_long_mode(ui->scrHome_minuteNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_minuteNumbers, 94, 51);
    lv_obj_set_size(ui->scrHome_minuteNumbers, 72, 44);

    //Write style for scrHome_minuteNumbers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_minuteNumbers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_minuteNumbers, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_minuteNumbers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_minuteNumbers, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_minuteNumbers, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_minuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_wifiIcon
    ui->scrHome_wifiIcon = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_wifiIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_wifiIcon, &_wifi_symbol_black_alpha_22x17);
    lv_img_set_pivot(ui->scrHome_wifiIcon, 50,50);
    lv_img_set_angle(ui->scrHome_wifiIcon, 0);
    lv_obj_set_pos(ui->scrHome_wifiIcon, 15, 10);
    lv_obj_set_size(ui->scrHome_wifiIcon, 22, 17);

    //Write style for scrHome_wifiIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrHome_wifiIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrHome_wifiIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_wifiIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrHome_wifiIcon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_dryIcon
    ui->scrHome_dryIcon = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_dryIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_dryIcon, &_dry_black_2_alpha_22x17);
    lv_img_set_pivot(ui->scrHome_dryIcon, 50,50);
    lv_img_set_angle(ui->scrHome_dryIcon, 0);
    lv_obj_set_pos(ui->scrHome_dryIcon, 48, 10);
    lv_obj_set_size(ui->scrHome_dryIcon, 22, 17);

    //Write style for scrHome_dryIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrHome_dryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrHome_dryIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_dryIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrHome_dryIcon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_plasmaIcon
    ui->scrHome_plasmaIcon = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_plasmaIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_plasmaIcon, &_plasma_black_2_alpha_22x17);
    lv_img_set_pivot(ui->scrHome_plasmaIcon, 50,50);
    lv_img_set_angle(ui->scrHome_plasmaIcon, 0);
    lv_obj_set_pos(ui->scrHome_plasmaIcon, 81, 10);
    lv_obj_set_size(ui->scrHome_plasmaIcon, 22, 17);

    //Write style for scrHome_plasmaIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrHome_plasmaIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrHome_plasmaIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_plasmaIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrHome_plasmaIcon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_mouseIcon
    ui->scrHome_mouseIcon = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_mouseIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_mouseIcon, &_mouse_black_alpha_22x17);
    lv_img_set_pivot(ui->scrHome_mouseIcon, 50,50);
    lv_img_set_angle(ui->scrHome_mouseIcon, 0);
    lv_obj_set_pos(ui->scrHome_mouseIcon, 112, 10);
    lv_obj_set_size(ui->scrHome_mouseIcon, 22, 17);

    //Write style for scrHome_mouseIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrHome_mouseIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrHome_mouseIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_mouseIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrHome_mouseIcon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_timerHoursNumbers
    ui->scrHome_timerHoursNumbers = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_timerHoursNumbers, "00");
    lv_label_set_long_mode(ui->scrHome_timerHoursNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_timerHoursNumbers, 51, 189);
    lv_obj_set_size(ui->scrHome_timerHoursNumbers, 34, 13);

    //Write style for scrHome_timerHoursNumbers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_timerHoursNumbers, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_timerHoursNumbers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_timerHoursNumbers, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_timerHoursNumbers, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_timerHoursNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_humidityNumber
    ui->scrHome_humidityNumber = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_humidityNumber, "00");
    lv_label_set_long_mode(ui->scrHome_humidityNumber, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_humidityNumber, 194, 41);
    lv_obj_set_size(ui->scrHome_humidityNumber, 71, 45);

    //Write style for scrHome_humidityNumber, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_humidityNumber, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_humidityNumber, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_humidityNumber, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_humidityNumber, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_humidityNumber, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_humidityNumber, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_tempNumbers
    ui->scrHome_tempNumbers = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_tempNumbers, "00");
    lv_label_set_long_mode(ui->scrHome_tempNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_tempNumbers, 194, 148);
    lv_obj_set_size(ui->scrHome_tempNumbers, 71, 45);

    //Write style for scrHome_tempNumbers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_tempNumbers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_tempNumbers, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_tempNumbers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_tempNumbers, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_tempNumbers, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_tempNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_dataNumbers
    ui->scrHome_dataNumbers = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_dataNumbers, "11月15号 星期五");
    lv_label_set_long_mode(ui->scrHome_dataNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_dataNumbers, 23, 113);
    lv_obj_set_size(ui->scrHome_dataNumbers, 129, 17);

    //Write style for scrHome_dataNumbers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_dataNumbers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_dataNumbers, &lv_font_SourceHanSerifSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_dataNumbers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_dataNumbers, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_dataNumbers, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_dataNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_timerColon
    ui->scrHome_timerColon = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_timerColon, ":");
    lv_label_set_long_mode(ui->scrHome_timerColon, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_timerColon, 85, 186);
    lv_obj_set_size(ui->scrHome_timerColon, 12, 19);

    //Write style for scrHome_timerColon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_timerColon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_timerColon, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_timerColon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_timerColon, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_timerColon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_timerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHome_timerMinuteNumbers
    ui->scrHome_timerMinuteNumbers = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_timerMinuteNumbers, "00");
    lv_label_set_long_mode(ui->scrHome_timerMinuteNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_timerMinuteNumbers, 97, 189);
    lv_obj_set_size(ui->scrHome_timerMinuteNumbers, 33, 14);

    //Write style for scrHome_timerMinuteNumbers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHome_timerMinuteNumbers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHome_timerMinuteNumbers, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHome_timerMinuteNumbers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHome_timerMinuteNumbers, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHome_timerMinuteNumbers, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHome_timerMinuteNumbers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrHome.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrHome);

}
