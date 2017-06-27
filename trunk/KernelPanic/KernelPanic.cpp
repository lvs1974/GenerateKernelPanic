#include <IOKit/IODeviceTreeSupport.h>
#include <IOKit/IORegistryEntry.h>
#include <IOKit/pwr_mgt/RootDomain.h>
#include <IOKit/IOLib.h>

#include "KernelPanic.hpp"

#define Debug FALSE

#define LogPrefix "KernelPanic: "
#define DebugLog(string, args...)	do { if (Debug) { IOLog (LogPrefix "[Debug] " string "\n", ## args); } } while(0)
#define WarningLog(string, args...) do { IOLog (LogPrefix "[Warning] " string "\n", ## args); } while(0)
#define InfoLog(string, args...)	do { IOLog (LogPrefix string "\n", ## args); } while(0)

#define super IOService
OSDefineMetaClassAndStructors (KernelPanic, IOService)


bool KernelPanic::init(OSDictionary *dictionary)
{
    if (!super::init(dictionary))
        return false;
    
    return true;
}

IOService *KernelPanic::probe(IOService *provider, SInt32 *score)
{
    if (!super::probe(provider, score))
        return 0;
    
    InfoLog("KernelPanic-probe by lvs1974 (C) 2016");
    return this;
}

bool KernelPanic::start(IOService *provider)
{
    if (!super::start(provider)) return false;
    
    InfoLog("KernelPanic-start by lvs1974 (C) 2016");
    
    // initialize superclass variables from IOService.h
    PMinit();
    static const IOPMPowerState powerStates[] = {
        {kIOPMPowerStateVersion1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {kIOPMPowerStateVersion1, kIOPMDeviceUsable, IOPMPowerOn, IOPMPowerOn, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    registerPowerDriver(this, const_cast<IOPMPowerState*>(powerStates),
                        sizeof(powerStates) / sizeof(powerStates[0]));
    // join the tree from IOService.h
    provider->joinPMtree(this);
    
    registerService();
    
    IOSleep(2000);
    
    static int volatile test = 0;
    int volatile test1 = 200/test;
    
    return true;
}


IOReturn KernelPanic::setPowerState( unsigned long state, IOService * provider )
{
    return kIOPMAckImplied;
}

void KernelPanic::stop(IOService *provider)
{
    PMstop();
    super::stop(provider);
}

void KernelPanic::free()
{
    super::free();
}
