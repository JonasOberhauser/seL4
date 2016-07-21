--
-- Copyright 2014, NICTA
--
-- This software may be distributed and modified according to the terms of
-- the BSD 2-Clause license. Note that NO WARRANTY is provided.
-- See "LICENSE_BSD2.txt" for details.
--
-- @TAG(NICTA_BSD)
--

-- this file contains types shared between libsel4 and the kernel

tagged_union seL4_Fault seL4_FaultType {
    -- generic faults
    tag NullFault 0
    tag CapFault 1
    tag UnknownSyscall 2
    tag UserException 3
    tag Temporal 4
    tag NoFaultHandler 5

    -- arch specific faults
    tag VMFault 6

#ifdef CONFIG_ARM_HYPERVISOR_SUPPORT
    tag VGICMaintenance 7
    -- 4 bits are required seL4_FaultType from here on
    tag VCPUFault 8
#endif
}
