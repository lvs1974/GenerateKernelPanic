#ifndef _KERNEL_PANIC_H
#define _KERNEL_PANIC_H

#include <IOKit/IOService.h>
#include <IOKit/pci/IOPCIDevice.h>
#include <IOKit/IOTimerEventSource.h>
#include <IOKit/acpi/IOACPIPlatformDevice.h>

class KernelPanic : public IOService
{
    OSDeclareDefaultStructors(KernelPanic)
    
private:

public:
    virtual bool		init(OSDictionary *dictionary = 0);
    virtual void		free(void);
    virtual IOService	*probe(IOService *provider, SInt32 *score);
    virtual bool		start(IOService *provider);
    virtual void		stop(IOService *provider);
    virtual IOReturn	setPowerState( unsigned long whichState, IOService * whatDevice );
};



#endif
