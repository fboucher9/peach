
peach_dst ?= _obj/test

peach_src ?= .

cave_src ?= $(peach_src)/../cave

peach_srcs := \
peach_test.cpp \
peach_options.cpp \
peach_buffer.cpp \
peach_object.cpp \
peach_word.cpp \
peach_list.cpp \
peach_stdin.cpp

peach_objs := $(addprefix $(peach_dst)/,$(peach_srcs:=.o))

peach_flags := \
-std=c++11 \
-g \
-O0 \
-I $(peach_src) \
-I $(cave_src) \
-Weverything \
-Wno-c++98-compat \
-Wno-c++98-compat-pedantic \
-fno-exceptions \
-fno-rtti

cave_srcs := \
cv_main.c \
cv_algo/cv_array.c \
cv_algo/cv_array_it.c \
cv_algo/cv_array_tool.c \
cv_algo/cv_array_print.c \
cv_algo/cv_buffer.c \
cv_misc/cv_convert.c \
cv_algo/cv_string0.c \
cv_algo/cv_chunk_root.c \
cv_algo/cv_chunk_node.c \
cv_algo/cv_chunk_it.c \
cv_algo/cv_crc32.c \
cv_manager.c \
cv_options/cv_options_desc.c \
cv_options/cv_options.c \
cv_options/cv_options_it.c \
cv_options/cv_options_node.c \
cv_options/cv_options_pool.c \
cv_options/cv_options_decoder.c \
cv_heap/cv_heap.c \
cv_heap/cv_heap_primary.c \
cv_heap/cv_heap_secondary.c \
cv_heap/cv_heap_node.c \
cv_heap/cv_heap_node_ptr.c \
cv_heap/cv_heap_pool.c \
cv_heap/cv_heap_it.c \
cv_heap/cv_heap_section.c \
cv_heap/cv_heap_section_lock.c \
cv_heap/cv_heap_small.c \
cv_heap/cv_heap_large.c \
cv_heap/cv_heap_used.c \
cv_debug/cv_debug.c \
cv_debug/cv_debug_code.c \
cv_debug/cv_debug_class.c \
cv_misc/cv_sizeof.c \
cv_thread/cv_thread_desc.c \
cv_thread/cv_thread.c \
cv_thread/cv_thread_impl.c \
cv_memory.c \
cv_number/cv_number_desc.c \
cv_number/cv_number_format.c \
cv_number/cv_number_enc.c \
cv_number/cv_number_dec.c \
cv_number/cv_number_scan.c \
cv_number/cv_number_print.c \
cv_clock/cv_clock.c \
cv_clock/cv_clock_it.c \
cv_clock/cv_clock_mono.c \
cv_clock/cv_clock_mono_it.c \
cv_clock/cv_clock_counter.c \
cv_clock/cv_clock_duration.c \
cv_clock/cv_clock_tool.c \
cv_clock/cv_clock_tick.c \
cv_random/cv_random.c \
cv_random/cv_random_crypto.c \
cv_algo/cv_list_node.c \
cv_algo/cv_list_it.c \
cv_algo/cv_list_root.c \
cv_algo/cv_stack.c \
cv_algo/cv_stack_it.c \
cv_thread/cv_mutex.c \
cv_thread/cv_mutex_impl.c \
cv_thread/cv_once.c \
cv_thread/cv_specific.c \
cv_algo/cv_pool.c \
cv_algo/cv_pool_desc.c \
cv_algo/cv_pool_lock.c \
cv_file/cv_file.c \
cv_file/cv_file_std.c \
cv_file/cv_file_disk_desc.c \
cv_file/cv_file_disk.c \
cv_file/cv_file_poll.c \
cv_file/cv_file_print.c \
cv_trace/cv_trace_node.c \
cv_trace/cv_trace_msg.c \
cv_trace/cv_trace_plugin.c \
cv_trace/cv_trace_level.c \
cv_screen/cv_screen_device_desc.c \
cv_screen/cv_screen_device.c \
cv_screen/cv_screen_linux.c \
cv_runtime.c \
cv_linux.c \
cv_windows.c \

cave_flags := \
-g \
-O0 \
-I $(cave_src) \
-D cv_debug_ \
-D cv_linux_ \
-D cv_have_libc_ \
-D cv_have_pthread_ \
-Weverything \
-Wno-missing-braces \
-Wno-missing-field-initializers \

cave_objs := $(addprefix $(peach_dst)/,$(cave_srcs:=.o))

$(peach_dst)/test.exe : $(peach_objs) $(cave_objs) $(peach_src)/makefile | $(peach_dst)
	@echo linking $@
	@clang -o $@ $(peach_flags) $(peach_objs) $(cave_objs) -lpthread

$(peach_dst)/%.cpp.o : $(peach_src)/%.cpp $(peach_src)/makefile | $(peach_dst)
	@echo compiling $<
	@clang -c -o $@ $(peach_flags) $<

$(peach_dst)/%.c.o : $(cave_src)/%.c $(peach_src)/makefile
	@echo compiling $<
	-@mkdir -p $(dir $@)
	@clang -c -o $@ $(cave_flags) $<

$(peach_dst) :
	-mkdir -p $(peach_dst)
