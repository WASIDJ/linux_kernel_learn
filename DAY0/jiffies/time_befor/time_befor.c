#include <linux/jiffies.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>

static int example = 1; // 默认运行 example1
module_param(example, int, 0644);
MODULE_PARM_DESC(example, "Choose which example to run: 1 or 2");

// example1
static void run_example1(void)
{
  unsigned long start, end;
  start = jiffies;
  msleep(499);
  end = jiffies;
  if (time_before(end, start + 2 * HZ))
  {
    printk(KERN_INFO "Example1: start=%lu, HZ=%d, end=%lu, start+2*HZ=%lu\n", start, HZ, end, start + 2 * HZ);
    printk(KERN_INFO "Example1: time_before works\n");
  }
  else
  {
    printk(KERN_INFO "Example1: time_before does not work\n");
  }
}

// example2
static void run_example2(void)
{
  unsigned long start, timeout;

  start = jiffies;          // 记录开始时间
  timeout = start + 5 * HZ; // 设置超时时间为 5 秒后
  printk(KERN_INFO "Example2: start=%lu, timeout=%lu\n", start, timeout);

  // 模拟延迟
  msleep(6000); // 睡眠 6 秒

  if (time_before(jiffies, timeout))
  {
    printk(KERN_INFO "Example2: Current time (%lu) is before timeout (%lu)\n", jiffies, timeout);
  }
  else
  {
    printk(KERN_INFO "Example2: Current time (%lu) is after or equal to timeout (%lu)\n", jiffies, timeout);
  }
}

static int __init time_befor_init(void)
{
  if (example == 1)
  {
    run_example1();
  }
  else if (example == 2)
  {
    run_example2();
  }
  else
  {
    printk(KERN_INFO "Invalid example number. Use 1 or 2.\n");
  }
  return 0;
}

static void __exit time_befor_exit(void)
{
  printk(KERN_INFO "Goodbye, time_before module unloaded.\n");
}

module_init(time_befor_init);
module_exit(time_befor_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ryou");
MODULE_DESCRIPTION("Test time_before module with selectable examples");
