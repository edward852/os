# 编译
```shell script
mkdir build && cd build
cmake ..
make
```

# perf剖析
```shell script
sysctl -w kernel.kptr_restrict=0

# 方法一 使用lbr，比较快但是需要硬件支持
perf record -a --call-graph lbr ./profiling ../moby.txt
# 方法二(推荐) 使用dwarf
perf record -a --call-graph dwarf ./profiling ../moby.txt
# 使用三 使用frame pointer, 需要带-fno-omit-frame-pointer选项重编
perf record -a -g ./profiling ../moby.txt

# 查看剖析结果
perf report
```