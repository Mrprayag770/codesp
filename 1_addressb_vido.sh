#!/bin/sh
# Assignment no 1 in the SL-II syllabus

create()
{
echo "Enter address book name"
read ab
#check address book is available or not in current working dir
res=`ls | grep $ab | wc -w`
if [ $res -gt 0 ]
then
echo "Error: file is already existing! "
else
touch $ab
fi

}


while [ true ]
do
echo "****** *** MENU ***
echo "1. Create"
I echo "7. Exit"
echo "Enter Choice"
read choice
case $choice in
1) create ;;
7) exit ;;
*) echo "Wrong Choice! " ;;
esac
done