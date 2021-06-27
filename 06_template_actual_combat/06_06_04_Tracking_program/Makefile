APID=tracertest

all:tracertest

.PHONY:clean

tracertest : tracer.hpp tracer.cpp tracertest.cpp  
	$(CXX) $(CXXFLAGS) tracer.hpp tracer.cpp tracertest.cpp  $(LDFLAGS) -o $@
	@echo "+ tracertest error OK with mystd"

clean:
	rm -rf ${APID}
