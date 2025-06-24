# 指定编译器和编译选项
CXX      ?= clang++
CXXFLAGS ?= -std=c++23 -Wall -Wextra -g

# 自动查找所有 .cpp 源文件
SRCS    := $(wildcard *.cpp)
# 目标可执行文件列表（去掉 .cpp 后缀）
TARGETS := $(SRCS:.cpp=)

# 默认目标：编译所有可执行文件
all: $(TARGETS)

# 模式规则：每个可执行文件由对应的 .cpp 源文件生成
# $@ 是目标名称，$< 是第一依赖（即 .cpp 文件）
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 清理中间文件/可执行
.PHONY: clean
clean:
	rm -f $(TARGETS)