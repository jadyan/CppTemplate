APID=myfirstinst

all:myfirstinst

.PHONY:clean

myfirstinst: myfirst.hpp myfirst.cpp myfirstinst.cpp myfirstmain.cpp
	$(CXX) $(CXXFLAGS) myfirst.cpp myfirstinst.cpp myfirstmain.cpp $(LDFLAGS) -o $@
	@echo "+ myfirstinst error OK with mystd"

clean:
	rm -rf ${APID}
