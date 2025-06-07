#pragma once

#include <emscripten/emscripten.h>
#include <stdlib.h>

#define DECLARE_EM_JS_INLINE(ret, c_name, params)                          \
  ret c_name params EM_IMPORT(c_name);                                            \
  EMSCRIPTEN_KEEPALIVE                                                             \
  __attribute__((section("em_js"), aligned(1))) extern char __em_js__##c_name[];


/////////////////////////////////// Interface //////////////////////////////////

typedef void (*upload_handler)(const char*, const char*, const void* buffer, size_t buffer_len, void*);

///////////////////////////////// Implementation ///////////////////////////////

DECLARE_EM_JS_INLINE(void, emscripten_upload, (char const *accept_types, upload_handler callback, void *callback_data));
DECLARE_EM_JS_INLINE(void, emscripten_download, (char const *filename, char const *mime_type, void const *buffer, size_t buffer_size));


// EMSCRIPTEN_KEEPALIVE inline int upload_file_return(char const *filename, char const *mime_type, char *buffer, size_t buffer_size, upload_handler callback, void *callback_data);

EMSCRIPTEN_KEEPALIVE int upload_file_return(char const *filename, char const *mime_type, char *buffer, size_t buffer_size, upload_handler callback, void *callback_data);
