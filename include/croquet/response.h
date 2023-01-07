#pragma once
#include <interface99.h>

#define Respondable_IFACE \
    vfunc(char *, into_buf, const VSelf)

interface(Respondable);