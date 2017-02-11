#!/bin/zsh

mkdir test0 test2
echo -n 1234 > test1
echo -n 1 > test3
echo -n 12 > test4
ln test3 test5
chmod 714 test1
chmod 504 test2
chmod 404 test3 test5
chmod 641 test4
touch -t 06012146 test1
touch -t 06012245 test2
touch -t 06012344 test3
touch -t 06012343 test4
touch -t 06012344 test5
touch -t 06012220 test0
ln -sn test0 test6
touch -h -t 06012220 test6
touch -t 06012047 test0
tar -cf exo.tar test* 
