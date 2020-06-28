// See LICENSE for license details
#ifndef peach_options_h_
#define peach_options_h_
#include <peach_object.h>
#include <peach_buffer.h>
#include <peach_list.h>
#include <peach_word.h>
struct peach_options : public peach_object {
    peach_options() = default;
    ~peach_options() = default;
    bool f_init();
    bool f_init(size_t argc, char const * const * argv);
    void f_cleanup();
    bool f_append(
        peach_buffer const & r_word);
    bool f_write(
        peach_buffer const & r_data);
    char c_object_pad[8u];
    peach_list m_words;
};
#endif // #ifndef peach_options_h_
