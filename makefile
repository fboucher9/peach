
peach_dst ?= _obj/test

peach_src ?= .

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
-Weverything \
-Wno-c++98-compat \
-fno-exceptions \
-fno-rtti

$(peach_dst)/test.exe : $(peach_objs) $(peach_src)/makefile | $(peach_dst)
	clang -o $@ $(peach_flags) $(peach_objs)

$(peach_dst)/%.cpp.o : $(peach_src)/%.cpp $(peach_src)/makefile | $(peach_dst)
	clang -c -o $@ $(peach_flags) $<

$(peach_dst) :
	-mkdir -p $(peach_dst)
