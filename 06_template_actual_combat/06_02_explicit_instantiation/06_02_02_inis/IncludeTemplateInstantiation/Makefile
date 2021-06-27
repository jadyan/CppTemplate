APID=IncludeTemplateInstantiation

all:IncludeTemplateInstantiation

.PHONY:clean

IncludeTemplateInstantiation:stack1test.cpp 
	$(CXX) $(CXXFLAGS) stack1test.cpp  $(LDFLAGS) -o $@
	@echo "+ myfirstinst error OK with mystd"

clean:
	rm -rf ${APID}
