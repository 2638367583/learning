ifeq ($(KERNELRELEASE),)
KERNELDIR ?= /usr/src/linux-source-4.15.0/linux-source-4.15.0
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions Module* modules* a.out

else
    obj-m := hello.o
endif