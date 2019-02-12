#include "gtms.h"

int main(int argc, char* argv[])
{
    char s[] = "ala ma kota";

    gtms::send_to_mainpro(s, sizeof(s));

    return 0;
}

