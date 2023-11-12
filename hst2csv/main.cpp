#include <cstdio>
#include <cerrno>
#include <cstring>
#include <cinttypes>
#include <ctime>
#include <cassert>

#include "mt4hst.h"

static
void format_ctm(const mt4::hst::datetime64 ctm, char date[], char time[])
{
    assert(date);
    assert(time);

    struct tm* tm = gmtime(&ctm);

    sprintf(
        date,
        "%04d%02d%02d",
        tm->tm_year + 1900,
        tm->tm_mon + 1,
        tm->tm_mday
    );

    sprintf(
        time,
        "%02d%02d%02d",
        tm->tm_hour,
        tm->tm_min,
        tm->tm_sec
    );
}

int main(int argc, char* argv[])
{
    if(2 > argc)
    {
        fprintf(stderr, "Usage: %s hstfile\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];

    FILE* file = fopen(filename, "rb");

    if(nullptr == file)
    {
        fprintf(stderr, "ERROR: Failed to open the file '%s' (errno=%d, errstr='%s')\n", filename, errno, std::strerror(errno));
        return -1;
    }

    mt4::hst::header header{};

    const size_t fread_result = fread(&header, sizeof(header), 1, file);

    if(1 != fread_result)
    {
        fprintf(stderr, "ERROR: Failed to read the header from the file '%s'. (errno=%d, errstr='%s')\n", filename, errno, std::strerror(errno));
        fclose(file);
        return -2;
    }

    while(true)
    {
        mt4::hst::record401 record{};

        const size_t fread_result = fread(&record, sizeof(record), 1, file);

        if(1 != fread_result)
        {
            if(ferror(file))
            {
                fprintf(stderr, "ERROR: Failed to read a record from the file '%s'. (errno=%d, errstr='%s')\n", filename, errno, std::strerror(errno));
                fclose(file);
                return -3;
            }

            if(feof(file))
            {
                break;
            }
        }

        char date[] = "yyyymmdd";
        char time[] = "hhmmss";

        format_ctm(record.ctm, date, time);

        fprintf(
            stdout,
            "%s,%s,%.*f,%.*f,%.*f,%.*f,%" PRId64 ",%" PRId32 ",%" PRId64 "\n",
            date,
            time,
            header.digits,
            record.open,
            header.digits,
            record.high,
            header.digits,
            record.low,
            header.digits,
            record.close,
            record.volume,
            record.spread,
            record.real_volume
        );
    }

    fclose(file);

    return 0;
}
