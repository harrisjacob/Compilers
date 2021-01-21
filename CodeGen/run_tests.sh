#!/bin/sh

for testfile in tests/resolve/good*.bminor
do
	
	if ./bminor -resolve $testfile > $testfile.output
	then
		echo "$testfile success (as expected)\n"
	else
		echo "$testfile failure (INCORRECT)\n"

	fi
done

for testfile in tests/resolve/bad*.bminor
do
	if ./bminor -resolve $testfile > $testfile.output
	then
		echo "$testfile success (INCORRECT)\n"
	else
		echo "$testfile failure (as expected)\n"
	fi
done
