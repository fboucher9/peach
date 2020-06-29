// See LICENSE for license details
#include <peach_stdin.h>
extern "C" {
#include <cv_file/cv_file.h>
#include <cv_file/cv_file_std.h>
}
size_t peach_stdin::s_read(peach_buffer const & r_buffer) {
    size_t i_result = 0;
    cv_array o_array;
    cv_array_init_range(&o_array, r_buffer.m_min_ptr.mc_void_ptr,
        r_buffer.m_max_ptr.mc_void_ptr);
    cv_sptr const i_read_result = cv_file_read(cv_file_std_in(), &o_array);
    if (i_read_result > 0) {
        i_result = i_read_result & 0x7fffffffL;
    }
    cv_array_cleanup(&o_array);
    return i_result;
}
bool peach_stdin::s_read_char(unsigned char * r_uchar) {
    static unsigned char g_cache[32u] = {0};
    static size_t g_cache_offset = 0;
    static size_t g_cache_len = 0;
    bool b_result = false;
    if (!g_cache_len) {
        peach_buffer o_buffer;
        if (o_buffer.f_init_vector(g_cache, sizeof(g_cache))) {
            g_cache_offset = 0;
            g_cache_len = peach_stdin::s_read(o_buffer);
            o_buffer.f_cleanup();
        }
    }
    if (g_cache_len) {
        *r_uchar = g_cache[g_cache_offset];
        g_cache_offset ++;
        g_cache_len --;
        b_result = true;
    }
    return b_result;
}
size_t peach_stdin::s_read_line(peach_buffer const & r_buffer) {
    size_t i_line_len = 0;
    bool b_continue = true;
    while (b_continue) {
        unsigned char c_data;
        if (s_read_char(&c_data)) {
            if ((r_buffer.m_min_ptr.m_uchar_ptr + i_line_len) <
                r_buffer.m_max_ptr.m_uchar_ptr) {
                r_buffer.m_min_ptr.m_uchar_ptr[i_line_len] = c_data;
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
