#Program Number: 1c
#Name:Gourav Anirudh B J,Register Number: IMT2023005
#Date: 15/02/2025
#Description: Creating fifo file using shell commands
#!/bin/bash
echo "Creating FIFO file"
mkfifo fifofile
echo "Writing to FIFO file"
echo "This is question 1c" > fifofile &
echo "Reading from FIFO file"
cat fifofile
echo "Data Read from FIFO file"
