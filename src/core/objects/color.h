#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

namespace subsurface
{
    namespace objects
    {
        class Color
        {
        public:
            Color()
                :red(0), green(0), blue(0), alpha(255)
            {
            }
            Color(int r, int g, int b, int a = 255)
                :red(r), green(g), blue(b), alpha(a)
            {
            }
            int red;
            int green;
            int blue;
            int alpha;
        };
    }

}

#endif // COLOR_H
