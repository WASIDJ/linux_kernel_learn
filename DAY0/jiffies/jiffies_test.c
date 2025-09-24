#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/jiffies.h>

static int __init jiffies_test_init(void)
{
    printk(KERN_INFO "Hello, jiffies=%lu\n", jiffies);
    return 0;
}

static void __exit jiffies_test_exit(void)
{
    printk(KERN_INFO "Goodbye, jiffies module unloaded.\n");
}

module_init(jiffies_test_init);
module_exit(jiffies_test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ryou");
MODULE_DESCRIPTION("Test jiffies module");

