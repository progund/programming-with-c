# Build it all - no archive, no shared object file

```
$ gcc main.c misc-stuff/sum.c misc-stuff/mean.c -o main
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
```

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
$ gcc main.c -Lmisc-stuff -lmisc -o main
$ ./main 
mean: 2.66666666666666651864
sum: 8
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
Note that the functions mean and sum are marked with "T", meaning they are the text section of the program - i e in the program.


## Build a shared object file

```
$ cd lib
$ gcc -c sum.c mean.c
$ gcc --shared sum.o mean.o -o libmisc.so
$ file libmisc.so 
libmisc.so: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, BuildID[sha1]=3553e3bb3d8d2119de9ef3974146491dcf204d18, not stripped
```

## List the symbols in the shard object file
```
$ nm libmisc.so 
0000000000201018 B __bss_start
0000000000201018 b completed.6984
                 w __cxa_finalize@@GLIBC_2.2.5
0000000000000500 t deregister_tm_clones
0000000000000590 t __do_global_dtors_aux
0000000000200e40 t __do_global_dtors_aux_fini_array_entry
0000000000200e48 d __dso_handle
0000000000200e50 d _DYNAMIC
0000000000201018 D _edata
0000000000201020 B _end
00000000000006cc T _fini
00000000000005d0 t frame_dummy
0000000000200e38 t __frame_dummy_init_array_entry
00000000000007a0 r __FRAME_END__
0000000000201000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000000006d8 r __GNU_EH_FRAME_HDR
00000000000004c8 T _init
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
000000000000064e T mean
0000000000000540 t register_tm_clones
00000000000005da T sum
0000000000201018 d __TMC_END__
```

## Link the program (against the shared object file)

```
$ rm -f misc-stuff/libmisc.a
$ gcc main.c -Lmisc-stuff -lmisc -o main
$ ./main 
./main: error while loading shared libraries: libmisc.so: cannot open shared object file: No such file or directory
$ LD_LIBRARY_PATH=lib ./main 
mean: 2.66666666666666651864
sum: 8
```


## List the symbols in main

```
$ nm main
000000000060103c B __bss_start
000000000060103c b completed.6984
0000000000601038 D __data_start
0000000000601038 W data_start
00000000004005d0 t deregister_tm_clones
0000000000400640 t __do_global_dtors_aux
0000000000600e08 t __do_global_dtors_aux_fini_array_entry
00000000004007a8 R __dso_handle
0000000000600e10 d _DYNAMIC
000000000060103c D _edata
0000000000601040 B _end
0000000000400794 T _fini
0000000000400670 t frame_dummy
0000000000600e00 t __frame_dummy_init_array_entry
000000000040091c r __FRAME_END__
0000000000601000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000004007fc r __GNU_EH_FRAME_HDR
0000000000400538 T _init
0000000000600e08 t __init_array_end
0000000000600e00 t __init_array_start
00000000004007a0 R _IO_stdin_used
0000000000400790 T __libc_csu_fini
0000000000400720 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000400677 T main
                 U mean
                 U printf@@GLIBC_2.2.5
                 U puts@@GLIBC_2.2.5
0000000000400600 t register_tm_clones
00000000004005a0 T _start
                 U sum
0000000000601040 D __TMC_END__
```

Note that the functions mean and sum are marked with "U" as undefined, i e not in the program.
