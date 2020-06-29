// See LICENSE for license details
#include <peach_stdin.h>
extern "C" {
#include <cv_file/cv_file.h>
#include <cv_file/cv_file_std.h>
}
size_t peach_stdin::s_read(cv_array const & r_buffer) {
    size_t i_result = 0;
    cv_sptr const i_read_result = cv_file_read(cv_file_std_in(), &r_buffer);
    if (i_read_result > 0) {
        i_result = i_read_result & 0x7fffffffL;
    }
    return i_result;
}
bool peach_stdin::s_read_char(unsigned char * r_uchar) {
    static unsigned char g_cache[32u] = {0};
    static size_t g_cache_offset = 0;
    static size_t g_cache_len = 0;
    bool b_result = false;
    if (!g_cache_len) {
        cv_array o_buffer;
        cv_array_init_vector(&o_buffer, g_cache, sizeof(g_cache));
        g_cache_offset = 0;
        g_cache_len = peach_stdin::s_read(o_buffer);
        cv_array_cleanup(&o_buffer);
    }
    if (g_cache_len) {
        *r_uchar = g_cache[g_cache_offset];
        g_cache_offset ++;
        g_cache_len --;
        b_result = true;
    }
    return b_result;
}
size_t peach_stdin::s_read_line(cv_array const & r_buffer) {
    size_t i_line_len = 0;
    bool b_continue = true;
    while (b_continue) {
        unsigned char c_data;
        if (s_read_char(&c_data)) {
            if ((r_buffer.o_min.p_uchar + i_line_len) <
                r_buffer.o_max.p_uchar) {
                r_buffer.o_min.p_uchar[i_line_len] = c_data;
                i_line_len ++;
                if ('\n' == c_data) {
                    b_continue = false;
                }
            } else {
                b_continue = false;
            }
        } else {
            b_continue = false;
        }
    }
    return i_line_len;
}
