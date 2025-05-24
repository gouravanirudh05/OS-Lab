#!/bin/bash

#    Program Number: 36c
#   Student Name: Gourav Anirudh; Register Number: IMT2023005 
#    Date: 12-05-2025
#  Description:Use strace command to determine which command (mknod or mkfifo) is more 
# efficient. 
# Trace mknod command
echo "Tracing mknod command"
strace -c mknod my_fifo_3 p

# Trace mkfifo command
echo "Tracing mkfifo command"
strace -c mkfifo my_fifo_4
