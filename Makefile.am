SUBDIRS = src

EXTRA_DIST = conf/log4cxx.xml

log_dir=$(DESTDIR)$(prefix)/log
conf_dir=$(DESTDIR)$(prefix)/conf

install-data-hook:
	$(mkinstalldirs) $(log_dir)
	$(mkinstalldirs) $(conf_dir)
	install -D --mode=644 $(top_srcdir)/conf/log4cxx.xml $(conf_dir)/
    
uninstall-hook:
	rm -rf $(log_dir)
