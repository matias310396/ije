#ifndef COLOR
#define COLOR

namespace engine{

    struct Color
    {
        unsigned char r, g, b, a;
        Color(unsigned char _r=0x00, unsigned char _g=0x00,
                unsigned char _b=0x00, unsigned char _a=0x00)
                :r(_r), g(_g), b(_b), a(_a){}
    };

}

#endif