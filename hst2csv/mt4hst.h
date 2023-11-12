#pragma once

#include <cstdint>

#pragma pack(push, 1)

namespace mt4::hst
{
    using datetime32 = std::int32_t;

    struct header
    {
        std::int32_t version;
        char copyright[64];
        char symbol[12];
        std::int32_t period;
        std::int32_t digits;
        datetime32 timesign;
        datetime32 lastsync;
        std::int32_t unused[13];
    };

    struct record400
    {
        datetime32 ctm;
        double open;
        double low;
        double high;
        double close;
        double volume; 
    };

    using datetime64 = std::int64_t;

    struct record401
    {
        datetime64 ctm;
        double open;
        double high;
        double low;
        double close;
        std::int64_t volume;
        std::int32_t spread;
        std::int64_t real_volume;
    };
}

#pragma pack(pop)
