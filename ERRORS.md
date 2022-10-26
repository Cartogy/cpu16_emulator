In file included from /usr/include/c++/11.2.0/memory:66,
                 from /usr/include/gtest/gtest.h:57,
                 from /home/jonas/Dev/Programming/cpp/emu/cpu16/tests/emulation_test.cc:1:
/usr/include/c++/11.2.0/bits/stl_uninitialized.h: In instantiation of ‘_ForwardIterator std::uninitialized_copy(_InputIterator, _InputIterator, _ForwardIterator) [with _InputIterator = __gnu_cxx::__normal_iterator<const std::unique_ptr<InsCategory>*, std::vector<std::unique_ptr<InsCategory> > >; _ForwardIterator = std::unique_ptr<InsCategory>*]’:
/usr/include/c++/11.2.0/bits/stl_uninitialized.h:333:37:   required from ‘_ForwardIterator std::__uninitialized_copy_a(_InputIterator, _InputIterator, _ForwardIterator, std::allocator<_Tp>&) [with _InputIterator = __gnu_cxx::__normal_iterator<const std::unique_ptr<InsCategory>*, std::vector<std::unique_ptr<InsCategory> > >; _ForwardIterator = std::unique_ptr<InsCategory>*; _Tp = std::unique_ptr<InsCategory>]’
/usr/include/c++/11.2.0/bits/stl_vector.h:558:31:   required from ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::unique_ptr<InsCategory>; _Alloc = std::allocator<std::unique_ptr<InsCategory> >]’
/home/jonas/Dev/Programming/cpp/emu/cpu16/src/Compiler/../Parser/POperTable/popertable.hpp:7:7:   required from here
/usr/include/c++/11.2.0/bits/stl_uninitialized.h:138:72: error: static assertion failed: result type must be constructible from value type of input range
  138 |       static_assert(is_constructible<_ValueType2, decltype(*__first)>::value,
      |                                                                        ^~~~~
/usr/include/c++/11.2.0/bits/stl_uninitialized.h:138:72: note: ‘std::integral_constant<bool, false>::value’ evaluates to false
make[2]: *** [tests/CMakeFiles/emulation_test.dir/build.make:76: tests/CMakeFiles/emulation_test.dir/emulation_test.cc.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:911: tests/CMakeFiles/emulation_test.dir/all] Error 2
make: *** [Makefile:146: all] Error 2

