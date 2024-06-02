# random_stat_linux_kernel
This is a linux kernel in C that will provide random stat.

Explanation
- proc_create: This function creates an entry in the /proc filesystem.
- proc_open: Called when the proc file is opened.
- proc_read: Called when the proc file is read. Here, it increments the read counter and then delegates to seq_read for actual data transfer.
- proc_show: Formats the output to be displayed when the proc file is read.
- module_init and module_exit: These macros define the initialization and cleanup functions of the module.
