#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "binarywriter.h"

namespace subsurface
{
    namespace data
    {
        class Serializable
        {
        public:
            void Serialize(BinaryWriter &bw)
            {
            }
        };
    }
}


#endif // SERIALIZABLE_H
