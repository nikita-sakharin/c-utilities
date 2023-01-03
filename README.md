`arithmetic.h`:<br/>
`multiplyHigh` (`mulHi`), `ipow`, `isqrt`, `ceilDivMod`, `euclidDivMod`, `floorDivMod`<br/>
`minmax`

http://www.open-std.org/jtc1/sc22/wg11/docs/n462.pdf<br/>
http://www.open-std.org/jtc1/sc22/wg11/docs/n497.pdf<br/>
http://www.open-std.org/jtc1/sc22/wg11/docs/n519.pdf

`bit.h`:<br/>
{`bitCount`|`popCount`}<br/>
`rotateLeft`, `rotateRight`

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
[Baseline for Ed 2 of TR 24772](www.open-std.org/jtc1/sc22/wg23/docs/ISO-IECJTC1-SC22-WG23_N0453-baseline-wd-pdtr-24772-2013-06.pdf)<br/>
[Errors](www.gnu.org/prep/standards/html_node/Errors.html)<br/>
[Error Messages](www.gnu.org/software/libc/manual/html_node/Error-Messages.html)

`math.h`:<br/>
`fclampf`, `fclamp`, `fclampl`, `lerp`<br/>
`toDegrees`, `toRadians`<br/>
`DBL_1_PI`, `DBL_2_PI`, `DBL_2_SQRTPI`, `DBL_E`, `DBL_LN10`, `DBL_LN2`, `DBL_LOG10E`, `DBL_LOG2E`, `DBL_PHI`, `DBL_PI`, `DBL_PI_2`, `DBL_PI_4`, `DBL_SQRT1_2`, `DBL_SQRT2`<br/>
`comb`, `factorial`, `perm`<br/>
`ulp`, `nextDown`, `nextUp`, `union { uint32_t u32; flt f; }`<br/>
`random`

`numeric.h`:<br/>
`gcd`, `lcm`, `midpoint`, `fmidpoint`, `isqrt`

Неправильный вариант:<br/>
`imidpoint`, `fmidpoint`

`string.h`:<br/>
`strFormat`, `strNFormat`, `strReverse`, `strNReverse`
