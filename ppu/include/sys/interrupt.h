/*! \file sys/interrupt.h
 \brief Thread interrupt syscalls.
*/

#ifndef __SYS_INTERRUPT_H__
#define __SYS_INTERRUPT_H__

#include <ppu-lv2.h>
#include <lv2/interrupt.h>
#include <lv2/syscalls.h>


#define SYS_HW_THREAD_ANY               0xFFFFFFFEU
#define SYS_HW_THREAD_INVALID           0xFFFFFFFFU
#define SYS_INTERRUPT_TAG_ID_INVALID    0xFFFFFFFFU


#ifdef __cplusplus
extern "C" {
#endif


LV2_SYSCALL sysInterruptTagCreate(sys_interrupt_tag_t *intrTag,sys_irqoutlet_id_t irq,sys_hw_thread_t hwThread)
{
	lv2syscall3(SYSCALL_INTERRUPT_TAG_CREATE, (u64)intrTag, irq, hwThread);
	return_to_user_prog(s32);
}

LV2_SYSCALL sysInterruptTagDestroy(sys_interrupt_tag_t intrTag)
{
	lv2syscall1(SYSCALL_INTERRUPT_TAG_DESTROY, intrTag);
	return_to_user_prog(s32);
}

LV2_SYSCALL sysInterruptThreadEstablish(sys_interrupt_thread_handle_t *ih,sys_interrupt_tag_t intrTag,sys_ppu_thread_t intrThread,u64 arg)
{
	lv2syscall5(SYSCALL_INTERRUPT_THREAD_ESTABLISH, (u64)ih, intrTag, intrThread, arg, 0);
	return_to_user_prog(s32);
}

LV2_SYSCALL _sysInterruptThreadDisestablish(sys_interrupt_thread_handle_t ih,u64 * tlsMem)
{
	lv2syscall2(SYSCALL_INTERRUPT_THREAD_DISESTABLISH, ih, (u64)tlsMem);
	return_to_user_prog(s32);
}

LV2_INLINE void sysInterruptThreadEOI(void)
{
	lv2syscall0(SYSCALL_INTERRUPT_THREAD_EOI);
}


#ifdef __cplusplus
	}
#endif

#endif
