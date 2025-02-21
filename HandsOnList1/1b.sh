#Program Number: 1b
#Student Name:Gourav Anirudh B J,Register Number: IMT2023005
#Date: 15/02/2025
#Description: Creating hardlink file using shell commands 

#!/bin/bash
echo "Creating a temporary file"
touch file1b.txt
echo "New File created" > file1b.txt
echo "Creating a hardlink for file1b.txt"
ln  file1b.txt hardlink1b.txt