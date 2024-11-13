#ifndef __LV_MAINSTART_H
#define __LV_MAINSTART_H

#include "gui_guider.h"
#include "events_init.h"


void lv_mainstart(void);

void lv_example_btn_1(void);

void physical_button_pressed(void);

void lv_display_button_init(void);


void lv_port_indev_init(void) ;

void check_button_state(void);

void update_works_time(lv_ui *ui);


#endif
