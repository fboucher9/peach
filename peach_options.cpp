// See LICENSE for license details
#include <peach_options.h>
bool peach_options::f_init() {
    // empty previous content...
    return true;
}
bool peach_options::f_init(size_t argc, char const * const * argv) {
    bool b_result = true;
    size_t i_argv_iterator = 1;
    while (b_result && (i_argv_iterator < argc)) {
        char const * const p_argv_node = argv[i_argv_iterator ++];
        peach_buffer o_argv_buffer;
        if (o_argv_buffer.f_init_sz(p_argv_node)) {
            if (f_append(o_argv_buffer)) {
            } else {
                b_result = false;
            }
            o_argv_buffer.f_cleanup();
        } else {
            b_result = false;
        }
    }
    return b_result;
}
void peach_options::f_cleanup() {
}
bool peach_options::f_append(
    peach_buffer const & r_word) {
    bool b_result = false;
    peach_word * p_word = new peach_word;
    if (p_word) {
        if (p_word->f_init(r_word)) {
            peach_list::s_join(p_word, &m_words);
            b_result = true;
        } else {
            delete p_word;
            b_result = false;
        }
    } else {
        b_result = false;
    }
    return b_result;
}
