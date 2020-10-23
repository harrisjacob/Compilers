#!/bin/sh

for testfile in $3/good*.bminor
do
	if $1 $2 $testfile
	then
		echo "$testfile success (as expected)\n"
	else
		echo "$testfile failure (INCORRECT)\n"

	fi
done

for testfile in $3/bad*.bminor
do
	if $1 $2 $testfile
	then
		echo "$testfile success (INCORRECT)\n"
	else
		echo "$testfile failure (as expected)\n"
	fi
done
