# 编译
```shell script
mkdir build && cd build
cmake ..
make
```

# perf剖析
```shell script
# docker内perf需要带--privileged运行docker
sysctl -w kernel.kptr_restrict=0
sysctl -w kernel.perf_event_paranoid=-1

# -e 指定监控指标 可以通过perf list查看完整列表

# 方法一 使用lbr，比较快但是需要硬件支持
perf record -a -e cpu-clock --call-graph lbr ./profiling ../moby.txt
# 方法二(推荐) 使用dwarf
perf record -a -e cpu-clock --call-graph dwarf ./profiling ../moby.txt
# 使用三 使用frame pointer, 需要带-fno-omit-frame-pointer选项重编
perf record -a -e cpu-clock -g ./profiling ../moby.txt

# 查看剖析结果
perf report 或者 perf report --stdio

火焰图
https://github.com/brendangregg/FlameGraph

perf script > perf.unfold
./stackcollapse-perf.pl perf.unfold > perf.folded
./flamegraph.pl perf.folded > perf.svg
```