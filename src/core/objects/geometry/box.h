#ifndef BOX_H
#define BOX_H

#include <cstdint>
#include "../geometry.h"

namespace subsurface
{
    namespace scence
    {
        class Box : public Geometry
        {
        public:
            Box();

        private:
            double length;
            double width;
            double height;

            std::int32_t lengthSegs;
            std::int32_t widthSegs;
            std::int32_t heightSegs;
        };

    }
}


#endif // BOX_H
