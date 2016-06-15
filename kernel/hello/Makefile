ifeq ($(KERNELRELEASE),)

KERNELDIR ?= /usr/src/linux-headers-3.19.0-61-generic/
PWD :=$(shell pwd)

modules:
	 $(MAKE) -C $(KERNELDIR) M=$(PWD) modules
modules_install:
	 $(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
clear:
	 rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions
.PHONY: modules modules_install clean
else
	 obj-m:= hello.o
endif
