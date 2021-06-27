APID=explicitTemplateInstantiation

all:explicitTemplateInstantiation

.PHONY:clean

explicitTemplateInstantiation:stack1test.cpp stack1_inst.cpp 
	$(CXX) $(CXXFLAGS) stack1test.cpp stack1_inst.cpp  $(LDFLAGS) -o $@
	@echo "+ explicitTemplateInstantiation error OK with mystd"

clean:
	rm -rf ${APID}
