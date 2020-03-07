TOP=..

include $(TOP)/configure/CONFIG

install:
	$(ECASYN)/etc/scripts/expandChain.py chain.xml > scanner.xml
	
clean:
	-rm scanner.xml scanner-ni.xml

uninstall:


