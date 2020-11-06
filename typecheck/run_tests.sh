#!/bin/sh

for testfile in tests/good*.bminor
do
	
	if ./bminor -typecheck $testfile > $testfile.output
	then
		echo "$testfile success (as expected)\n"
	else
		echo "$testfile failure (INCORRECT)\n"

	fi
done

for testfile in tests/bad*.bminor
do
	if ./bminor -typecheck $testfile > $testfile.output
	then
		echo "$testfile success (INCORRECT)\n"
	else
		echo "$testfile failure (as expected)\n"
	fi
done
