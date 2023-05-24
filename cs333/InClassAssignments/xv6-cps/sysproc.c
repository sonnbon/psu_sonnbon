#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

#ifdef HALT
int
sys_halt(void)
{
    outw(0x604, 0x2000);
    // https://wiki.osdev.org/Shutdown
    return 0;
}
#endif // HALT

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

#ifdef GETPPID
int
sys_getppid(void)
{
    int ppid = 1;

    if (myproc()->parent) {
        ppid = myproc()->parent->pid;
    }
    return ppid;
}
#endif // GETPPID

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

#ifdef CPS
int
sys_cps(void)
{
    return proc_cps();
}
#endif // CPS

#ifdef KDEBUG
int
sys_kdebug(void)
{
    int n = 0;

    cprintf("%d %s\n", __LINE__, __FILE__);
    if (argint(0, &n) < 0) {
        return -1;
    }
    return proc_kdebug(n);
}
#endif // KDEBUG
#ifdef VA2PA
int
sys_va2pa(void)
{
    int va = 0x0;
    char *pa = 0x0;
    struct proc *p = myproc();

    if (argint(0, &va) < 0) {
        return 0x0;
    }
    pa = uva2ka(p->pgdir, (char *) va);
    pa = pa + (((uint) va) & 0xFFF);
    return ((int) pa);
}
#endif // VA2PA
