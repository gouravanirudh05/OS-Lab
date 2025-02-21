#Program Number: 1a
#Student Name:Gourav Anirudh B J,Register Number: IMT2023005
#Date: 15/02/2025
#Description: Creating softlink file using shell commands
#!/bin/bash
echo "Creating a temporary file"
touch file1a.txt
echo "New File created" > file1a.txt
echo "Creating a softlink for file.txt"
ln -s file1a.txt softlink1a.txt
