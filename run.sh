export BIGFILE="./read.go"
echo 3 | sudo tee /proc/sys/vm/drop_caches
time go run read.go 1000000000 2000000000 10 
time ./a.out