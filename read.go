package main

import (
	"time"
	"fmt"
	"strconv"
	"os"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	args := os.Args[1:]

	start, err := strconv.Atoi(args[0])
	check(err)
	end, err := strconv.Atoi(args[1])
	check(err)

	var sleepSec int

	if len(args) > 2 {
		sleepSec, err = strconv.Atoi(args[2])
		check(err)
		fmt.Printf("set sleep sec to %d\n", sleepSec)
	} else {
		sleepSec = 10
		fmt.Printf("use default sleep sec: %d\n", sleepSec)
	}

	var bwtPath string

	if len(args) > 3 {
		bwtPath = args[3]
		fmt.Printf("reading file: %s\n", bwtPath)
	} else {
		bwtPath = "/mnt/data/alignment/hg38.fa.gz.bwt"
		fmt.Printf("reading default file: %s\n", bwtPath)
	}

	fmt.Printf("read from %d to %d of %s\n", start, end, bwtPath)
	b := make([]byte, end - start + 1)

	// open file
	f, err := os.Open(bwtPath)
	check(err)

	n, err := f.Read(b)
	check(err)

	fmt.Println("memory load done!")
	// fmt.Printf("[%d, %d] of bytes(%d):\n[%s]\n", 
	// 	start, end, n, b[start:end])
	f.Close()

	var timeSlept int
	for i := 0; i < sleepSec; i++ {
		time.Sleep(1 * time.Second)
		timeSlept ++
		fmt.Printf("time countdown: %d of %d\n", 
			timeSlept, sleepSec)
	}
	fmt.Printf("size of chunk: %d\n", n)

}
