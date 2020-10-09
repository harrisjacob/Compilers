#!/bin/sh

for testfile in good*.bminor
do
	if ../bminor -parse $testfile
	then
		echo "$testfile success (as expected)\n"
	else
		echo "$testfile failure (INCORRECT)\n"

	fi
done

for testfile in bad*.bminor
do
	if ../bminor -parse $testfile
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done
