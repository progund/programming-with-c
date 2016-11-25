
C_FILES=parser/parser.c searcher/searcher.c
MAIN=main.c
PROG=sgrep


all: $(PROG)

include rules.mk


clean:
	if [ -d searcher ]; then cd searcher && make clean; fi
	if [ -d parser ]; then cd parser && make clean; fi
	@-rm -f $(OBJS) *~ $(PROG)

run: $(PROG)
	./$(PROG) apa

debug: CFLAGS += $(DEBUG_FLAGS) -Dll
debug: $(PROG)

debug-run: debug
	./$(PROG) apa


bb: $(PROG)
	echo "Carl-Einar" | ./$(PROG) carl ; if [ $$? -ne 1 ] ; then exit 1 ; fi
	echo "Carl-Einar" | ./$(PROG) Carl ; if [ $$? -ne 0 ] ; then exit 1 ; fi
	export CNT=$$(printf "Apa\nbepa\nApa\nbepa\n" | ./$(PROG) Apa | wc -l) ; if [ $$CNT -ne 2 ] ; then exit 1 ; fi
	export CNT=$$(printf "Apa\nbepa\nApa\nbepaApa\nbepa\nApa\nBepa\n" | ./$(PROG) Bepa | wc -l) ; if [ $$CNT -ne 1 ] ; then exit 1 ; fi
	cat Makefile | ./$(PROG) OBJS  >/dev/null;  if [ $$? -ne 0 ] ; then exit 1 ; fi
	cat sgrep_data.h | ./$(PROG) OBJSSLS >/dev/null; if [ $$? -ne 1 ] ; then exit 1 ; fi
	echo "" | ./$(PROG) "" >/dev/null; if [ $$? -ne 0 ] ; then exit 1 ; fi
	echo -n "" | ./$(PROG) "" >/dev/null; if [ $$? -ne 1 ] ; then exit 1 ; fi
	seq 1 100002 | awk ' { printf "%s " , $$0 }' | ./$(PROG) 777 >/dev/null;  if [ $$? -ne 0 ] ; then exit 1 ; fi
	seq 1 100002 | awk ' { printf "%s " , $$0 }' | ./$(PROG) 777ss; if [ $$? -ne 1 ] ; then exit 1 ; fi
	seq 1 1000000 | awk ' { printf "%s " , $$0 }' | ./$(PROG) 777s; if [ $$? -ne 1 ] ; then exit 1 ; fi
#	seq 1 12345678 | awk ' { printf "%s " , $$0 }' | ./$(PROG) 777s; if [ $$? -ne 1 ] ; then exit 1 ; fi
	cat /bin/ls | ./$(PROG) 777s; if [ $$? -ne 1 ] ; then exit 1 ; fi
	@echo ""
	@echo "All tests passed."

check:
	@echo "Not performing test since code is not written yet"
	@echo " - implement the code and enable the tests again"
#	cd searcher && make check
#	cd parser && make check

valgrind: debug
	cat Makefile | valgrind --leak-check=full ./$(PROG) OBJS


doc: Doxyfile
	rm -fr latex
	doxygen 
	cd latex && make

