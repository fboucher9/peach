// See LICENSE for license details
#include <peach_options.h>
#include <peach_stdin.h>
extern "C" {
#include <cv_main.h>
}
#include <stdio.h>
static void dump_word(peach_word const * p_word) {
    peach_buffer const & r_buffer =
        p_word->m_data;
    size_t const z_buffer_len =
        r_buffer.f_len();
    int const i_buffer_len =
        z_buffer_len & 0x7fff;
    char const * pc_char = r_buffer.m_min_ptr.mc_char_ptr;
    printf("[%.*s]\n",
        i_buffer_len,
        pc_char);
}
static void dump_options(peach_options const * p_options) {
    peach_word_it o_word_it(p_options->m_words);
    peach_word_ptr o_word_ptr;
    while (o_word_it.f_next(&o_word_ptr)) {
        dump_word(o_word_ptr.pc_word);
    }
}
static void read_stdin() {
    bool b_more_input = true;
    while (b_more_input) {
        static char g_line[256u];
        peach_buffer o_buffer;
        if (o_buffer.f_init_vector(g_line, sizeof(g_line))) {
            size_t const z_line_len = peach_stdin::s_read_line(o_buffer);
            if (z_line_len) {
                int const i_line_len = z_line_len & 0x7fff;
                char const * pc_char = o_buffer.m_min_ptr.mc_char_ptr;
                printf("[%.*s]\n",
                    i_line_len,
                    pc_char);
                // store line into linked list of lines
                // sort of lines...
            } else {
                b_more_input = false;
            }
            o_buffer.f_cleanup();
        } else {
            b_more_input = false;
        }
    }
}
int main(int argc, char** argv) {
    cv_options * p_cave_options = cv_main_init(argc, argv);
    if (p_cave_options) {
        if (argc > 0) {
            unsigned int const i_arg_count = argc & 0x7fff;
            char const * const * p_arg_vector = argv;
            peach_options * p_options = new peach_options;
            if (p_options) {
                if (p_options->f_init(i_arg_count, p_arg_vector)) {
                    dump_options(p_options);
                    read_stdin();
                    p_options->f_cleanup();
                }
                delete p_options;
            }
        }
        cv_main_cleanup(p_cave_options);
    }
    return 0;
}
