flush
echo 3 | sudo tee /proc/sys/vm/drop_caches
time dd if=/path/to/bigfile of=/dev/null bs=8k