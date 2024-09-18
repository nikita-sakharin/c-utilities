`arithmetic.h`:<br/>
`multiplyHigh` (`mulHi`)<br/>
`isMultipleOf`, `nextMultipleOf`, `prevMultipleOf`<br/>
[`icopysign`](https://gcc.gnu.org/onlinedocs/gfortran/SIGN.html)<br/>
`isignbit` (docs.gl, nvidia.com, khronos.org, numpy.org, opencl.org, vulkan.org)<br/>
`ceilDivMod`, `euclidDivMod`, `floorDivMod`

- [ISO/IEC Part 1: Integer and floating point arithmetic](http://www.open-std.org/jtc1/sc22/wg11/docs/n519.pdf)
- [ISO/IEC Part 2: Elementary numerical functions](http://www.open-std.org/jtc1/sc22/wg11/docs/n462.pdf)
- [ISO/IEC Part 3: Complex integer and floating point arithmetic and complex elementary numerical functions](http://www.open-std.org/jtc1/sc22/wg11/docs/n497.pdf)

`bit.h`:<br/>
{`bitCount`|`popCount`}<br/>
`rotateLeft`, `rotateRight`<br/>
`clear` (~~`reset`~~), `set`, `flip`<br/>
 `getBit` (`testBit`):<br/>
 - `testAll` (`isAll`, ~~`getAll`~~)
 - `testAny` (`isAny`, ~~`getAny`~~)
 - `testNone` (`isNone`, ~~`getNone`~~)

`(are|have|has|is)SameSign[um]`

`ctype.h`:<br/>
`isAscii`, `toAscii`

`debug.h` (`check.h`):<br/>
`checkArray` (`checkPointer`), `checkIndexSize`, `checkLengthSize`

`error_handling.h`:<br/>
Макрос `EXIT_IF` можно использовать в следующей ситуации: было выделено несколько ресурсов, далее произошла ошибка, `GOTO_IF` перекинул в место, где выделенные ресурсы освобождаются. Когда вызываем функцию для освобождения ресурса, то возвращаемое значение проверяем уже с помощью `EXIT_IF`, а не с помощью `GOTO_IF`. В данном случае напрашивается аналогия с C++ `std::terminate`, которая вызывается, если при обработке исключения, было выброшено еще одно. Возможно, в рамках данной аналогии, имеет смысл вместо функции `exit`, использовать `_Exit`, или даже `abort`. Но вариант, просто `exit` видится более органичным, более интуитивным, так как в точности копирует `return` в `main` (вызывает `atexit` и закрывает файловые дискрипторы). С другой стороны вариант с функцией `abort` ближе по семантике к `std::terminate`. Вариант при котором будет отдельно макрос с `abort` и отдельно с `exit` кажется откровенно спорным.

Так же имеет смысл рассмотреть макрос для вывода сообщений об ошибках в формате POSIX. Например:<br/>
`dir: cannot access '42': No such file or directory`,<br/>
где первый аргумент это `argv[0]`, затем сообщение произвольного вида, затем `perror`.

Итого, получается нужно три макроса под три ситуации:<br/>
1) Размотка стека;<br/>
2) По форме POSIX;<br/>
3) Если при обработке ошибки произошла еще одна.

Для `GOTO_IF` добавить вариант (или изменить имеющийся макрос?) который записывает текущее значение `errno` в lvalue (или по указателю?) переданное в макрос, затем зануляет errno (или просто оставляет без изменений?). Переданное lvalue может содержать side-effect. Есть ОЧЕНЬ плохой вариант `DO_GOTO_IF` с выполнением произвольного блока. Но данный вариант категорически ошибкоопасен и отвергается по понятным причинам.

[ERR04-C. Choose an appropriate termination strategy](https://wiki.sei.cmu.edu/confluence/display/c/ERR04-C.+Choose+an+appropriate+termination+strategy)<br/>
[Baseline for Ed 2 of TR 24772](https://www.open-std.org/jtc1/sc22/wg23/docs/ISO-IECJTC1-SC22-WG23_N0453-baseline-wd-pdtr-24772-2013-06.pdf)<br/>
[Errors](https://www.gnu.org/prep/standards/html_node/Errors.html)<br/>
[Error Messages](https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html)

`math.h`:<br/>
`fclampf`, `fclamp`, `fclampl`, `lerp`, `saturate`<br/>
`toDegrees`, `toRadians`<br/>
`DBL_1_PI`, `DBL_2_PI`, `DBL_2_SQRTPI`, `DBL_E`, `DBL_LN10`, `DBL_LN2`, `DBL_LOG10E`, `DBL_LOG2E`, `DBL_PHI`, `DBL_PI`, `DBL_PI_2`, `DBL_PI_4`, `DBL_SQRT1_2`, `DBL_SQRT2`<br/>
`comb` (`binomialCoefficient`), `perm` (`factorial`)<br/>
`ulp`, `nextDown`, `nextUp`, `union { uint32_t u32; flt f; }`<br/>
`random`

`numeric.h`:<br/>
`gcd`, `lcm`, `midpoint`, `fmidpoint`, `isqrt`, `icbrt`

`preprocessor.h`:<br/>
[Integer Properties](https://www.gnu.org/software/gnulib/manual/html_node/Integer-Properties.html)
- `check_*` (`checked_*`), `is_*_overflow`, ~~`is_*_undefined`~~
- `wrapping_*`, ~~`overflowing_*`~~
- `saturating_*`

`string.h`:<br/>
`strFormat`, `strNFormat`, `strReverse`, `strNReverse`

`type_generic.h`:<br/>
`TYPE_GENERIC_POINTER`

`utility.h`:<br/>
Три уровня интерфейса:
- Два указателя (`mem*`)
- Элемент массива и указатель (`elemGet`, `elemSet`, `elem*`/`elem*Mem`) ???
- Два элемента массива (`arr*`/`arrElem*`/`array*`/`elem*Elem`)
- Все элементы массива (`arrMax`/`arrElemMax`/`arrayMax`) ???

`elemCompareEqual`, `elemCompareGreater`, `elemCompareGreaterEqual`, `elemCompareLess`, `elemCompareLessEqual`, `elemCompareNotEqual`<br/>
`memCompareEqual`, `memCompareGreater`, `memCompareGreaterEqual`, `memCompareLess`, `memCompareLessEqual`, `memCompareNotEqual`<br/>
`memReverse`<br/>
`memRotate` (`memExchange`, `memShift`)<br/>
`ptrRemoveConst` (`ptrConstCast`), `ptrRemoveConstVolatile` (`ptrConstVolatileCast`), `ptrRemoveVolatile` (`ptrVolatileCast`)

# Тестирование:<br/>
- Два `goal` синонима друг другу: `check` и `test`.
- Следуя практикам `xUnit` выделяются файлы являющиеся `suit`-ами и функции внутри этих файлов, являющиеся `case`-ами, которые тестируют функции из `./src` и `./include`.
- Как должен называться файл содержащий тесты для функций находящихся в `./src/arithmetic.c` и `./include/arithmetic.h`? Существует два варианта:
  - `./test/arithmetic.test.c`
  - `./test/arithmetic.c`
- Как должен называться исполняемый файл, скомпилированный из файлов предыдущего пункта? Опять же два варианта:
  - `./test/arithmetic.test.out`
  - `./test/arithmetic.out`
- Каждый файл из папки `./test` (т.е. `suit`) содержит функцию `main` в которой запускаети все тестовые функции (`case`).
- Могут ли в папке `./test` существовать кроме самих `suit`-ов еще и другие файлы? Если да, то потребуется продумать где лежат не только `.c`-файлы, но и местоположение `.h`-файлов. А это значит, что кроме папки `./include` потребуется еще аналогичная папка для заголовочников, которые используются только в тестах. **ОЧЕНЬ ПЛОХАЯ ИДЕЯ.**
