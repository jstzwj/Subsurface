#pragma once
#ifndef VOCALSTUDIO_STREAM_STREAM_H
#define VOCALSTUDIO_STREAM_STREAM_H

#include<exception>
#include<cstdint>

#include"StreamBase.h"

namespace subsurface
{
    namespace data
    {
        template <typename T = char, typename Traits = StreamTraits>
        class Stream :public StreamBase<T, Traits>
        {
        public:
            virtual bool isReadable() const override
            {
                return true;
            }
            virtual bool isWriteable() const override
            {
                return true;
            }
        };
	}
}

#endif // !STREAM_STREAM_H
