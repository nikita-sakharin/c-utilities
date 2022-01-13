common.h:<br/>
arrayCompare - сравнить в массиве два элемента, используя компаратор.<br/>
arrayCompareSwap - сравнить в массиве два элемента и поменять их местами в том случае, если элемент по первому индексу строго больше (используя компаратор), чем по второму.<br/>
arraySwap - поменять местами в массиве два элемента.<br/>
ptrDifference - вычислить разницу между двумя указателями как число элементов.<br/>
ptrOffset - вычислить указатель на элемент в массиве по индексу.

Финализировать memSwap. При реализации следует использовать не char, а uchar по аналогии с определением в стандарте функций memchr, memcmp, memset.<br/>
http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2484.htm<br/>
https://www.lysator.liu.se/c/restrict.html<br/>
https://cellperformance.beyond3d.com/articles/2006/06/understanding-strict-aliasing.html<br/>
https://gustedt.wordpress.com/2010/08/17/a-common-misconsception-the-register-keyword

error_handling.h:<br/>
Макрос EXIT_IF можно использовать в следующей ситуации: было выделено несколько ресурсов, далее произошла ошибка, GOTO_IF перекинул в место, где выделенные ресурсы освобождаются. Когда вызываем функцию для освобождения ресурса, то возвращаемое значение проверяем уже с помощью EXIT_IF, а не с помощью GOTO_IF. В данном случае напрашивается аналогия с C++ std::terminate, которая вызывается, если при обработке исключения, было выброшено еще одно. Возможно, в рамках данной аналогии, имеет смысл вместо фунеции exit, использовать \_Exit, или даже abort. Но вариант, просто exit видится более органичным, более интуитивным, так как в точности копирует 'return' в main (вызывает atexit и закрывает файловые дискрипторы). С другой стороны вариант с функцией abort ближе по семантике к std::terminate. Вариант при котором будет отдельно макрос с abort и отдельно с exit кажется откровенно спорным.

Так же имеет смысл рассмотреть макрос для вывода сообщений об ошибках в формате POSIX. Например:
dir: cannot access '42': No such file or directory<br/>
первый аргумент это argv[0], затем сообщение произвольного вида, затем perror.

Итого, получается нужно три макроса под три ситуации:<br/>
1) Размотка стека;<br/>
2) По форме POSIX;<br/>
3) Если при обработке ошибки произошла еще одна.<br/>

Для GOTO_IF добавить вариант (или изменить имеющийся макрос?) который записывает текущее значение errno в lvalue (или по указателю?) переданное в макрос, затем зануляет errno (или просто оставляет без изменений?). Переданное lvalue может содержать side-effect.

Есть ОЧЕНЬ плохой вариант DO_GOTO_IF с выполнением произвольного блока. Но данный вариант категорически ошибкоопасен и отвергается по понятным причинам.

arithmetic.h:<br/>
multiplyHigth (mulh), ipow, isqrt, floorDiv, floorMod, floorDivMod<br/>
minmax<br/>
fclampf, fclamp, fclampl

Неправильный вариант:<br/>
clampi(clamp), clampu, clampl, clampul, clampll, clampull, clampimax, clampumax, clampf, clampd, clampld

http://www.open-std.org/jtc1/sc22/wg11/docs/n462.pdf<br/>
http://www.open-std.org/jtc1/sc22/wg11/docs/n497.pdf<br/>
http://www.open-std.org/jtc1/sc22/wg11/docs/n519.pdf

bit.h:<br/>
{bitCount|popCount}
hasSingleBit -> {isPowOf2|isPowOfTwo}
rotateLeft, rotateRight

math.h:<br/>
lerp<br/>
degrees, radians<br/>
DBL_E, DBL_LN2, DBL_PI, DBL_SQRT2<br/>
comb, factorial, perm<br/>
ulp, nextDown, nextUp, union { uint32_t u32; flt f; }<br/>
random

numeric.h:<br/>
gcd, lcm, midpoint, fmidpoint, isqrt(?)

Неправильный вариант:<br/>
imidpoint, fmidpoint
