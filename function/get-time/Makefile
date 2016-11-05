PDF=time-date.pdf

all:
	doxygen  && \
	cd latex && \
	make pdf && \
	cd .. && \
	mv latex/refman.pdf time-date.pdf

upload: all
	git commit -m "new version" time-date.pdf
	git push
