#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

#define PROC_NAME "simple_stats"

static int num_reads = 0;

static int proc_show(struct seq_file *m, void *v) {
    seq_printf(m, "Number of reads: %d\n", num_reads);
    return 0;
}

static int proc_open(struct inode *inode, struct file *file) {
    return single_open(file, proc_show, NULL);
}

static ssize_t proc_read(struct file *file, char __user *buf, size_t count, loff_t *ppos) {
    num_reads++;
    return seq_read(file, buf, count, ppos);
}

static const struct proc_ops proc_ops = {
    .proc_open = proc_open,
    .proc_read = proc_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};

static int __init simple_stats_init(void) {
    proc_create(PROC_NAME, 0, NULL, &proc_ops);
    printk(KERN_INFO "/proc/%s created\n", PROC_NAME);
    return 0;
}

static void __exit simple_stats_exit(void) {
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

module_init(simple_stats_init);
module_exit(simple_stats_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module to collect read statistics");