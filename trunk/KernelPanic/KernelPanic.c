//
//  KernelPanic.c
//  KernelPanic
//
//  Copyright © 2017 lvs1974. All rights reserved.
//

#include <mach/mach_types.h>
#include <IOKit/IOLib.h>

kern_return_t KernelPanic_start(kmod_info_t * ki, void *d);
kern_return_t KernelPanic_stop(kmod_info_t *ki, void *d);

kern_return_t KernelPanic_start(kmod_info_t * ki, void *d)
{
    IOSleep(1000);
    static int volatile test = 0;
    int volatile test1 = 200/test;
    return test1;
}

kern_return_t KernelPanic_stop(kmod_info_t *ki, void *d)
{
    return KERN_SUCCESS;
}
