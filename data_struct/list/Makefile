export STAGING_DIR=/home/nichola/workspace/openwrt/wrtnode/staging_dir
CROSS_DIR=$(STAGING_DIR)/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin
CC=$(CROSS_DIR)/mipsel-openwrt-linux-uclibc-gcc
list_test:list.o
	$(CC) -o list_test list.o
list.o:list.c
	$(CC) -c list.c

clean:
	rm list_test list.o
