APID=myfirstinst

CXXFLAGS:=-g

all:myfirstinst

.PHONY:clean

myfirstinst: myfirst.hpp myfirst.cpp myfirstmain.cpp
	$(CXX) $(CXXFLAGS) myfirst.cpp  myfirstmain.cpp $(LDFLAGS) -o $@
	@echo "+ myfirstinst error OK with mystd"

clean:
	rm -rf ${APID}
