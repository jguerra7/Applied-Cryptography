PROGS:=		des-certify des des-ktest test-crypt test-crypt2 des-probe random-key
ELIBS:=		-ldes -lhut
include Makerules

CFLAGS:=	$(CFLAGS) -I../lib

foobar: des-certify
	echo x $(CFLAGS)
