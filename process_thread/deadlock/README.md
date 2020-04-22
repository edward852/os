# gdb
## attaching
```shell script
pidof deadlock | xargs -n1 gdb --batch -ex "thread apply all bt" -p
# 如果线程太多，可以通过top或htop线程模式找到指定线程pid后再用gdb查看

# docker内定位
docker exec -it -u root --privileged 容器Id或名称 bash
```

## coredump
```shell script
# 确保coredump启用
ulimit -c unlimited

kill -s segv `pidof deadlock`
# coredump文件一般在程序同级目录，没有的话可以查看 /proc/sys/kernel/core_pattern
gdb ./deadlock core

# gdb command
thread apply all bt
```