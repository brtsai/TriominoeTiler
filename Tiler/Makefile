src := $(wildcard *.cpp)
obj := $(src:%.cpp=%.o)
hdr := $(wildcard *.h)
bin := tiler

CXX := $(shell which clang++ || which g++)
CXXFLAGS := -Wall -W -std=c++14
LDFLAGS := 

UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
  LDFLAGS := $(LDFLAGS) -lpthread
endif

all: $(bin)

$(bin): $(obj) $(hdr)
	$(CXX) -o $(bin) $(obj) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(<) -o $(@)

.PHONY: clean
clean:
	rm -f $(bin) $(obj)
