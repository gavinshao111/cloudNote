编译动态库 libgmqtt.so, libgmqtt.so 调用了 libbytebuffer.a. error:
relocation R_X86_64_32S against `vtable for bytebuf::ByteBuffer' can not be used when making a shared object; recompile with -fPIC
../ByteBuffer/libbytebuffer.a: could not read symbols: Bad value

重编 libbytebuffer.a 并加上编译选项 -fPIC