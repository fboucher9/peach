// See LICENSE for license details
#ifndef peach_stdin_h_
#define peach_stdin_h_
#include <peach_object.h>
extern "C" {
#include <cv_algo/cv_array.h>
}
struct peach_stdin : public peach_object {
    static size_t s_read(cv_array const & r_buffer);
    static bool s_read_char(unsigned char * r_uchar);
    static size_t s_read_line(cv_array const & r_buffer);
};
#endif // #ifndef peach_stdin_h_
