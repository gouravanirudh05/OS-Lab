* If any command requires permissions-use sudo with that

```
lsb_release -a - to check the os version
```

* kernel.org website to check the kernel version

```
* kernel is present in the boot directory

ls -l/boot/vm*

* to see its size in human readable form 

ls -lh/boot/vm*
```
To see what file type a file is:-
file filename


tree - to see the hierarchy of the file system
tree -l 

bin directory contains the binary executable

To check the number of cores lscpu | more

cat /proc/meminfo - to see the memory information

free - how much memory is free 
free -k,-m,-g to see in kB ,MB,GB,

pid-max is a file in proc/sys/kernel tells the max number of processes allowed

ls /proc/ -it lists the processes as numbers

./a.out & to run in bakground

top -p pid-to put the process id
top - to see about all the processes

jobs  - to see the active processes running 


Any executable has - text portion,data portion ,data stack portion
To see its size - 
size filename

to see harddisk partition-
sudo fdisk 
The ones with * are the ones that are bootable partitions-(Only 4 partitions are allowed by default)

df -h - it will give the filesystem and all the partitions 

grep *alphabet- to list all the files with that alphabet in its name at the beginning-default 10 files will be put

mount command - to see the currently mounted files

touch abc(1..100).mp3 creates 100 dummy files

-rf-recursively forcefully

ll is an alias for ls -alF (a here is to list the hidden files)

whereis command name gives the complete path of that command


To create alias for any command use - alias aliasname actual name
This will be till we close the terminal -to make it permanent put in the bashrc
do vi .bashrc and put it there

In the permissions -rw-rw-r-- 
What is the first - before rw -This indicates the type of the file
d means the directory
. is present directory 
rw-read write
-l -symbolic link file -hardlink,softlink,

To see default permissions
How to set the permission?chmod to change the permissions after file is created


mask command  
See the permission numbers for group,rootuser,user

id command to list the user id 's 

How to change the owner of a file:-
sudo chown root filename 

touch command is to create files 

See man page for each command for more details 


ll is an alias for ls -alf

character devices are the device that we  access sequentially character by character 
Example: keyboard,monitor

Block devices are the device that we access block by block 
example:harddisk

To see all the character devices
ls -l /dev | grep ^c | head
```
$ ls -l /dev | grep ^c | head
```
* Output:
crw-r--r-- 1 root root     10, 235 Feb 14 11:27 autofs
crw-rw---- 1 root disk     10, 234 Feb 14 11:27 btrfs-control
crw--w---- 1 root tty       5,   1 Feb 14 11:27 console
crw------- 1 root root     10, 125 Feb 14 11:27 cpu_dma_latency
crw------- 1 root root     10, 203 Feb 14 11:27 cuse
crw-rw-rw- 1 root root     10, 127 Feb 14 11:27 dxg
crw-rw-rw- 1 root root      1,   7 Feb 14 11:27 full
crw-rw-rw- 1 root root     10, 229 Feb 14 11:27 fuse
crw------- 1 root root    229,   0 Feb 14 11:27 hvc0
crw--w---- 1 root tty     229,   1 Feb 14 11:27 hvc1

THE TWO numbers are called major and minor numbers.
Major number is used to identify the device type
Minor number is the instance of the device 

```
ll ../>file1
```

```
ls -lh 
```



To list the block devices, use the following:
```
$ ls -l /dev/sda * | grep ^b | head
```

Major number is used to identify the device (lets say for hardisk the major number will be the same but the minor number will be different as it is the partition number)
Minor number is used to identify the partition of the device(hard disk)

```
ping url
```

# Linked files :- Shortcuts created are linked files.It won't  copy everything to one file.It just points to it using a pointer 

## Types:-
1. Soft link 
2. Hard links 

To see all the hard links

```

ls -hl

```
To create a hard link file 
```
touch file1 
ln file1(just a name) hrdlink(just a name)
ln is the command to create the hard link file
```
```
$ ls  -hl
```

total 0
drwxrwxrwx 1 gourav gourav 512 Jan 20 21:53 Lab0
drwxrwxrwx 1 gourav gourav 512 Feb 14 11:49 Lab1
-rwxrwxrwx 1 gourav gourav  37 Jan 10 11:33 README.md

The number next to permission here is the number of links


## Inode number 

An inode number (Index Node) is a unique identifier assigned to each file and directory in a Unix/Linux filesystem. It stores metadata about the file but not the filename or data.

```
ls -ihl(inode number human readable format long list)
```

Hardink helps us to create a link to some file and for some reason it allows us to access that file even if the file is deleted (check out later).

How to link a file from one partion to another partion in the file system?

We need to create a pointer .
This is called a softlink

```
ls -ihl
```
Difference between hardlink and softlink

* In hardlink even if the main file is deleted we can access it using the hardlink.Identified using the inode number
* In softlink if the main file is deleted then we can't access it using the softlink. Identified using the -l .


### FIFO:- Interprocess communication using this.
* Pseudo device file called a pipe.(We open it in two terminals and here we see that the pipe )

```
mkfifo myfifo
```

* To examin the proc directory
we can just use 

```
$ lscpu
```



