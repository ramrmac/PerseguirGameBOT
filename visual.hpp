#ifndef _VISION_HPP_
#define _VISION_HPP_

#include <allegro.h>

int long rsp();
void isp1();

class VISUAL{
public:
    BITMAP*LIENZO;

    VISUAL();
    const virtual ~VISUAL();
    void accion();
};

#endif // _VISION_HPP_
