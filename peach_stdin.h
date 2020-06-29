// See LICENSE for license details
#ifndef peach_stdin_h_
#define peach_stdin_h_
#include <peach_object.h>
#include <peach_buffer.h>
struct peach_stdin : public peach_object {
    static size_t s_read(peach_buffer const & r_buffer);
    static bool s_read_char(unsigned char * r_uchar);
    static size_t s_read_line(peach_buffer const & r_buffer);
};
#endif // #ifndef peach_stdin_h_
