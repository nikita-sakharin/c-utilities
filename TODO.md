common.h:<br/>
arrayCompare - сравнить в массиве два элемента, используя компаратор.<br/>
arrayCompareSwap - сравнить в массиве два элемента и поменять их местами в том случае, если элемент по первому индексу строго больше (используя компаратор), чем по второму.<br/>
arraySwap - поменять местами в массиве два элемента.<br/>
ptrDifference - вычислить разницу между двумя указателями как число элементов.<br/>
ptrOffset - вычислить указатель на элемент в массиве по индексу.


error_handling.h:<br/>
Макрос EXIT_IF можно использовать в следующей ситуации: было выделено несколько ресурсов, далее произошла ошибка, GOTO_IF перекинул в место, где выделенные ресурсы освобождаются. Когда вызываем функцию для освобождения ресурса, то возвращаемое значение проверяем уже с помощью EXIT_IF, а не с помощью GOTO_IF. В данном случае напрашивается аналогия с C++ std::terminate, которая вызывается, если при обработке исключения, было выброшено еще одно. Возможно, в рамках данной аналогии, имеет смысл использовать функцию \_Exit, или даже abort. Но вариант, просто exit видится более органичным, более интуитивным, так как в точности копирует 'return' в main. С другой стороны вариант с функцией abort ближе по семантике к std::terminate.

Для GOTO_IF добавить вариант (или изменить имеющийся макрос?) который записывает текущее значение errno в lvalue (или по указателю?) переданное в макрос, затем зануляет errno (или просто оставляет без изменений?). Переданное lvalue может содержать side-effect.

Есть ОЧЕНЬ плохой вариант DO_GOTO_IF с выполнением произвольного блока. Но данный вариант категорически ошибкоопасен и отвергается по понятным причинам.


math.h:<br/>
lerp<br/>
degrees, radians<br/>
DBL_E, DBL_LN2, DBL_PI, DBL_SQRT2<br/>
comb, factorial, perm<br/>
ulp, nextDown, nextUp, union { uint32_t u32; flt f; }<br/>
random


arithmetic.h:<br/>
abs, div, multiplyHigth (mulh), ipow, isqrt, floorDiv, floorMod, floorDivMod

dim, max, min, minmax<br/>
clamp, lclamp, llclamp, imaxclamp, fclampf, fclamp, fclampl

Неправильный вариант:<br/>
clampi(clamp), clampu, clampl, clampul, clampll, clampull, clampimax, clampumax, clampf, clampd, clampld


numeric.h:<br/>
gcd, lcm, midpoint, fmidpoint, isqrt(?)

Неправильный вариант:<br/>
imidpoint, fmidpoint
