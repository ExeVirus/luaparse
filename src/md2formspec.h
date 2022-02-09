#ifndef MD2FORMSPEC_H
#define MD2FORMSPEC_H

#include "md4c/md4c.h"

#ifdef __cplusplus
    extern "C" {
#endif

static int enter_block_callback(MD_BLOCKTYPE type, void* detail, void* userdata) {

    switch (type) {
        case MD_BLOCK_H:   printf("%i\n", ((MD_BLOCK_H_DETAIL*)detail)->level); break;
    }

    return 0;
};

static int leave_block_callback(MD_BLOCKTYPE type, void* detail, void* userdata) { return 0; };
static int enter_span_callback(MD_SPANTYPE type, void* detail, void* userdata) { return 0; };
static int leave_span_callback(MD_SPANTYPE type, void* detail, void* userdata) { return 0; };
static void debug_log_callback(const char* msg, void* userdata) {};
static int text_callback(MD_TEXTTYPE type, const MD_CHAR* text, MD_SIZE size, void* userdata)
{
    switch (type) {
    default:         printf("%.*s\n", size, text); break;
    }

    return 0;
}

MD_PARSER md2f = {
        0,
        MD_DIALECT_GITHUB,
        enter_block_callback,
        leave_block_callback,
        enter_span_callback,
        leave_span_callback,
        text_callback,
        debug_log_callback,
        NULL
};

#ifdef __cplusplus
    }  /* extern "C" { */
#endif

#endif  /* MD2FORMSPEC_H */