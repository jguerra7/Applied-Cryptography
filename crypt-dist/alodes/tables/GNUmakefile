# LMAINTOPS=	all
RPAR=)
LPAR=(
SOURCES=	$(wildcard *.make)
HS=	$(addprefix ../lib/,$(addsuffix .h,$(basename $(SOURCES))))
PRINTFILES:=	mk-ip $(SOURCES)

all::	$(HS)

include Makerules

clean::
	echo "These files can be removed: $(HS)"
	echo $(HS) > REMOVABLE

../lib/%.h:	%.make
	./$^ > $@
