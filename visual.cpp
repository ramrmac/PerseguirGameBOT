#include "visual.hpp"

volatile long sp=0;

int long rsp(){
    return sp;
}

void isp(){
    sp++;
}

void isp1(){
    sp--;
}

END_OF_FUNCTION(isp);

VISUAL::VISUAL(){
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	show_mouse(screen);
	LOCK_VARIABLE(sp);
	install_int_ex(isp,BPS_TO_TIMER(180));
    LIENZO=create_bitmap(SCREEN_W,SCREEN_H);
	/* add other initializations here */
}

const VISUAL::~VISUAL(){
	clear_keybuf();
	delete this->LIENZO;
}

void VISUAL::accion(){
    draw_sprite(screen,LIENZO,0,0);
    clear_to_color(LIENZO,0x000000);
    isp1();
}
