# random_stat_linux_kernel
This is a linux kernel in C that will provide random stat.

Explanation
- proc_create: This function creates an entry in the /proc filesystem.
- proc_open: Called when the proc file is opened.
- proc_read: Called when the proc file is read. Here, it increments the read counter and then delegates to seq_read for actual data transfer.
- proc_show: Formats the output to be displayed when the proc file is read.
- module_init and module_exit: These macros define the initialization and cleanup functions of the module.

How to install it:
Step 1:
Run the following command.
```sh
make
```

Step 2:
Run the following command.
```sh
sudo insmod stat.ko
```

Step 3:
You can check the kernel logs to see if your module loaded correctly.
```sh
dmesg | tail
```

How to use it:
Read from the Proc File:
```sh
cat /proc/<name_of_the_Proc>
```

Each time you read from the Proc file, the number of reads displayed will increase.

How to remove the kernel:
Please run the following command to remove the kernel.
```sh
sudo rmmod <the_name_you_used>
make clean
```
