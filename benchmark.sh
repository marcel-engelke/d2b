#!/bin/sh

if [ ! -e testdata ]; then
	echo "generating data"
	./gen.py > testdata;
fi

echo "running benchmarks"
echo "def"
time ./def < testdata > /dev/null
echo "fast"
time ./fast < testdata > /dev/null
