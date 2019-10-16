echo 3 | sudo tee /proc/sys/vm/drop_caches
time dd if=/mnt/data/alignment/hg38.fa.gz.bwt of=/dev/null bs=8k