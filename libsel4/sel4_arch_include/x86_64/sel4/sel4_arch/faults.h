/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

#ifndef __LIBSEL4_SEL4_ARCH_FAULTS_H
#define __LIBSEL4_SEL4_ARCH_FAULTS_H

#include <autoconf.h>
#include <sel4/faults.h>
#include <sel4/sel4_arch/constants.h>

LIBSEL4_INLINE_FUNC seL4_Fault_t
seL4_getArchFault(seL4_MessageInfo_t tag)
{
    switch (seL4_MessageInfo_get_label(tag)) {
    case seL4_Fault_UnknownSyscall:
        return seL4_Fault_UnknownSyscall_new(seL4_GetMR(seL4_UnknownSyscall_RAX),
                                             seL4_GetMR(seL4_UnknownSyscall_RBX),
                                             seL4_GetMR(seL4_UnknownSyscall_RCX),
                                             seL4_GetMR(seL4_UnknownSyscall_RDX),
                                             seL4_GetMR(seL4_UnknownSyscall_RSI),
                                             seL4_GetMR(seL4_UnknownSyscall_RDI),
                                             seL4_GetMR(seL4_UnknownSyscall_RBP),
                                             seL4_GetMR(seL4_UnknownSyscall_R8),
                                             seL4_GetMR(seL4_UnknownSyscall_R9),
                                             seL4_GetMR(seL4_UnknownSyscall_R10),
                                             seL4_GetMR(seL4_UnknownSyscall_R11),
                                             seL4_GetMR(seL4_UnknownSyscall_R12),
                                             seL4_GetMR(seL4_UnknownSyscall_R13),
                                             seL4_GetMR(seL4_UnknownSyscall_R14),
                                             seL4_GetMR(seL4_UnknownSyscall_R15),
                                             seL4_GetMR(seL4_UnknownSyscall_FaultIP),
                                             seL4_GetMR(seL4_UnknownSyscall_SP),
                                             seL4_GetMR(seL4_UnknownSyscall_FLAGS),
                                             seL4_GetMR(seL4_UnknownSyscall_Syscall));

    case seL4_Fault_UserException:
        return seL4_Fault_UserException_new(seL4_GetMR(seL4_UserException_FaultIP),
                                            seL4_GetMR(seL4_UserException_SP),
                                            seL4_GetMR(seL4_UserException_FLAGS),
                                            seL4_GetMR(seL4_UserException_Number),
                                            seL4_GetMR(seL4_UserException_Code));
    case seL4_Fault_VMFault:
        return seL4_Fault_VMFault_new(seL4_GetMR(seL4_VMFault_IP),
                                      seL4_GetMR(seL4_VMFault_Addr),
                                      seL4_GetMR(seL4_VMFault_PrefetchFault),
                                      seL4_GetMR(seL4_VMFault_FSR));
    case seL4_Fault_Timeout:
        return seL4_Fault_Timeout_new(seL4_GetMR(seL4_Timeout_Data),
                                      seL4_GetMR(seL4_Timeout_Consumed));

    default:
        return seL4_Fault_NullFault_new();
    }
}


#endif
