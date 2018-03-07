# Build it all - no archive, no shared object file

```
$ gcc main.c lib/sum.c lib/mean.c -o main
$ ./main
```
## List the symbols in main

```
$ nm main
000000000060102c B __bss_start
000000000060102c b completed.6984
0000000000601028 D __data_start
0000000000601028 W data_start
0000000000400480 t deregister_tm_clones
00000000004004f0 t __do_global_dtors_aux
0000000000600e18 t __do_global_dtors_aux_fini_array_entry
0000000000400748 R __dso_handle
0000000000600e20 d _DYNAMIC
000000000060102c D _edata
0000000000601030 B _end
0000000000400734 T _fini
0000000000400520 t frame_dummy
0000000000600e10 t __frame_dummy_init_array_entry
000000000040090c r __FRAME_END__
0000000000601000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
000000000040079c r __GNU_EH_FRAME_HDR
0000000000400400 T _init
0000000000600e18 t __init_array_end
0000000000600e10 t __init_array_start
0000000000400740 R _IO_stdin_used
0000000000400730 T __libc_csu_fini
00000000004006c0 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000400527 T main
0000000000400639 T mean
                 U printf@@GLIBC_2.2.5
                 U puts@@GLIBC_2.2.5
00000000004004b0 t register_tm_clones
0000000000400450 T _start
00000000004005c5 T sum
0000000000601030 D __TMC_END__
```
# Using archive

## Build an archive

```
$ cd lib
$ gcc -c sum.c mean.c
$ ar rcv libmisc.a sum.o mean.o
a - sum.o
a - mean.o
$ file libmisc.a 
libmisc.a: current ar archive

## List the symbols in the archive
```
$ nm libmisc.a 

sum.o:
0000000000000000 T sum

mean.o:
0000000000000000 T mean
```

## Link the program (against the archive)

```
$ gcc main.c -L. -lmisc -o main
$ ./main 
mean: 2.66666666666666651864
sum: 8
```


```


## List the symbols in main

```
$ nm main
000000000060102c B __bss_start
000000000060102c b completed.6984
0000000000601028 D __data_start
0000000000601028 W data_start
0000000000400480 t deregister_tm_clones
00000000004004f0 t __do_global_dtors_aux
0000000000600e18 t __do_global_dtors_aux_fini_array_entry
0000000000400748 R __dso_handle
0000000000600e20 d _DYNAMIC
000000000060102c D _edata
0000000000601030 B _end
0000000000400734 T _fini
0000000000400520 t frame_dummy
0000000000600e10 t __frame_dummy_init_array_entry
000000000040090c r __FRAME_END__
0000000000601000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
000000000040079c r __GNU_EH_FRAME_HDR
0000000000400400 T _init
0000000000600e18 t __init_array_end
0000000000600e10 t __init_array_start
0000000000400740 R _IO_stdin_used
0000000000400730 T __libc_csu_fini
00000000004006c0 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000400527 T main
0000000000400639 T mean
                 U printf@@GLIBC_2.2.5
                 U puts@@GLIBC_2.2.5
00000000004004b0 t register_tm_clones
0000000000400450 T _start
00000000004005c5 T sum
0000000000601030 D __TMC_END__
```
# 