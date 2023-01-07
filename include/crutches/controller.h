#pragma once
#include <metalang99.h>
#include <interface99.h>
#include <string.h>
#include "response.h"

typedef Respondable (*Responder)();

#define streq !strcmp

#define Controller_IFACE \
    vfunc(Responder, respond, const VSelf, const char *)

interface(Controller);

#define __routeHandler_IMPL(controllerName, tuple) ML99_TERMS( \
    ML99_invoke(v(if), ML99_invoke(v(streq), v(path), ML99_stringify(ML99_tupleGet(0)(tuple)))), \
        ML99_braced(ML99_tupleGet(1)(tuple)))
#define __routeHandler__ARITY 2

#define _controller_IMPL(name, ...) ML99_TERMS( \
    ML99_typedef(v(name), v(struct { char dummy; })), \
    v(void name##_respond(const VSelf, const char *path)), \
    ML99_braced(ML99_variadicsForEach(ML99_appl(v(__routeHandler), v(name)), v(__VA_ARGS__))), \
    IFACE99_impl_IMPL(Controller, name))

#define _controller(name, ...) ML99_EVAL(ML99_call(_controller, v(name), v(__VA_ARGS__)))