// See LICENSE for license details
#include <peach_stdin.h>
extern "C" {
#include <cv_main.h>
#include <cv_algo/cv_array.h>
#include <cv_options/cv_options_it.h>
}
#include <stdio.h>
static void dump_word(cv_array const & r_buffer) {
    size_t const z_buffer_len =
        cv_array_len(&r_buffer);
    int const i_buffer_len =
        z_buffer_len & 0x7fff;
    char const * pc_char = r_buffer.o_min.pc_char;
    printf("[%.*s]\n",
        i_buffer_len,
        pc_char);
}
static void dump_options(cv_options const * p_options) {
    cv_options_it o_word_it;
    cv_options_it_init(&o_word_it, p_options);
    cv_array o_array;
    cv_array_init(&o_array);
    while (cv_options_it_next(&o_word_it, &o_array)) {
        dump_word(o_array);
    }
    cv_array_cleanup(&o_array);
    cv_options_it_cleanup(&o_word_it);
}
static void read_stdin() {
    bool b_more_input = true;
    while (b_more_input) {
        static char g_line[256u];
        cv_array o_buffer;
        cv_array_init_vector(&o_buffer, g_line, sizeof(g_line));
        size_t const z_line_len = peach_stdin::s_read_line(o_buffer);
        if (z_line_len) {
            int const i_line_len = z_line_len & 0x7fff;
            char const * pc_char = o_buffer.o_min.pc_char;
            printf("[%.*s]\n",
                i_line_len,
                pc_char);
            // store line into linked list of lines
            // sort of lines...
        } else {
            b_more_input = false;
        }
        cv_array_cleanup(&o_buffer);
    }
}
int main(int argc, char** argv) {
    cv_options * p_options = cv_main_init(argc, argv);
    if (p_options) {
        dump_options(p_options);
        read_stdin();
        cv_main_cleanup(p_options);
    }
    return 0;
}
